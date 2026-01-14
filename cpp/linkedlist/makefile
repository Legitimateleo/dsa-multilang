CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
SRCS = linkedlist1.cpp test.cpp 
DEPS = $(SRCS:.cpp=.d)
all: test


.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test: test.o linkedlist1.o
	$(CC) test.o linkedlist1.o -o test



clean:
	rm *.o test