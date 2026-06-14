#!/bin/bash
# Build script for Smart University Operations System (Linux/Mac)
# DSA Final Project

echo "========================================"
echo "Smart University Operations System"
echo "Building Project..."
echo "========================================"
echo ""

# Create directories if they don't exist
mkdir -p build
mkdir -p bin
mkdir -p data

# Compile the project
echo "Compiling..."
g++ -std=c++11 -Wall -Wextra -Isrc src/main.cpp -o bin/university_system

if [ $? -eq 0 ]; then
    echo ""
    echo "========================================"
    echo "Build successful!"
    echo "Executable: bin/university_system"
    echo "========================================"
    echo ""
    echo "Run with: ./bin/university_system"
    echo "Or simply: ./run.sh"
else
    echo ""
    echo "========================================"
    echo "Build failed! Please check errors above."
    echo "========================================"
    exit 1
fi
