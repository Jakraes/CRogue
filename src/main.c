#include "app.h"
#include <windows.h>

int main(int argc, char *argv[])
{
	app_init();

	app_loop();

	app_end();

	return EXIT_SUCCESS;
}