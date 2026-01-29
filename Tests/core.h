/*!
 * \file core.h
 * \brief Core-specific function declarations.
 * \details This header file contains declarations for core-specific functions used
 * in the TriCore test suite.
 */

 /*!
  * \brief Core-0 main function declaration.
  * \details This function is marked with the "no return" attribute to indicate
  * that it does not return.
  */
void core0_main(void) __attribute__((noreturn));
