
CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-I$(IDIR)
SRCS=vectors.cpp 

.SILENT:compile run clean

all: compile run clean

compile:
	$(CXX) -o vectors $(SRCS)
run:
	./vectors
clean:
	$(RM) vectors