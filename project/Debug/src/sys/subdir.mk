################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/sys/gpio.c" \
"../src/sys/timer.c" 

C_SRCS += \
../src/sys/gpio.c \
../src/sys/timer.c 

OBJS_OS_FORMAT += \
./src/sys/gpio.o \
./src/sys/timer.o 

C_DEPS_QUOTED += \
"./src/sys/gpio.d" \
"./src/sys/timer.d" 

OBJS += \
./src/sys/gpio.o \
./src/sys/timer.o 

OBJS_QUOTED += \
"./src/sys/gpio.o" \
"./src/sys/timer.o" 

C_DEPS += \
./src/sys/gpio.d \
./src/sys/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/sys/gpio.o: ../src/sys/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/sys/gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/sys/gpio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/timer.o: ../src/sys/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/sys/timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/sys/timer.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


