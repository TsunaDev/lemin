/*
** my_util_array.c for my_util_array.c in /home/gaby/projet_Epitech/PSU/tetris_PSU/tools_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sat Feb 25 16:47:51 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 16:23:48 2017 Glenn Gabriel Irakiza
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
  if (array != NULL)
    while (array[i] != NULL)
      free(array[i++]);
  free(array);
}
