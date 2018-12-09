/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** my.h
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_

//main.c
int	loop_game(char *argv);
int	my_usage(char *argv);
char	**my_restart(int key, char *argv, char **cpymap);
int	my_exit(int key, char **map, char *buffer, int *pos);

//open.c
char	**my_print_o(char **map, char **newmap);
char	*open_map(char *file);
char	**gen_map(char *buffer);

//movement.c
char	**map_movement(char **map, int y, int x, int option);
char	**map_movementX(char **map, int y, int x, int option);
char	**player_move(int y, int x, char **map, int key);

//fonction.c
void	my_print_map(char **map);
int	my_collision_check(int y, int x, char **map);
int	*get_pos_player(char **map, char c);
int	my_win_lose(char **map, int total, int *circles);
int	my_total_count(char **map);

//error.c
int	my_error_check(char *argv);
int	map_check(char *buffer);

#endif
