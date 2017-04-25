##
## Makefile for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
## 
## Made by LaFleche
## Login   <vincent.larcher@epitech.eu>
## 
## Started on  Sat Apr 22 23:02:42 2017 LaFleche
## Last update Mon Apr 24 11:52:36 2017 LaFleche
##

NAME	=	boobs

CC	=	gcc -o

CFLAGS	=	-Wall -Wextra -g

SRCS	=	create_tools.c				\
		find_all_path.c				\
		my_linked_list_ft.c			\
		my_cmp_int.c				\
		get_tab_combination.c


OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(NAME) $(OBJS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
