##
## Makefile for Makefile in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
## 
## Made by anaisbrnt
## Login   <anais.breant@epitech.eu>
## 
## Started on  Tue Apr  4 17:10:32 2017 anaisbrnt
## Last update Wed Apr 12 11:29:02 2017 Glenn Gabriel Irakiza
##

NAME	=	lem_in

CC	=	gcc -o

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+=	-Iinclude

SRCS	=	src/anais/open_file.c			\
		src/anais/my_pars.c			\
		src/anais/main.c

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
