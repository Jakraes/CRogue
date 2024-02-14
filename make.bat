Rem gcc ./src/*.c -I./inc/ -s -finline-functions -funroll-loops -o app.exe -lpdcurses

gcc ./src/*.c -I./inc/ -O3 -s -o app.exe -lpdcurses