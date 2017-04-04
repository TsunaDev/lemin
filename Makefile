##
## Makefile for Makefile in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
## 
## Made by anaisbrnt
## Login   <anais.breant@epitech.eu>
## 
## Started on  Tue Apr  4 17:10:32 2017 anaisbrnt
## Last update Tue Apr  4 14:40:21 2017 Glenn Gabriel Irakiza
##

NAME	=	lem_in

CC	=	gcc -o

CFLAGS	= -W -Wall -Wextra
CFLAGS	+= -Iinclude

SRCS	=	src/anais/open_file.c			\
		src/lib/my_strcat.c			\
		src/lib/my_strlen.c			\
		src/lib/get_next_line.c			\
		src/lib/my_strnchar_to_wordtab.c	\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
