################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/FPU.c \
../Src/GPIO_prog.c \
../Src/KeyPad_prog.c \
../Src/LCD_prog.c \
../Src/RCC_prog.c \
../Src/SysTick.c \
../Src/calculator.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/FPU.o \
./Src/GPIO_prog.o \
./Src/KeyPad_prog.o \
./Src/LCD_prog.o \
./Src/RCC_prog.o \
./Src/SysTick.o \
./Src/calculator.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/FPU.d \
./Src/GPIO_prog.d \
./Src/KeyPad_prog.d \
./Src/LCD_prog.d \
./Src/RCC_prog.d \
./Src/SysTick.d \
./Src/calculator.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/FPU.cyclo ./Src/FPU.d ./Src/FPU.o ./Src/FPU.su ./Src/GPIO_prog.cyclo ./Src/GPIO_prog.d ./Src/GPIO_prog.o ./Src/GPIO_prog.su ./Src/KeyPad_prog.cyclo ./Src/KeyPad_prog.d ./Src/KeyPad_prog.o ./Src/KeyPad_prog.su ./Src/LCD_prog.cyclo ./Src/LCD_prog.d ./Src/LCD_prog.o ./Src/LCD_prog.su ./Src/RCC_prog.cyclo ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/SysTick.cyclo ./Src/SysTick.d ./Src/SysTick.o ./Src/SysTick.su ./Src/calculator.cyclo ./Src/calculator.d ./Src/calculator.o ./Src/calculator.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

