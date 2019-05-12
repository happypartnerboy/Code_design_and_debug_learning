#!/usr/bin/make -f 
CC=gcc 
CC?=gcc
CXX=g++
AR=ar
STRIP=strip
RM=rm -rf
INSTALL=install -cv -m 777
CFLAGS+= -Wall
RFLAGS+= $(CFLAGS) -O3 -DNDEBUG
DFLAGS+= $(CFLAGS) -W -g
LFLAGS+= -Wl,--wrap,sem_wait -Wl,--wrap,sem_timedwait -Wl,--wrap,sleep -Wl,--wrap,usleep -lpthread
#指定包含的目录
#INCPATH+= -I.. -I../include -I../PUB -I../PAR -I../RNL -I../../modules/include -I$(CROSS_COMPILE_PATH)/include -I$(CROSS_COMPILE_PATH)/usr/include
MPATH=$(shell pwd)
LIBNAME=$(notdir $(MPATH))
#最终存放库的目录
LIBDIR=../LIB	
BIN=lib$(LIBNAME).a
RELEASE_DIR=RELEASE-arm-static
RELEASE_TARGET=$(RELEASE_DIR)/$(BIN)
#当前 目录中
OBJECTS=$(patsubst %.c, %.o, $(wildcard *.c)) 
OBJECTS+= $(patsubst %.cpp, %.o, $(wildcard *.cpp))

.PHONY:relase clean build  install
release:$(RELEASE_TARGET)
		
clean:
	$(RM) ${OBJECTS} ${TARGETS}
	$(RM) $(RELEASE_DIR)/* 

# create default build dirs
#创建目录
build:		
%/.:
	mkdir -m 777 -p $*

$(RELEASE_TARGET):$(addprefix $(RELEASE_DIR)/,$(OBJECTS))
	@$(AR) crD $@ $^
	echo $@
	$(INSTALL) $@ ${LIBDIR} 
	
$(RELEASE_DIR)/%.o:%.c
	$(CC) -c $^ -o $@ $(RFLAGS) $(INCPATH)

$(RELEASE_DIR)/%.o:%.cpp
	$(CXX) -c $^ -o $@ $(RFLAGS) $(INCPATH)

#将所有库安装


