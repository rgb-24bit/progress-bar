/**
 * Copyright (c) 2018 by rgb-24bit.
 * License MIT, see LICENSE for more details.
 * ProgressBar use to output a simple progress bar to the terminal.
 */

#include <stdio.h>
#include <stdlib.h>

#include "progress_bar.h"

/* Create and initialize the ProgressBar structure. */
ProgressBar* create_progressbar(int total, int increase, int width) {
  ProgressBar* progressbar = (ProgressBar*)malloc(sizeof(ProgressBar));

  if (progressbar == NULL) {
    return NULL;
  }

  progressbar->total = total;
  progressbar->current = -1;
  progressbar->increase = increase == -1 ? 1 : increase;
  progressbar->width = width == -1 ? 50 : width;

  /* The longest output string: \r[+][width]100.00%\0 */
  progressbar->buf = (char*)malloc((progressbar->width + 20) * sizeof(char));

  if (progressbar->buf == NULL) {
    free(progressbar);
    return NULL;
  }

  return progressbar;
}

/* Destroy the ProgressBar structure. */
void destroy_progressbar(ProgressBar* progressbar) {
  if (progressbar != NULL) {
    if (progressbar->buf != NULL) {
      free(progressbar->buf);
    }
    free(progressbar);
  }
}

/* Build the string to be output. */
void __build_output_string(ProgressBar* progressbar) {
  float percent = progressbar->current * 100.0f / progressbar->total;

  char tail[9] = "]%.2f%%\0";

  if (percent >= 100) {
    sprintf(progressbar->buf, "\r[+][");

    for (int i = 0; i < progressbar->width; ++i) {
      progressbar->buf[5 + i] = '>';
    }

    percent = 100.0f;

  } else {
    sprintf(progressbar->buf, "\r[-][");

    int current_width = progressbar->width * percent / 100;
    for (int i = 0; i < current_width; ++i) {
      progressbar->buf[5 + i] = '>';
    }

    for (int i = current_width; i < progressbar->width; ++i) {
      progressbar->buf[5 + i] = '-';
    }
  }

  sprintf(progressbar->buf + 5 + progressbar->width, tail, percent);
}

/* Output progress bar to terminal. */
void output_progressbar(ProgressBar* progressbar, int current) {
  if (current == -1) {
    progressbar->current += progressbar->increase;
  } else {
    progressbar->current = current;
  }

  __build_output_string(progressbar);

  fputs(progressbar->buf, stdout);
}

/* finish output, output a line break to standard output */
ProgressBar* finish_output(ProgressBar* progressbar) {
  fputc('\n', stdout);
  return progressbar;
}

/* Reinitialize the progress bar properties */
ProgressBar* restart_progressbar(ProgressBar* progressbar,
                         int total, int increase, int width) {
  progressbar->current = -1;
  progressbar->total = total == -1 ? progressbar->total : total;
  progressbar->increase = increase == -1 ? progressbar->increase : increase;

  if (width != -1) {
    progressbar->buf = (char*)realloc(progressbar->buf,
                                      width + 20 * sizeof(char));

    if (progressbar->buf == NULL) {
      free(progressbar);
      return NULL;
    }

    progressbar->width = width;
  }

  return progressbar;
}
