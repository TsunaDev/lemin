/*
** my_strdup.c for my_strdup.c in /home/gaby/projet_Epitech/PSU/tetris_PSU
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Tue Feb 21 23:11:31 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 13:31:52 2017 LaFleche
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	my_strnlen(char *str, int i)
{
  int		count;

  count = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      count++;
      i++;
    }
  return (count);
}

char		*my_strncpy(char *src, char *dest, int i)
{
  int		c;

  c = 0;
  if (my_strnlen(src, i) == 0)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[c] = src[i];
      i++;
      c++;
    }
  dest[c] = '\0';
  return (dest);
}

char		*my_strndup(char *src, int i)
{
  char		*str;
  int		size;
  int		len;

  len = my_strlen(src) - 1;
  if (src == NULL || i > len)
    return (NULL);
  size = my_strnlen(src, i) + 1;
  str = malloc(sizeof(char) * size);
  if (str == NULL)
    return (NULL);
  str = my_strncpy(src, str, i);
  return (str);
}
