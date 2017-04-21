/*
** my_strcmp.c for my_strcmp.c in /home/gaby/projet_Epitech/PSU/PSU_2016_minishell1/src
** 
** Made by Irakiz_g
** Login   <glenn-gabriel.irakiza@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 10 22:41:18 2017 Irakiz_g
** Last update Fri Apr 21 08:31:35 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_strcmp(char *src, char *dest)
{
  int		i;
  int		len1;
  int		len2;

  i = 0;
  len1 = my_strlen(src);
  len2 = my_strlen(dest);
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
