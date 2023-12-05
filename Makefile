# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Name of your main executable
TARGET = hw5

# Source directory
SRC_DIR = ./src

# Build directory
BUILD_DIR = ./build

# All .cc files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)

# Object files (one for each source file)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))

# Default rule
all: $(TARGET)

# Debug rule
debug: CXXFLAGS += -g
debug: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to clean build files
clean:
	rm -rf $(TARGET) $(BUILD_DIR)/*