# Makefile for building the executable

CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g -Werror -std=c++17 -I/opt/homebrew/Cellar/sfml/3.0.0/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Set the default executable name if not provided
EXEC = main 

# List of source files (You can modify this list as needed)
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Default target: build the executable
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

# Compile the source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build artifacts
clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)

# Phony targets
.PHONY: all clean
