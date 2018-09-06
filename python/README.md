# progress-bar

> Use Python to output a simple progress bar to the terminal.

# install

```
$ git clone https://github.com/rgb-24bit/progress-bar.git
$ cd progress-bar/python
$ python setup.py install
```

# Usage

For example:

```python
# -*- coding: utf-8 -*-

import time

from progress_bar import ProgressBar


def example():
    bar = ProgressBar(208)
    for i in range(2, 5):
        for j in range(100):
            bar.output()
            time.sleep(0.1)
        bar.finish()
        bar.restart(inscrease=i)


if __name__ == '__main__':
    example()
```

Results:

```
[-][>>>>>>>>>>>>>>>>>>>>>>>---------------------------]47.60%
[-][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>---]95.67%
[+][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]100.00%
```
