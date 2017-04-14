/*
** my_strdup.c for my_strdup.c in /home/gaby/projet_Epitech/PSU/tetris_PSU
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Tue Feb 21 23:11:31 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 12 16:00:39 2017 Glenn Gabriel Irakiza
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_string.h"

static int	my_strnlen_end(char *str, int i, int end)
{
  int		count;

  count = 0;
  if (str == NULL)
    return (0);
  while (i != end)
    {
      count++;
      i++;
    }
  return (count);
}

static char	*my_strncpy_end(char *src, char *dest, int i, int e)
{
  int		c;

  c = 0;
  if (my_strnlen_end(src, i, e) == 0)
    return (NULL);
  while (i != e)
    {
      dest[c] = src[i];
      i++;
      c++;
    }
  dest[c] = '\0';
  return (dest);
}

char		*my_strndup_end_free(char *src, int i, int e)
{
  char		*str;

  if (src == NULL)
    return (NULL);
  if (e > my_strlen(src) || e <= 0)
    return (NULL);
  str = malloc(sizeof(char) * (my_strnlen_end(src, i, e) + 1));
  if (str == NULL)
    return (NULL);
  str = my_strncpy_end(src, str, i, e);
  free(src);
  return (str);
}
