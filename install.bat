@echo off
setlocal

:: Default paths
set "INSTALL_PATH_RELEASE=%CD%\UTF8Lib"
set "INSTALL_PATH_DEBUG=%CD%\UTF8LibDebug"

:: Check if user provided an install path
if not "%~1"=="" set "INSTALL_PATH_RELEASE=%~1\UTF8Lib"
if not "%~2"=="" set "INSTALL_PATH_DEBUG=%~2\UTF8LibDebug"

:: Create build directories if they don't exist
if not exist build mkdir build

:: x86 Release
cmake . -B build\x86 -A Win32
cmake --build build\x86 --config Release
cmake --install build\x86 --prefix %INSTALL_PATH_RELEASE% --config Release

:: x86 Debug
cmake --build build\x86 --config Debug
cmake --install build\x86 --prefix %INSTALL_PATH_DEBUG% --config Debug

:: x64 Release
cmake . -B build\x64 -A x64
cmake --build build\x64 --config Release
cmake --install build\x64 --prefix %INSTALL_PATH_RELEASE% --config Release

:: x64 Debug
cmake --build build\x64 --config Debug
cmake --install build\x64 --prefix %INSTALL_PATH_DEBUG% --config Debug

endlocal
