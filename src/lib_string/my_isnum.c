/*
** my_isnum.c for my_isnum.c in /home/irakiz_g/delivery/CPE_2016_Pushswap/src
** 
** Made by gabriel irakiza
** Login   <irakiz_g@epitech.net>
** 
** Started on  Wed Nov  9 17:35:21 2016 gabriel irakiza
** Last update Fri Feb 24 14:19:20 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	<stdio.h>

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
