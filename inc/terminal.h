#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdlib.h>
#include "external/curses.h"

#define T_BLK 0
#define T_BLU 1
#define T_GRN 2
#define T_CYN 3
#define T_RED 4
#define T_PUR 5
#define T_YLW 6
#define T_WHT 7

#define T_UL 55 // key up left (7)
#define T_UM 56 // key up middle (8)
#define T_UR 57 // key up right (9)
#define T_ML 52 // key middle left (4)
#define T_MM 53 // key middle middle (5)
#define T_MR 54 // key middle right (6)
#define T_LL 49 // key down left (1)
#define T_LM 50 // key down middle (2)
#define T_LR 51 // key down right (3)

#define T_WD 61 // terminal width
#define T_HT 41 // terminal height
#define T_PWD 1 // terminal padding
#define T_PHT 1 // terminal padding

chtype terminal_current_color;
int terminal_current_key;

void terminal_init();
void terminal_end();
void terminal_change_color(attr_t color);
void terminal_put_raw(int x, int y, chtype c);
void terminal_put_string_raw(int x, int y, char *str);
void terminal_put(int x, int y, chtype c);
void terminal_put_string(int x, int y, char *str);
void terminal_clear();
void terminal_refresh();
void terminal_input();
attr_t terminal_new_color(int fg, int bg, chtype bfg, chtype bbg);

#endif