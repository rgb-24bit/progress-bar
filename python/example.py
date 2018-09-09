# -*- coding: utf-8 -*-

import time

from progress_bar import ProgressBar


def example():
    bar = ProgressBar(208)
    for i in range(2, 5):
        for j in range(100):
            time.sleep(0.1)
            bar.output()
        bar.finish().restart(inscrease=i)


if __name__ == '__main__':
    example()
