##
## Makefile for Makefile in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
## 
## Made by anaisbrnt
## Login   <anais.breant@epitech.eu>
## 
## Started on  Tue Apr  4 17:10:32 2017 anaisbrnt
## Last update Sun Apr 30 04:53:09 2017 LaFleche
##

NAME	=	lem_in

CC	=	gcc -o

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-Iinclude

SRCS	=	src/main.c				\
		src/parsing/open_file.c			\
		src/parsing/my_pars.c			\
		src/parsing/create_room.c		\
		src/parsing/utils_create_room.c		\
		src/parsing/check_file.c		\
		src/parsing/check_nbr_ants.c		\
		src/parsing/check_start_end.c		\
		src/parsing/skip_bad_line.c		\
		src/parsing/epur_str_check.c		\
		src/parsing/valid_file.c		\
		src/parsing/my_stranger.c		\
		src/parsing/display_arr.c		\
		src/parsing/check_nbr_room.c		\
		src/parsing/delete_room_tunnel.c	\
		src/parsing/my_swap_room.c		\
		src/parsing/verif_pos_room.c		\
		src/parsing/stock_tun/stock_tun.c	\
		src/parsing/stock_tun/fill_tab_tun.c	\
		src/parsing/stock_tun/delete_double.c	\
		pathfinding/create_tools.c		\
		pathfinding/find_my_unique_path.c	\
		pathfinding/first_step.c		\
		pathfinding/find_all_path.c		\
		pathfinding/my_linked_list_ft.c		\
		pathfinding/my_cmp_int.c		\
		pathfinding/my_initialization.c		\
		pathfinding/get_tab_combination.c	\
		display/src/display_shell.c

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
