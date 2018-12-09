/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** movement.c
*/

#include "../include/my.h"
#include "../include/lib.h"

char **map_movement(char **map, int y, int x, int option)
{
	if (option == 1) {
		map[y][x] = ' ';
		map[y][x + 1] = 'P';
	}
	else if (option == 2) {
		map[y][x] = ' ';
		map[y][x - 1] = 'P';
	}
	else if (option == 3) {
		map[y][x] = ' ';
		map[y - 1][x] = 'P';
	}
	else if (option == 4) {
		map[y][x] = ' ';
		map[y + 1][x] = 'P';
	}
	return (map);
}

char **map_movementX(char **map, int y, int x, int option)
{
	if (option == 1) {
		map[y][x] = ' ';
		map[y][x + 1] = 'P';
		map[y][x + 2] = 'X';
	}
	else if (option == 2) {
		map[y][x] = ' ';
		map[y][x - 1] = 'P';
		map[y][x - 2] = 'X';
	}
	else if (option == 3) {
		map[y][x] = ' ';
		map[y - 1][x] = 'P';
		map[y - 2][x] = 'X';
	} else if (option == 4) {
		map[y][x] = ' ';
		map[y + 1][x] = 'P';
		map[y + 2][x] = 'X';
	}
	return (map);
}

char **player_move(int y, int x, char **map, int key)
{
	int check = 1;

	clear();
	switch (key) {
	case KEY_RIGHT:
		check = my_collision_check(y, x + 1, map);
		if (check == 1) {
			map = map_movement(map, y, x, 1);
			x = x + 1;
		}
		if (check == 2) {
			check = my_collision_check(y, x + 2, map);
			if (check == 1) {
				map = map_movementX(map, y, x, 1);
				x = x + 1;
			}
		}
		my_print_o(map, newmap);
		break;
	case KEY_LEFT:
		check = my_collision_check(y, x - 1, map);
		if (check == 1) {
			map = map_movement(map, y, x, 2);
			x = x - 1;
		}
		if (check == 2) {
			check = my_collision_check(y, x - 2, map);
			if (check == 1) {
				map = map_movementX(map, y, x, 2);
				y = y + 1;
			}
			
		}
		break;
	case KEY_UP:
		check = my_collision_check(y - 1, x, map);
		if (check == 1) {
			map = map_movement(map, y, x, 3);
			y = y - 1;
		}
		if (check == 2) {
			check = my_collision_check(y - 2, x, map);
			if (check == 1) {
				map = map_movementX(map, y, x, 3);
				y = y + 1;
			}
		}
		break;
	case KEY_DOWN:
		check = my_collision_check(y + 1, x, map);
		if (check == 1) {
			map = map_movement(map, y, x, 4);
			y = y + 1;
		}
		if (check == 2) {
			check = my_collision_check(y + 2, x, map);
			if (check == 1) {
				map = map_movementX(map, y, x, 4);
				y = y + 1;
			}
		}
		break;
	}
	my_print_map(map);
	return (map);
}
