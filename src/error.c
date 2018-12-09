/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** error.c
*/

#include "../include/my.h"
#include "../include/lib.h"

int my_error_check(char *argv)
{
	int fd = open(argv, O_RDONLY);
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * 1000);
	if (buffer == NULL)
		exit(84);
	if (fd >= 0) {
		read(fd, buffer, 1000);
		return (map_check(buffer));
	}
	else {
		write(2, "File not exist", 14);
		exit(84);
	}
	return (0);
}

int map_check(char *buffer)
{
	int nb  = 0;
	int boxes = 0;
	int circles = 0;
	int player = 0;

	while (buffer[nb] != '\0') {
		if (buffer[nb] == 'X')
			boxes = boxes + 1;
		if (buffer[nb] == 'O')
			circles = circles + 1;
		if (buffer[nb] == 'P')
			player = player + 1;
		nb = nb + 1;
	}
	if (boxes != circles || player == 0 || player > 1) {
		write(2, "Invalid map", 11);
		exit(84);
	}
	return (0);
}
