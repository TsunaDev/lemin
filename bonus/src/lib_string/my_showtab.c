/*
** my_showtab.c for my_showtab.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:51:43 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:51:45 2017 Glenn Gabriel Irakiza
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
