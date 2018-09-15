/**
 * Copyright (c) 2018 by rgb-24bit.
 * License MIT, see LICENSE for more details.
 * ProgressBar use to output a simple progress bar to the terminal.
 */

#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#ifdef __cplusplus
// extern "C" {
#endif

/**
 * Structure for recording the basic information of the progress bar.
 *
 * The creation and destruction of the structure should be done with
 * the functions create_progressbar and destroy_progressbar.
 */
typedef struct {
  int total;
  int increase;
  int width;
  int current;
  char* buf;
} ProgressBar;

/**
 * Create and initialize the ProgressBar structure.
 *
 * The parameter total is required. If the value of other parameters is -1,
 * the default value is used.
 *
 * increase default value is 1.
 * width default value is 50.
 */
ProgressBar* create_progressbar(int total, int increase, int width);

/**
 * Destroy the ProgressBar structure.
 */
void destroy_progressbar(ProgressBar* progressbar);

/**
 * Build the string to be output.
 */
void __build_output_string(ProgressBar* progressbar);

/**
 * Output progress bar to terminal.
 *
 * If the value of the parameter current is -1, then the default
 * self-promotion is used.
 */
void output_progressbar(ProgressBar* progressbar, int current);

/**
 * Finish output, output a line break to standard output.
 *
 * Return the progressbar itself.
 */
ProgressBar* finish_output(ProgressBar* progressbar);

/**
 * Reinitialize the progress bar properties.
 *
 * If the parameter value is -1, then the previous value is used.
 *
 * Specifying a new width may cause the reallocation space to fail,
 * returning NULL.
 *
 * Return the progressbar itself.
 */
ProgressBar* restart_progressbar(ProgressBar* progressbar,
                         int total, int increase, int width);


#ifdef __cplusplus
// }
#endif

#endif  /* PROGRESS_H */

