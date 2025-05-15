CC=gcc
CXX=g++
RM=rm 
CFLAGS=-I$(IDIR)
SRCS=*.cpp 

.SILENT:compile run clean

all: compile run clean

compile:
	$(CXX) -std=c++17 -o matrix $(SRCS)
run:
	./matrix
clean:
	$(RM) matrix
