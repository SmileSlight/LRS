TARGET= bin/lrs_dns
CXX=g++
CFLAGS=-g -O2 -Wall -Wno-deprecated

BASE=../base
BASE_H=$(BASE)/include
LRS_REACTOR=../lrs_reactor
LRS_REACTOR_H =$(LRS_REACTOR)/include
LRS_REACTOR_LIB=$(LRS_REACTOR)/lib  -llreactor

MYSQL=$(BASE)/mysql-connector-c
MYSQL_H=$(MYSQL)/include
MYSQL_LIB=$(MYSQL)/lib/libmysqlclient.a

OTHER_LIB = -lpthread -ldl
SRC= ./src
INC= -I./include -I$(BASE_H) -I$(LRS_REACTOR_H) -I$(MYSQL_H)

LIB= $(MYSQL_LIB) -L$(LRS_REACTOR_LIB) $(OTHER_LIB) 


OBJS = $(addsuffix .o, $(basename $(wildcard $(SRC)/*.cpp)))

$(TARGET): $(OBJS)
	mkdir -p bin
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJS) $(INC) $(LIB)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $< $(INC) 

.PHONY: clean

clean:
	-rm -f src/*.o $(TARGET)