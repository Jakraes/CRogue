#include "app.h"

static int camera_x = 0;
static int camera_y = 0;
static Map *game_map;

static void app_draw_player_inventory(Entity *entity)
{
	attr_t def_color = terminal_new_color(T_WHT, T_BLK, 0, 0);

	for (size_t i = 0; i < entity->inventory->items->length; i++)
	{
		Item *p = entity->inventory->items->data[i];

		terminal_change_color(p->object->color);
		terminal_put(10, i, p->object->glyph);
		terminal_change_color(def_color);
		// terminal_put(12, i, p->object->name);
	}
}

static void app_draw_map(Map *map)
{
	for (int y = 0; y < T_HT; y++)
	{
		for (int x = 0; x < T_WD; x++)
		{
			int n_y = camera_y - (T_HT / 2) + y;
			int n_x = camera_x - (T_WD / 2) + x;

			Terrain *p = map->terrains->data[n_y * map->height + n_x];

			terminal_change_color(p->object->color);
			terminal_put(x, y, p->object->glyph);
		}
	}

	for (int i = 0; i < map->items->length; i++)
	{
		Item *p = map->items->data[i];

		terminal_change_color(p->object->color);
		terminal_put(p->x, p->y, p->object->glyph);
	}

	for (int i = 0; i < map->entities->length; i++)
	{
		Entity *p = map->entities->data[i];

		/*
		if (p->name == PLAYER) {
			app_draw_player_inventory(p);
		}
		*/

		entity_act(p, map);

		terminal_change_color(p->object->color);
		terminal_put(p->x, p->y, p->object->glyph);
	}
}

static void app_draw_border()
{
	const int x_e = T_WD + T_PWD * 2;
	const int y_e = T_HT + T_PHT * 2;

	terminal_change_color(terminal_new_color(T_WHT, T_BLK, 0, 0));

	for (int y = 0; y < y_e; y++)
	{
		terminal_put_raw(0, y, 179);
		terminal_put_raw(x_e - 1, y, 179);
	}

	for (int x = 0; x < x_e; x++)
	{
		terminal_put_raw(x, 0, 196);
		terminal_put_raw(x, y_e - 1, 196);
	}

	terminal_put_raw(0, 0, 218);
	terminal_put_raw(x_e - 1, 0, 191);
	terminal_put_raw(0, y_e - 1, 192);
	terminal_put_raw(x_e - 1, y_e - 1, 217);

	terminal_put_string_raw(x_e / 2 - strlen("Jak's Rogue") / 2, 0, "Jak's Rogue");
}

void app_init()
{
	terminal_init();

	init_rand();

	app_draw_border();
	terminal_put_string(T_WD / 2 - strlen("Wait...") / 2, T_HT / 2, "Wait...");
	terminal_refresh();

	game_map = map_new(1000, 1000, rand_int(0, 1024), OVERWORLD);

	camera_x = game_map->width / 2;
	camera_y = game_map->height / 2;

	app_draw_border();
	app_draw_map(game_map);

	terminal_refresh();

	// map_generate_test(game_map);
}

void app_loop()
{
	while (terminal_current_key != 'q')
	{
		terminal_input();
		terminal_clear();

		switch (terminal_current_key)
		{
		case 'r':
			app_draw_border();
			terminal_put_string(T_WD / 2 - strlen("Wait...") / 2, T_HT / 2, "Wait...");
			terminal_refresh();

			map_free(game_map);
			game_map = map_new(1000, 1000, rand_int(0, 1024), OVERWORLD);
			break;
		case T_UL:
			camera_y--;
			camera_x--;
			break;
		case T_UM:
			camera_y--;
			break;
		case T_UR:
			camera_y--;
			camera_x++;
			break;
		case T_ML:
			camera_x--;
			break;
		case T_MM:
			break;
		case T_MR:
			camera_x++;
			break;
		case T_LL:
			camera_y++;
			camera_x--;
			break;
		case T_LM:
			camera_y++;
			break;
		case T_LR:
			camera_y++;
			camera_x++;
			break;
		}

		app_draw_border();
		app_draw_map(game_map);

		terminal_refresh();
	}
}

void app_end()
{
	terminal_end();

	map_free(game_map);
}
