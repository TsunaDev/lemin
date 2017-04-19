/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 20:34:15 2017 Anaïs Breant
*/

#include	"lemin.h"
#include	"check_file.h"
#include	"my_string.h"

int		my_pars(char **arr)
{
  t_room	**room;

  arr = check_file(arr);
  if (arr == NULL)
    return (-1);
  arr = skip_bad_line(arr);
  my_valid_file(arr);
  display_arr(arr);
  room = my_recup_room(arr);
  arr = check_nbr_room(room, arr);
  return (0);
}
