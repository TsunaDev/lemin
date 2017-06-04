/*
** my_strndup_end.c for my_strndup_end.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:53:24 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:53:31 2017 Glenn Gabriel Irakiza
*/

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

char		*my_strndup_end(char *src, int i, int e)
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
  return (str);
}
