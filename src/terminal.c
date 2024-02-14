#include "terminal.h"

static void init_colors()
{
    start_color();

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            init_pair(j << 4 | i, i, j);
        }
    }
}

void terminal_init()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    if (!has_colors())
    {
        exit(EXIT_FAILURE);
    }

    init_colors();
}

void terminal_end()
{
    endwin();
}   

void terminal_change_color(attr_t color)
{
    attroff(terminal_current_color);
    terminal_current_color = color;
    attron(terminal_current_color);
}

void terminal_put(int x, int y, unsigned char c)
{
    mvaddch(y, x, c);
}

void terminal_put_string(int x, int y, char *str)
{
    mvaddstr(y, x, str);
}

void terminal_clear()
{
    clear();
}

void terminal_refresh()
{
    refresh();
}

void terminal_input()
{
    terminal_current_key = getch();
}

attr_t terminal_new_color(int fg, int bg, bool bright)
{
    return COLOR_PAIR(bg << 4 | fg) | (bright ? A_BOLD : A_NORMAL);
}

size_t terminal_get_width() {
    return getmaxx(stdscr);
}

size_t terminal_get_height() {
    return getmaxy(stdscr);
}