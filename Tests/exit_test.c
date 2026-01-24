int core0_main(void) {
  /*
   * Write a value to the TriCore test device to trigger an exit.
   * The value written determines the exit code of QEMU.
   */
  *(volatile int *)0xf0000000U = 8;
  return 0;
}
