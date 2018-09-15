# progress-bar

> Use C to output a simple progress bar to the terminal.

# install

> Just Copy & Paste.

# Usage

For example:

```C
#include <windows.h>

#include "progress_bar/progress_bar.h"

int main(int argc, char* argv[]) {
  ProgressBar* progressbar = create_progressbar(128, -1, -1);

  for (int i = 3; i > 0; --i) {
    for (int j = i * 65; j > 0; --j ) {
      output_progressbar(progressbar, -1);
      Sleep(100);
    }
    restart_progressbar(finish_output(progressbar), -1, -1, -1);
  }

  finish_output(progressbar);
  destroy_progressbar(progressbar);

  return 0;
}
```

Results:

```
[+][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]100.00%
[+][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]100.00%
[-][>>>>>>>>>>>>>>>>>>>>>>>>>-------------------------]50.00%
```

