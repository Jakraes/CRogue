#include "terminal.h"
#include "entity_map.h"

int main(int argc, char* argv[]) {
	Map* map = map_new(10, 10);
	map_generate_test(map);
	
	terminal_init();
	
	while(terminal_current_key != 'q') {
		terminal_input();
		terminal_clear();
		
		for (int i = 0; i < map->terrains->length; i++) {
			Terrain* p = map->terrains->data[i];
			
			terminal_change_color(p->object->color);
			terminal_put(p->x, p->y, p->object->glyph);
		}
		
		for (int i = 0; i < map->items->length; i++) {
			Item* p = map->items->data[i];
			
			terminal_change_color(p->object->color);
			terminal_put(p->x, p->y, p->object->glyph);
		}
		
		for (int i = 0; i < map->entities->length; i++) {
			Entity* p = map->entities->data[i];
			
			entity_act(p, map);
			
			terminal_change_color(p->object->color);
			terminal_put(p->x, p->y, p->object->glyph);
		}
		
		terminal_refresh();
	}
	
	terminal_end();

	return EXIT_SUCCESS;
}