#include <stdint.h>
#include "FPU_reg.h"


/*
	Function to Enable Floating point unit in cortex M4 Processors

*/


void EnableFPU(void){


	uint32_t Loc_u32Value;
	/*Read the current value of the CPACR register*/
    Loc_u32Value = CPACR;

    /*Set bits 20-23 to enable CP10 and CP11 coprocessors*/
    Loc_u32Value |= (0xF << 20);

    /*Write the modified value back to the CPACR register*/
    CPACR = Loc_u32Value;
	/*Data Synchronization Barrier*/
	__asm volatile("dsb");
	/*Instruction Synchronization Barrier*/
	__asm volatile("isb");
	
	
}
