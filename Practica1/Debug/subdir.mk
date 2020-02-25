################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cliente.cpp \
../Entrada.cpp \
../Main5.cpp \
../Pedido.cpp \
../PharmaDron.cpp \
../Producto.cpp \
../THashCerradaProducto.cpp 

OBJS += \
./Cliente.o \
./Entrada.o \
./Main5.o \
./Pedido.o \
./PharmaDron.o \
./Producto.o \
./THashCerradaProducto.o 

CPP_DEPS += \
./Cliente.d \
./Entrada.d \
./Main5.d \
./Pedido.d \
./PharmaDron.d \
./Producto.d \
./THashCerradaProducto.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


