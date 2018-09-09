# progress-bar

> Use Java to output a simple progress bar to the terminal.

# install

> Just Copy & Paste.

# Usage

For example:

```java
import progressbar.ProgressBar;

public class Run {
  public static void main(String[] args) throws Exception {
    ProgressBar bar = new ProgressBar(350, 4);

    for (int i = 3; i > 0; --i) {
      for (int j = 0; j < 100; j++) {
        Thread.sleep(100);
        bar.output();
      }
      bar.finish().restart(350, i);
    }
  }
}
```

Results:

```
[+][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]100.00%
[-][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>--------]85.43%
[-][>>>>>>>>>>>>>>>>>>>>>>>>>>>>----------------------]56.86%
```

