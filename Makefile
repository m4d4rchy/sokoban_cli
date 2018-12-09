##
## EPITECH PROJECT, 2017
## Makefiles
## File description:
## 
##

CC	= 	gcc

LDFLAGS =       lib/libmy.a

FLAGS   =       -W -Wall -Werror -Wextra -lncurses

NAME	= 	my_sokoban

SRC 	=	src/main.c\
		src/open.c\
		src/movement.c\
		src/fonction.c\
		src/error.c

all: 		$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(LDFLAGS)

clean:
		make -f lib/my/Makefile clean

fclean: 	clean
		$(RM) $(NAME)
re: 		fclean all

.PHONY: 	all clean fclean re
