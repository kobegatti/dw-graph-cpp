# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
HEADER_DIR = header
EXTERNAL_DIR = external/json/include

# Subdirectories for main and test
OBJ_MAIN_DIR = $(OBJ_DIR)/main
OBJ_TEST_DIR = $(OBJ_DIR)/test
BIN_MAIN_DIR = $(BIN_DIR)/main
BIN_TEST_DIR = $(BIN_DIR)/test

# Gather all .cpp files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files corresponding to the .cpp files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Object files for main and test
MAIN_OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_MAIN_DIR)/%.o)
TEST_OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_TEST_DIR)/%.o)

# Output binaries
MAIN_BIN = $(BIN_MAIN_DIR)/main
TEST_BIN = $(BIN_TEST_DIR)/test

# Include directory for header files
INCLUDES = -I$(HEADER_DIR) -I$(EXTERNAL_DIR)

# Targets
all: $(MAIN_BIN) $(TEST_BIN)

# Rule to compile the main program (link only main.o and necessary objects)
$(MAIN_BIN): $(OBJ_MAIN_DIR)/main.o $(OBJ_MAIN_DIR)/dwGraph.o $(OBJ_MAIN_DIR)/utils.o
	$(CXX) $^ -o $(MAIN_BIN)

# Rule to compile the test program (link only test.o and necessary objects)
$(TEST_BIN): $(OBJ_TEST_DIR)/test.o $(OBJ_MAIN_DIR)/dwGraph.o $(OBJ_MAIN_DIR)/utils.o
	$(CXX) $^ -o $(TEST_BIN)

# Rule to compile source files into object files for main
$(OBJ_MAIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_MAIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile source files into object files for test
$(OBJ_TEST_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_TEST_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files (but keep the directories)
clean:
	rm -f $(OBJ_DIR)/main/*.o $(OBJ_DIR)/test/*.o
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/main/*.o $(BIN_DIR)/test/*.o
	rm -f $(BIN_DIR)/main/main $(BIN_DIR)/test/test

# Run the main program
run-main: $(MAIN_BIN)
	$(MAIN_BIN)

# Run the test program
run-test: $(TEST_BIN)
	$(TEST_BIN)

.PHONY: all clean run-main run-test
