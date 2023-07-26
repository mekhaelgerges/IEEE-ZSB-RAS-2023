################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_MOTOR_programme.c \
../KPD_programme.c \
../LCD_programe.c \
../main.c \
../programme.c 

O_SRCS += \
../DC_MOTOR_programme.o \
../KPD_programme.o \
../programme.o 

OBJS += \
./DC_MOTOR_programme.o \
./KPD_programme.o \
./LCD_programe.o \
./main.o \
./programme.o 

C_DEPS += \
./DC_MOTOR_programme.d \
./KPD_programme.d \
./LCD_programe.d \
./main.d \
./programme.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


