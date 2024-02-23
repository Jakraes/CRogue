#include "app.h"

int main(int argc, char *argv[])
{
	app_init();

	app_loop();

	app_end();

	return EXIT_SUCCESS;
}