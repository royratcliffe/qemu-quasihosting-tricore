/*!
 * \brief Initialise the Context Save Area (CSA) linked list.
 * \details This function initialises the CSA linked list for the CPU on which
 * it is called. It links all CSAs in a linked list fashion and sets the FCX and
 * LCX registers accordingly.
 * \param csa_begin Pointer to the start of the CSA area.
 * \param csa_end Pointer to the end of the CSA area.
 */
void Ssw_initCSA(unsigned int *csaBegin, unsigned int *csaEnd);
