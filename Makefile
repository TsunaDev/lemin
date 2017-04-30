##
## Makefile for Makefile in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
## 
## Made by anaisbrnt
## Login   <anais.breant@epitech.eu>
## 
## Started on  Tue Apr  4 17:10:32 2017 anaisbrnt
## Last update Sun Apr 30 16:09:26 2017 Martin Van Elslande
##

NAME	=	lem_in

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
		display/src/display_shell.c		\
		display/src/display_utils.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-Lsrc/lib_string -lstr

all: $(NAME)

debug:	CFLAGS += -ggdb3
debug:	re

$(NAME): $(OBJS)
	make -C src/lib_string
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	make -C src/lib_string clean
	rm -rf $(OBJS)

fclean: clean
	make -C src/lib_string fclean
	rm -rf $(NAME)

re: fclean all
