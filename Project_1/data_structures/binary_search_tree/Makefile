
CC=gcc
CXX=g++
RM=rm 
CFLAGS=-I$(IDIR)
SRCS=*.cpp 

.SILENT:compile run 

all: compile run 

compile:
	$(CXX) -std=c++11 -o binary_search_tree $(SRCS)
run:
	./binary_search_tree
clean:
	$(RM) binary_search_tree 