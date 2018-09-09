# -*- coding: utf-8 -*-

import sys


class ProgressBar(object):
    """Output a simple progress bar to the terminal.

    Args:
        total: The total size of progress
        increase: Every time the default self-increase, the default is 1
        width: The width of the character output from the progress bar,
            the default is 50

    Expected display effect:
        [+][>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]100.00%
        [-][>>>>>>>>>>>>>>>>>>>>>>>>>----------------]60.00%
    """
    def __init__(self, total, increase=1, width=50):
        self.total = total
        self.increase = increase
        self.width = width
        self.current = -1

    def output(self, current=None):
        """Output progress bar to terminal.

        Args:
            current: The current progress, if it is None, use the progress
            of self-increment.

        Note:
            When the first output is output, the default is 0.
        """
        if current is not None:
            self.current = current
        else:
            self.current += self.increase

        current_width = self.current * self.width // self.total
        remain_width = self.width - current_width
        current_percent = self.current * 100.0 / self.total

        out_format = '[{current}{remain}]{percent:.2f}%'
        if current_percent >= 100:
            current_width = self.width
            remain_width = 0
            current_percent = 100.00
            out_format = '\r[+]' + out_format
        else:
            out_format = '\r[-]' + out_format

        out = out_format.format(
            current = '>' * current_width,
            remain = '-' * remain_width,
            percent = current_percent
        )

        sys.stdout.write(out)
        sys.stdout.flush()

    def restart(self, total=None, inscrease=None, width=None):
        """Reinitialize the progress bar properties.

        Args:
            total: The total size of progress. If it is None,
                it will not be modified
            increase: Every time the default self-increase.
                If it is None, it will not be modified
            width: The width of the character output from the progress bar.
                If it is None, it will not be modified
        """
        if total is not None:
            self.total = total
        if inscrease is not None:
            self.increase = inscrease
        if width is not None:
            self.width = width
        self.current = -1

    def finish(self):
        """Complete output and return the instance object itself.
        """
        sys.stdout.write('\n')
        sys.stdout.flush()
        return self
