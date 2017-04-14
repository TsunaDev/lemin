##
## Makefile for Makefile in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
## 
## Made by anaisbrnt
## Login   <anais.breant@epitech.eu>
## 
## Started on  Tue Apr  4 17:10:32 2017 anaisbrnt
## Last update Thu Apr 13 15:01:09 2017 Anaïs Breant
##

NAME	=	lem_in

CC	=	gcc -o

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+=	-Iinclude

SRCS	=	src/anais/open_file.c			\
		src/anais/my_pars.c			\
		src/anais/create_room.c			\
		src/anais/main.c			\
		src/anais/check_file.c			\
		src/anais/check_nbr_ants.c		\
		src/anais/check_start_end.c		\
		src/anais/skip_bad_line.c		\
		src/anais/epur_str_check.c		\

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-Lsrc/lib_string -lstr

all: $(NAME)

$(NAME): $(OBJS)
	make -C src/lib_string
	$(CC) $(NAME) $(OBJS) $(LDFLAGS)

clean:
	make -C src/lib_string clean
	rm -rf $(OBJS)

fclean: clean
	make -C src/lib_string fclean
	rm -rf $(NAME)

re: fclean all
