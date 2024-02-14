#include "app.h"

static void app_draw_player_inventory(Entity* entity) {
    attr_t def_color = terminal_new_color(T_WHT, T_BLK, 0);
    
    for (size_t i = 0; i < entity->inventory->items->length; i++) {
        Item* p = entity->inventory->items->data[i];
        
        terminal_change_color(p->object->color);
        terminal_put(10, i, p->object->glyph);
        terminal_change_color(def_color);
        terminal_put_string(12, i, p->object->name);
    }
}

static void app_draw_map(Map* map) {
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
			
			if (p->name == PLAYER) {
			    app_draw_player_inventory(p);
			}
			
			entity_act(p, map);
			
			terminal_change_color(p->object->color);
			terminal_put(p->x, p->y, p->object->glyph);
		}
}

static Map* game_map; 

void app_init() {
    game_map = map_new(10, 10);
	map_generate_test(game_map);
	
	terminal_init();
}

void app_loop() {
    while(terminal_current_key != 'q') {
		terminal_input();
		terminal_clear();
		
		app_draw_map(game_map);
		
		terminal_refresh();
	}
}

void app_end() {
    terminal_end();
    
    map_free(game_map);
}

