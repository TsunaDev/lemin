/*
** my_util_array.c for my_util_array.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:54:23 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:54:23 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>

int		my_strlen_char(char **arr)
{
  int		y;

  y = 0;
  if (arr == NULL)
    return (0);
  while (arr[y] != NULL)
    y++;
  return (y);
}

void		my_free_array(char **array)
{
  int		i;

  i = 0;
  while (array[i] != NULL)
    free(array[i++]);
  free(array);
}
