/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 16:08:36 2017 Anaïs Breant
*/

#include	"check_file.h"
#include	"my_string.h"

int		my_pars(char **arr)
{
  int		ants;

  arr = check_file(arr);
  if (arr == NULL)
    return (-1);
  arr = skip_bad_line(arr);
  display_arr(arr);
  printf("-------------GAB----------------------\n");
  my_valid_room(arr);
  return (0);
}
