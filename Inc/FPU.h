#ifndef FPU_H
#define FPU_H


/*
	Function to Enable Floating point unit in cortex M4 Processors
	#########################################################################
	You need To call this function Before Performing any Floating Point 
	operation otherwise it could cause HardFault or System behaves incorrectly
	#########################################################################
	Better approach is to implement the same enabling logic in startup code 
*/



void EnableFPU(void);





#endif 
