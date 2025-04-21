
CC=gcc
CXX=g++
RM=rm 
CFLAGS=-I$(IDIR)
SRCS=*.cpp 

.SILENT:compile run clean

all: compile run clean

compile:
	$(CXX) -std=c++11 -o linked_list $(SRCS)
run:
	./vectors
clean:
	$(RM) vectors