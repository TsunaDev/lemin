/*
** skip_line_void.c for skip_line_void.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/parsing
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 15:58:09 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 15:59:54 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

int		skip_line_void(char **arr, int y)
{
  int		len;

  y++;
  len = my_strlen(arr[y]);
  while (len == 0)
    {
      y++;
      len = my_strlen(arr[y]);
    }
  return (y);
}
