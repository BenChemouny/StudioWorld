################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Actor.cpp \
../Cinema.cpp \
../Director.cpp \
../Movie.cpp \
../Producer.cpp \
../Professional.cpp \
../Recv.cpp \
../ScreenWriter.cpp \
../TCPServer.cpp \
../server.cpp 

OBJS += \
./Actor.o \
./Cinema.o \
./Director.o \
./Movie.o \
./Producer.o \
./Professional.o \
./Recv.o \
./ScreenWriter.o \
./TCPServer.o \
./server.o 

CPP_DEPS += \
./Actor.d \
./Cinema.d \
./Director.d \
./Movie.d \
./Producer.d \
./Professional.d \
./Recv.d \
./ScreenWriter.d \
./TCPServer.d \
./server.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


