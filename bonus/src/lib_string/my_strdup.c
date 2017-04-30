/*
** my_strdup.c for my_strdup.c in /home/gaby/projet_Epitech/PSU/tetris_PSU
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Tue Feb 21 23:11:31 2017 Glenn Gabriel Irakiza
** Last update Tue Mar 14 12:36:22 2017 Glenn Gabriel Irakiza
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

char		*my_strcpy(char *src, char *dest)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strdup(char *src)
{
  char		*str;

  if (src == NULL)
    return (NULL);
  str = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (str == NULL)
    return (NULL);
  str = my_strcpy(src, str);
  return (str);
}
