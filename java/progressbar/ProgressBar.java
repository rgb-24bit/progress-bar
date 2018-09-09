package progressbar;

/**
 * Output a simple progress bar to the terminal.
 */
public class ProgressBar {
  private int total = 0;
  private int increase = 1;
  private int width = 50;
  private int current = -1;

  /**
   * Create a new ProgressBar object.
   * @param total The total size of progress.
   */
  public ProgressBar(int total) {
    this.total = total;
  }

  /**
   * Create a new ProgressBar object.
   * @param total The total size of progress.
   * @param increase Every time the default self-increase, the default is 1.
   */
  public ProgressBar(int total, int increase) {
    this.total = total;
    this.increase = increase;
  }

  /**
   * Create a new ProgressBar object.
   * @param total The total size of progress.
   * @param increase Every time the default self-increase, the default is 1.
   * @param width The width of the character output from the progress bar, the default is 50.
   */
  public ProgressBar(int total, int increase, int width) {
    this.total = total;
    this.increase = increase;
    this.width = width;
  }

  /**
   * Output progress bar to terminal.
   * Use {@code increase} to increase current progress.
   */
  public void output() {
    current += increase;
    System.out.print(getOutputString());
  }

  /**
   * Output progress bar to terminal.
   * @param current Special current progress.
   */
  public void output(int current) {
    this.current = current;
    System.out.print(getOutputString());
  }

  /**
   * Reinitialize the progress bar properties.
   * @param total The total size of progress.
   */
  public void restart(int total) {
    this.total = total;
    this.current = -1;
  }

  /**
   * Reinitialize the progress bar properties.
   * @param total The total size of progress.
   * @param increase Every time the default self-increase.
   */
  public void restart(int total, int increase) {
    this.total = total;
    this.increase = increase;
    this.current = -1;
  }

  /**
   * Reinitialize the progress bar properties.
   * @param total The total size of progress.
   * @param increase Every time the default self-increase.
   * @param width The width of the character output from the progress bar.
   */
  public void restart(int total, int increase, int width) {
    this.total = total;
    this.increase = increase;
    this.width = width;
    this.current = -1;
  }

  /**
   * Complete output.
   * @return Return the instance object itself,
   *     use like this: instance.finish().restart(xxx)
   */
  public ProgressBar finish() {
    System.out.print("\n");
    return this;
  }

  /**
   * Get the string to be output currently.
   */
  private String getOutputString() {
    float percent = current * 100.0f / total;

    if (percent >= 100) {
      return String.format("\r[+][%s]%.2f%%", repeat(">", width), 100.0f);
    }

    int currentWidth = current * width / total;
    int remainWidth = width - currentWidth;

    String format = "\r[-][%s%s]%.2f%%";
    return String.format(format, repeat(">", currentWidth), repeat("-", remainWidth), percent);
  }

  /**
   * Repeat string specified times.
   */
  private String repeat(String string, int count) {
    return new String(new char[count]).replace("\0", string);
  }
}
