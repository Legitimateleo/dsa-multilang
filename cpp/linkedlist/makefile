CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

# List of all source (.cpp) files used in the project
SRCS = linkedlist1.cpp test.cpp 

# Automatically generate dependency file names (.d) from source files
# This is useful for tracking header dependencies, although they are
# not yet included in this Makefile.
DEPS = $(SRCS:.cpp=.d)

# Default target: builds the 'test' executable when 'make' is run
all: test

# Pattern rule: how to compile any .cpp file into a .o object file
# $< represents the first prerequisite (the .cpp file)
# $@ represents the target (the .o file)
.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

# Link object files together to create the final executable
# test depends on test.o and linkedlist1.o, so they must be built first
test: test.o linkedlist1.o
	$(CC) test.o linkedlist1.o -o test

# Remove all generated files to allow a clean rebuild
# This deletes object files and the final executable
clean:
	rm *.o test