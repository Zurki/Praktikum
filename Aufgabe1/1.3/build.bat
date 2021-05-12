@echo off
if not exist build mkdir build
pushd build
g++ ..\source\RinglisteSpielerei.cpp ..\source\Ringliste.cpp -o RinglisteSpielerei.exe
popd