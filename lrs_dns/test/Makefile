TARGET= LRS_dns_test1
CXX=g++
CFLAGS=-g -O2 -Wall -Wno-deprecated

BASE=../../base
BASE_H=$(BASE)/include

PROTO = $(BASE)/proto
PROTO_H = $(BASE)/proto

LRS_REACTOR=../../LRS_reactor
LRS_REACTOR_H =$(LRS_REACTOR)/include
LRS_REACTOR_LIB=$(LRS_REACTOR)/lib  -llreactor

OTHER_LIB = -lpthread -ldl -lprotobuf
SRC= ./src
INC= -I./include -I$(BASE_H) -I$(LRS_REACTOR_H) -I$(PROTO_H)

LIB= $(MYSQL_LIB) -L$(LRS_REACTOR_LIB) $(OTHER_LIB) 


OBJS = LRS_dns_test1.o
OBJS += $(PROTO)/LRS.pb.o

$(TARGET): $(OBJS)
        $(CXX) $(CFLAGS) -o $(TARGET) $(OBJS) $(INC) $(LIB)

%.o: %.cpp
        $(CXX) $(CFLAGS) -c -o $@ $< $(INC) 

.PHONY: clean

clean:
        -rm -f ./*.o $(TARGET)