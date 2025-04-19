
CC=gcc
CXX=g++
RM=rm 
CFLAGS=-I$(IDIR)
SRCS=vectors.cpp 

.SILENT:compile run clean

all: compile run

compile:
	$(CXX) -o vectors $(SRCS)
run:
	./vectors
clean:
	$(RM) vectors