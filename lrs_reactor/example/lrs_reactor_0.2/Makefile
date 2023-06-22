CXX=g++
CFLAGS=-g -O2 -Wall -fPIC -Wno-deprecated 

INC=-I../../include
LIB=-L../../lib -llreactor -lpthread
OBJS = $(addsuffix .o, $(basename $(wildcard *.cc)))

all:
	$(CXX) -o lrs_reactor $(CFLAGS)  lrs_reactor.cpp $(INC) $(LIB)

clean:
	-rm -f *.o lrs_reactor