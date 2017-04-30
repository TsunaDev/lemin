/*
** my_strcat.c for my_strcat.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:51:54 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:51:55 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	my_cpy(char *src, char *new, int i)
{
  int		j;

  j = 0;
  while (src[j] != '\0')
    {
      new[i] = src[j];
      i++;
      j++;
    }
  return (i);
}

char		*my_strcat(char *src, char *dest, int y)
{
  int	i;
  int	len;
  char	*new;

  i = 0;
  len = my_strlen(dest) + my_strlen(src) + 1;
  new = malloc(sizeof(char) * len);
  if (new == NULL)
    return (NULL);
  if (src)
    i = my_cpy(src, new, i);
  if (dest)
    i = my_cpy(dest, new, i);
  new[i] = '\0';
  if (y != 0)
    free(src);
  return (new);
}

char    *my_strcat_bis(char *str1, char *str2)
{
  int   s;
  int   x;
  int   cpt;
  char  *new;

  s = 0;
  x = 0;
  cpt = my_strlen(str1) + my_strlen(str2);
  new = malloc(sizeof(char) * (cpt + 1));
  cpt = 0;
  while (str1[s] != '\0')
    {
      new[cpt] = str1[s];
      cpt++;
      s++;
    }
  while (str2[x] != '\0')
    {
      new[cpt] = str2[x];
      cpt++;
      x++;
    }
  new[cpt] = '\0';
  return (new);
}
