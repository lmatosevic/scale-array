@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64   
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:scale-array.exe
cl.exe /Fo:build\ /Fd:build\vc140.pdb %compilerflags% main.cpp /link %linkerflags% /out:build\scale-array.exe