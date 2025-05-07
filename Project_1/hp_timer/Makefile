CC=gcc
CXX=g++
RM=rm 
CFLAGS=-I$(IDIR)
SRCS=*.cpp 

.SILENT:compile run clean

all: compile run clean

compile:
	$(CXX) -std=c++23 -o hp_timer $(SRCS)
run:
	./hp_timer
clean:
	$(RM) hp_timer 