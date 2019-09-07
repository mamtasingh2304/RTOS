################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f10x.c 

OBJS += \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f10x.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/Third-Party/SEGGGER/SEGGER" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/Third-Party/SEGGGER/OS" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/Third-Party/SEGGGER/Config" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/config" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/StdPeriph_Driver/inc" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/inc" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/CMSIS/device" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/CMSIS/core" -I"/home/dell/Documents/RTOS/HELLOOO_wOOORLD/Third-Party/FreeRTOS/org/Source/include" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


