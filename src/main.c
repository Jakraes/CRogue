#include "terminal.h"
#include "entity.h"

int main(int argc, char* argv[]) {
	Entity* player = entity_new_player(0, 0);
	
	terminal_init();
	
	while(terminal_current_key != 'q') {
		terminal_input();
		terminal_clear();
		
		entity_move(player);
		
		terminal_change_color(player->object->color);
		terminal_put(player->x, player->y, player->object->glyph);
		
		terminal_refresh();
	}
	
	terminal_end();

	return EXIT_SUCCESS;
}