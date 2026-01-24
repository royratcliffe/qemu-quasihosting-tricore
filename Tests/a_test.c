int core0_main(void) {
  *(volatile int *)0xf0000000U = 8;
  return 0;
}
