#!/bin/bash
# Run script for Smart University Operations System (Linux/Mac)

if [ ! -f "bin/university_system" ]; then
    echo "Executable not found! Building first..."
    ./build.sh
fi

echo ""
echo "========================================"
echo "Starting Smart University System..."
echo "========================================"
echo ""

./bin/university_system
