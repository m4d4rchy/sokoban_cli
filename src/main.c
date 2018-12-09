/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/lib.h"

int main(int argc, char **argv)
{
	int error = 0;

	if (argc == 2) {
		my_usage(argv[1]);
		error = my_error_check(argv[1]);
		if (error == 0) {
			loop_game(argv[1]);
		}
	}
	else
		exit(84);
	return (0);
}

int loop_game(char *argv)
{
	char *buffer = open_map(argv);
	char **map = gen_map(buffer);
	//char **o_map = gen_map(buffer);
	int *pos = get_pos_player(map, 'P');
	int *posO = get_pos_player(map, 'O');
	int total = my_total_count(map);
	int key = 0;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	my_print_map(map);
	refresh();
	while(1) {
		key = getch();
		pos = get_pos_player(map, 'P');
		map = player_move(pos[0], pos[1], map, key);
		map = my_restart(key, argv, map);
		//map = my_print_o(map, o_map);
		refresh();
		my_win_lose(map, total, posO);
		my_exit(key, map, buffer, pos);
	}
}

int my_usage(char *argv)
{
	if (argv[0] == '-' && argv[1] == 'h') {
		my_printf(" USAGE\n      ./my_sokoban map\n");
		my_printf(" DESCRIPTION\n      map  file representing the warehouse map,");
		my_printf(" containing '#' for walls,\n           'P' for the player, 'X' for boxes and 'O' for");
		my_printf(" storage locations.");
	}
	return (0);
}

char **my_restart(int key, char *argv, char **cpymap)
{
	char *buffer = open_map(argv);
	char **map = cpymap;

	if (key == 32) {
		clear();
		map = gen_map(buffer);
		my_print_map(map);
	}
	return (map);
}

int my_exit(int key, char **map, char *buffer, int *pos)
{
	if (key == 'q') {
		clear();
		free(map);
		free(buffer);
		free(pos);
		endwin();
		exit(84);
	}
	return (0);
}
