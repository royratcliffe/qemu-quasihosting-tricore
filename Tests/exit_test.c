int core0_main(void) {
  /*
   * Write the string "EXIT\n" to the TriCore test device to indicate test
   * completion.
   */
  for (const char *con = "EXIT\n"; *con != '\0'; con++) {
    *(volatile int *)0xf0000000U = 0x100 | (*con & 0xff);
  }

  /*
   * Write the magic value to the TriCore test device to flush the output
   * buffer.
   */
  *(volatile int *)0xf0000000U = 0x200;

  /*
   * Write a value to the TriCore test device to trigger an exit.
   * The value written determines the exit code of QEMU.
   */
  *(volatile int *)0xf0000000U = 8;
  return 0;
}
