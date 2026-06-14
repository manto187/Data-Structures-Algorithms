@echo off
REM Build script for Smart University Operations System (Windows)
REM DSA Final Project

echo ========================================
echo Smart University Operations System
echo Building Project...
echo ========================================
echo.

REM Create directories if they don't exist
if not exist "build" mkdir build
if not exist "bin" mkdir bin
if not exist "data" mkdir data

REM Compile the project
echo Compiling...
g++ -std=c++11 -Wall -Wextra -Isrc src/main.cpp -o bin/university_system.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo Build successful!
    echo Executable: bin/university_system.exe
    echo ========================================
    echo.
    echo Run with: bin\university_system.exe
    echo Or simply: run.bat
) else (
    echo.
    echo ========================================
    echo Build failed! Please check errors above.
    echo ========================================
    pause
    exit /b 1
)

pause
