################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/AHRS.cc \
../src/AdvUAVHost.cc \
../src/DataAcq.cc \
../src/NAV.cc \
../src/Telemetry.cc \
../src/UAVControl.cc 

OBJS += \
./src/AHRS.o \
./src/AdvUAVHost.o \
./src/DataAcq.o \
./src/NAV.o \
./src/Telemetry.o \
./src/UAVControl.o 

CC_DEPS += \
./src/AHRS.d \
./src/AdvUAVHost.d \
./src/DataAcq.d \
./src/NAV.d \
./src/Telemetry.d \
./src/UAVControl.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DWITH_TCP_COMMON -DWITH_TCP_INET -DWITH_IPv4 -DWITH_IPv6 -DWITH_UDP -DWITH_RTP -DWITH_SCTP -DWITH_DHCP -DWITH_ETHERNET -DWITH_PPP -DWITH_EXT_IF -DWITH_MPLS -DWITH_OSPFv2 -DWITH_BGPv4 -DWITH_TRACI -DWITH_MANET -DWITH_xMIPv6 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


