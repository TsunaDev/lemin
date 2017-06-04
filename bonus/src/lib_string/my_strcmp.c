/*
** my_strcmp.c for my_strcmp.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:52:05 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:52:06 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>

int		my_strcmp(char *src, char *dest)
{
  int		i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (-1);
  while (src[i] != '\0' || dest[i] != '\0')
    {
      if (src[i] != dest[i])
	return (1);
      if (src[i] == dest[i])
	i++;
    }
  return (0);
}

int		my_strncmp(char *src, char *dest, int n)
{
  int		i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (-1);
  while (i < n)
    {
      if (src[i] != dest[i])
	return (1);
      if (src[i] == dest[i])
	i++;
    }
  return (0);
}
