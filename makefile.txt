# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Define the target executable
TARGET = myprogram

# Define the source files
SRCS = main.cpp filehandler.cpp bintree.cpp bintree_births.cpp bintree_region.cpp avl.cpp bintree_period.cpp hashing.cpp menu.cpp

# Define the header files (for dependency tracking)
HDRS = region.h

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
