#include "terminal.h"

static WINDOW *win = NULL;

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
    win = initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(win, TRUE);

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
    wattroff(win, terminal_current_color);
    terminal_current_color = color;
    wattron(win, terminal_current_color);
}

void terminal_put(int x, int y, unsigned char c)
{
    mvwaddch(win, y, x, c);
}

void terminal_put_string(int x, int y, char *str)
{
    mvwaddstr(win, y, x, str);
}

void terminal_clear()
{
    wclear(win);
}

void terminal_refresh()
{
    wrefresh(win);
}

void terminal_input()
{
    terminal_current_key = wgetch(win);
}

attr_t terminal_new_color(int fg, int bg, bool bfg, bool bbg)
{
    return COLOR_PAIR(fg << 4 | bg) | (bbg ? A_BOLD : A_NORMAL) | A_REVERSE | (bfg ? A_BOLD : A_NORMAL);
}

size_t terminal_get_width()
{
    return getmaxx(win);
}

size_t terminal_get_height()
{
    return getmaxy(win);
}