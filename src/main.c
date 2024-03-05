#include "app.h"
#include <windows.h>

int main(int argc, char *argv[])
{
	app_init();

	app_loop();

	/*
	terminal_refresh();

	chtype i = 0;

	while (1)
	{
		terminal_clear();
		for (int j = 0; j < T_HT; j++)
		{
			char num[32];
			itoa(i, num, 10);

			terminal_put_string(0, j, num);
			terminal_put(6, j, i++);
		}
		terminal_refresh();

		terminal_input();
	}
	*/

	app_end();

	return EXIT_SUCCESS;
}