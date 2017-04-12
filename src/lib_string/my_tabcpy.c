/*
** my_tabcpy.c for my_tabcpy.c in /home/gaby/projet_Epitech/PSU/PSU_2016_my_sokoban
** 
** Made by Irakiz_g
** Login   <glenn-gabriel.irakiza@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 14 15:12:43 2016 Irakiz_g
** Last update Tue Mar 14 14:50:06 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

int		my_strlen_tab(char **arr)
{
  int		i;

  i = 0;
  if (arr == NULL)
    return (0);
  while (arr[i] != NULL)
    i++;
  return (i);
}

char		**my_tab_cpy(char **src)
{
  char		**dest;
  int		b;

  b = 0;
  if (src == NULL)
    return (NULL);
  dest = malloc(sizeof(char *) * (my_strlen_tab(src) + 1));
  if (dest == NULL)
    return (NULL);
  while (src[b] != NULL)
    {
      dest[b] = malloc(sizeof(char) * (my_strlen(src[b]) + 1));
      if (dest[b] == NULL)
	return (NULL);
      dest[b] = my_strcpy(src[b], dest[b]);
      b++;
    }
  dest[b] = NULL;
  return (dest);
}
