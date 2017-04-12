/*
** my_showtab.c for my_showtab.c in /home/gaby/projet_Epitech/PSU/tetris_PSU
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sat Feb 25 16:19:42 2017 Glenn Gabriel Irakiza
** Last update Mon Apr 10 14:30:01 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

void		my_showtab(char **form)
{
  int		y;
  int		len;

  y = 0;
  if (form == NULL)
    return ;
  while (form[y] != NULL)
    {
      len = my_strlen(form[y]);
      if (len != 0)
	{
	  my_putstr(1, form[y]);
	  my_putchar(1, '\n');
	}
      y++;
    }
}
