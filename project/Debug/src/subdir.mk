################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/hello.c" 

C_SRCS += \
../src/hello.c 

OBJS_OS_FORMAT += \
./src/hello.o 

C_DEPS_QUOTED += \
"./src/hello.d" 

OBJS += \
./src/hello.o 

OBJS_QUOTED += \
"./src/hello.o" 

C_DEPS += \
./src/hello.d 


# Each subdirectory must supply rules for building sources it contributes
src/hello.o: ../src/hello.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/hello.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/hello.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


