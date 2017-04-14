##
## Makefile for make in /home/irakiz_g/delivery/PSU_2021_my_printf
## 
## Made by gabriel irakiza
## Login   <irakiz_g@epitech.net>
## 
## Started on  Mon Nov  7 10:40:19 2016 gabriel irakiza
## Last update Wed Apr 12 16:00:54 2017 Glenn Gabriel Irakiza
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
		To_wordtab/to_wordtab_to_str.c		\
		To_wordtab/my_epurstr.c			\
		To_wordtab/my_epurnchar_str.c		\
		To_wordtab/my_strnchar_to_wordtab.c	\
		To_wordtab/my_str_to_wordtab.c		\

OBJS	=	$(SRC:.c=.o)

INCLUDE	=	-I../../include/

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -g $(INCLUDE)

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
