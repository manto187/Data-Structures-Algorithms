@echo off
REM Run script for Smart University Operations System (Windows)

if not exist "bin\university_system.exe" (
    echo Executable not found! Building first...
    call build.bat
)

echo.
echo ========================================
echo Starting Smart University System...
echo ========================================
echo.

bin\university_system.exe

pause
