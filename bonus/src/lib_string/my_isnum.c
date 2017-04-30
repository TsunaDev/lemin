/*
** my_isnum.c for my_isnum.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:50:53 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:50:54 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

int		my_isnum(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  if (str == NULL || str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	nb++;
      i++;
    }
  if (i == nb)
    return (0);
  return (1);
}
