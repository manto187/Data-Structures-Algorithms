# Makefile for Smart University Operations System
# DSA Final Project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./src
LDFLAGS = 

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Source files
SOURCES = $(SRC_DIR)/main.cpp

# Object files
OBJECTS = $(BUILD_DIR)/main.o

# Executable
TARGET = $(BIN_DIR)/university_system

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p data

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build successful! Executable: $(TARGET)"

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Clean complete!"

# Clean everything including data
cleanall: clean
	rm -rf data
	@echo "All files removed!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  run      - Build and run the program"
	@echo "  clean    - Remove build files"
	@echo "  cleanall - Remove build files and data"
	@echo "  help     - Show this help message"

.PHONY: all directories run clean cleanall help
