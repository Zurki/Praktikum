@echo off
if not exist build mkdir build
pushd build
g++ ..\source\main.cpp -o main.exe
popd