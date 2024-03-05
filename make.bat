@ECHO OFF

ECHO Compiling...
gcc -Os -s -fno-ident -fno-asynchronous-unwind-tables ./src/*.c -I./inc -o app.exe -lpdcurses
ECHO Compiled!

where /q upx.exe 
IF ERRORLEVEL 1 (
    ECHO upx.exe doesn't exist in path, please add it to the path if you want to further decrease binary size.
) ELSE (
    ECHO Packing...
    upx.exe -9 app.exe
    ECHO Packed!
)