################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/config" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/StdPeriph_Driver/inc" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/inc" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/CMSIS/device" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/CMSIS/core" -I"/home/dell/git/RTOS/RTOS/HELLOOO_wOOORLD/Third-Party/FreeRTOS/org/Source/include" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


