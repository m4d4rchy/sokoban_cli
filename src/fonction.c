/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** fonction.c
*/

#include "../include/my.h"
#include "../include/lib.h"

void my_print_map(char **map)
{
	int nb = 0;

	while(map[nb][0] != '\0') {
		printw(map[nb]);
		nb = nb + 1;
	}
}

int my_collision_check(int y, int x, char **map)
{
	if (map[y][x] == ' ' || map[y][x] == 'O')
		return (1);
	else if (map[y][x] == 'X')
		return (2);
	else if (map[y][x] == '#')
		return (-1);
	return (0);
}

int *get_pos_player(char **map, char c)
{
	int *pos = malloc(sizeof(int) * 10);
	int y = 0;
	int x = 0;
	int nb = 0;

	while (map[y][x] != '\0') {
		if (map[y][x] == c) {
			pos[nb] = y;
			pos[nb+1] = x;
			nb = nb + 2;
		}
		x = x + 1;
		if (map[y][x] == '\n') {
			x = 0;
			y = y + 1;
		}
	}
	pos[nb] = -1;
	return (pos);
}

int my_win_lose(char **map, int total, int *circles)
{
	int *boxes = get_pos_player(map, 'X');
	int win = 0;
	int lose = 0;
	int nb = 0;

	while (circles[nb] != -1 && boxes[nb] != -1) {
		if (circles[nb] == boxes[nb] && circles[nb + 1] == boxes[nb + 1]) {
			win = win + 1;
		}
		if (map[boxes[nb] - 1][boxes[nb + 1]] == '#' && map[boxes[nb]][boxes[nb + 1] + 1] == '#') {
			lose = lose + 1;
		}
		if (map[boxes[nb] + 1][boxes[nb + 1]] == '#' && map[boxes[nb]][boxes[nb + 1] + 1] == '#') {
			lose = lose + 1;
		}
		if (map[boxes[nb] + 1][boxes[nb + 1]] == '#' && map[boxes[nb]][boxes[nb + 1] - 1] == '#') {
			lose = lose  + 1;
		}
		if (map[boxes[nb] - 1][boxes[nb + 1]] == '#' && map[boxes[nb]][boxes[nb + 1] - 1] == '#') {
			lose = lose + 1;
		}
		if (lose == total) {
			clear();
			printw("You Lost!");
			refresh();
			sleep(2);
			free(map);
			endwin();
			exit(1);
		}
		if (win == total) {
			clear();
			printw("You Won!");
			refresh();
			sleep(2);
			free(map);
			endwin();
			exit(0);
		}
		nb = nb + 2;
	}
	return (0);
}

int my_total_count(char **map)
{
	int circles = 0;
	int boxes = 0;
	int y = 0;
	int x = 0;

	while (map[y][x] != '\0') {
		if (map[y][x] == 'O') {
			circles = circles + 1;
		}
		if (map[y][x] == 'X') {
			boxes = boxes + 1;
		}
		x = x + 1;
		if (map[y][x] == '\n') {
			x = 0;
			y = y + 1;
		}
	}
	return (boxes);
}
