################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/aspect.cpp \
../src/engine.cpp \
../src/entity.cpp \
../src/entityMgr.cpp \
../src/gameMgr.cpp \
../src/gfxMgr.cpp \
../src/inputMgr.cpp \
../src/main.cpp \
../src/mgr.cpp \
../src/utils.cpp 

CPP_DEPS += \
./src/aspect.d \
./src/engine.d \
./src/entity.d \
./src/entityMgr.d \
./src/gameMgr.d \
./src/gfxMgr.d \
./src/inputMgr.d \
./src/main.d \
./src/mgr.d \
./src/utils.d 

OBJS += \
./src/aspect.o \
./src/engine.o \
./src/entity.o \
./src/entityMgr.o \
./src/gameMgr.o \
./src/gfxMgr.o \
./src/inputMgr.o \
./src/main.o \
./src/mgr.o \
./src/utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/jbusse/Documents/OGRE-Projects/Basic-Engine-Demo/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/local/include/OGRE/Bites -I/usr/local/include/ois -I/usr/local/include/OGRE/RTShaderSystem -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/aspect.d ./src/aspect.o ./src/engine.d ./src/engine.o ./src/entity.d ./src/entity.o ./src/entityMgr.d ./src/entityMgr.o ./src/gameMgr.d ./src/gameMgr.o ./src/gfxMgr.d ./src/gfxMgr.o ./src/inputMgr.d ./src/inputMgr.o ./src/main.d ./src/main.o ./src/mgr.d ./src/mgr.o ./src/utils.d ./src/utils.o

.PHONY: clean-src

