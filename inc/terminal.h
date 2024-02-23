#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdlib.h>
#include "external/curses.h"

#define T_UL 55
#define T_UM 56
#define T_UR 57
#define T_ML 52
#define T_MM 53
#define T_MR 54
#define T_LL 49
#define T_LM 50
#define T_LR 51

chtype terminal_current_color;
int terminal_current_key;

void terminal_init();
void terminal_end();
void terminal_change_color(attr_t color);
void terminal_put(int x, int y, unsigned char c);
void terminal_put_string(int x, int y, char *str);
void terminal_clear();
void terminal_refresh();
void terminal_input();
attr_t terminal_new_color(int fg, int bg, bool bfg, bool bbg);
size_t terminal_get_width();
size_t terminal_get_height();

#endif