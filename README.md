Advanced Calculator Using STM32F446RE Microcontroller (ARM Cortex-M4)

### Overview
This project implements an advanced calculator using the STM32F446RE microcontroller, based on the ARM Cortex-M4 architecture. The calculator supports 32-bit integers and floating-point numbers for division operations, taking full advantage of the Cortex-M4's Floating Point Unit (FPU) for efficient floating-point computations.

The project includes custom drivers for GPIO, RCC, and SysTick peripherals, making the implementation highly modular and flexible.

### Features

32-bit Integer Calculations: Capable of performing basic arithmetic operations (addition, subtraction, multiplication, division) with numbers up to 32 bits.
Floating-point Division: The FPU allows handling single-precision floating-point numbers for division with improved performance.

### Custom Peripheral Drivers: The project includes manually written drivers for the following peripherals:

### GPIO: For handling inputs and outputs.

https://github.com/Ahmed123231/GPIO-Driver-For-STM32F446RE

### RCC: For configuring and managing the clock system.

https://github.com/Ahmed123231/RCC-Driver-For-STM32F446RE-

### SysTick: For timing and delay operations.

https://github.com/Ahmed123231/SysTick-Timer-Driver-For-ARM-Cortex-M4-and-M3-Processors

### FPU: For Dealing with Floating Numbers

https://github.com/Ahmed123231/FPU-Driver-For-ARM-Cortex-M4-Processors
