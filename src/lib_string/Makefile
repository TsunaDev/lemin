##
## Makefile for Lemin in /home/lafleche/norm3/CPE_2016_Lemin
## 
## Made by LaFleche
## Login   <vincent.larcher@epitech.eu>
## 
## Started on  Sun Apr 30 13:21:54 2017 LaFleche
## Last update Sun Apr 30 16:09:46 2017 Glenn Gabriel Irakiza
##

NAME	=	libstr.a

SRC	=	my_isnum.c				\
		my_strlen.c				\
		get_next_line.c				\
		my_putchar.c				\
		my_putstr.c				\
		my_showtab.c				\
		my_strcmp.c				\
		my_strcmp_name.c			\
		my_strcat.c				\
		my_strdup.c				\
		my_strndup.c				\
		my_strndup_end_free.c			\
		my_strndup_end.c			\
		my_util_array.c				\
		my_tabcpy.c				\
		my_getnbr.c				\
		my_revstr.c				\
		my_swap.c				\
		my_putnbr.c				\
		match.c					\
		To_wordtab/to_wordtab_to_str.c		\
		To_wordtab/my_epurstr.c			\
		To_wordtab/my_epurnchar_str.c		\
		To_wordtab/my_strnchar_to_wordtab.c	\
		To_wordtab/my_str_to_wordtab.c		\
		To_wordtab/my_str_to_wordtab_hypen.c	\

OBJS	=	$(SRC:.c=.o)

INCLUDE	=	-I../../include/ -g

CFLAGS	=	-W -Wall -Wextra $(INCLUDE)

all: $(NAME)

debug: CFLAGS += -g
debug: re

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
