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

#指明库的路径
LIBDIR=LIB
LIBPAH=-L${LIBDIR}
#指定包含的库
LDFLAGS+= -lCommand -lInvoker -lReceiver

#指定包含的目录
INCPATH+=-I./Command -I./Invoker -I./Receiver

#最终生成的二进制文件a
BIN=Command_Mode
RELEASE_DIR=bin
RELEASE_TARGET=$(RELEASE_DIR)/$(BIN)
#当前 目录中
OBJECTS=$(patsubst %.c, %.o, $(wildcard *.c)) 
OBJECTS+= $(patsubst %.cpp, %.o, $(wildcard *.cpp))

.PHONY:relase clean build  install
release:$(RELEASE_TARGET)
		
clean:
	$(RM) ${OBJECTS} ${TARGETS}
	$(RM) $(RELEASE_DIR)/* 
	$(RM) $(LIBDIR)/*
# create default build dirs
#创建目录
build:		
%/.:
	mkdir -m 777 -p $*

$(RELEASE_TARGET):$(addprefix $(RELEASE_DIR)/,$(OBJECTS))
	$(CXX) $(MACRO) -o $@  $^  $(DFLAGS) $(LDFLAGS) $(LIBPAH)
	echo $@
	
$(RELEASE_DIR)/%.o:%.c
	$(CC) -c $^ -o $@ $(DFLAGS) $(INCPATH) $(LIBPAH)

$(RELEASE_DIR)/%.o:%.cpp
	$(CXX) -c $^ -o $@ $(DFLAGS) $(INCPATH) $(LIBPAH)

#将所有库安装


