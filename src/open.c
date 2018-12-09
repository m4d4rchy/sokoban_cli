/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** open.c
*/

#include "../include/my.h"
#include "../include/lib.h"
#include "../include/struct.h"

char **my_print_o(char **map, char **newmap)
{
	int *posO = get_pos_player(newmap, 'O');
	int nb = 0;
	int y = 0;
	int x = 0;

	while (posO[nb] != -1) {
		y = posO[nb];
		x = posO[nb + 1];
		map[y][x] = 'O';
		nb = nb + 2;
	}
	return (map);
}

char *open_map(char *file)
{
	int fd = open(file, O_RDONLY);
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * 1000);
	if (buffer == NULL)
		exit(84);
	if (fd >= 0) {
		read(fd, buffer, 1000);
	}
	else
		exit(84);
	return (buffer);
}

char **gen_map(char *buffer)
{
	char **map = malloc(sizeof(char*) * 1000);
	t_filemap mapbackup;
	int nb = 0;
	int nb2 = 0;
	int line = 0;

	map[0] = malloc(sizeof(char) * 1000);
	while (buffer[nb] != '\0') {
		map[line][nb2] = buffer[nb];
		nb2 = nb2 + 1;
		nb = nb + 1;
		if (buffer[nb] == '\n') {
			map[line][nb2] = buffer[nb];
			map[line][nb2 + 1] = '\0';
			line = line + 1;
			map[line] = malloc(sizeof(char) * 1000);
			nb2 = 0;
			nb = nb + 1;
		}
	}
	line = line + 1;
	map[line] = malloc(sizeof(char) * 1000);
	map[line][0] = '\0';
	t_filemap.mapbackup = map;
	return (map);
}
