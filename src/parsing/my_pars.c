/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Thu Apr 20 08:54:18 2017 Glenn Gabriel Irakiza
*/

#include	"lemin.h"
#include	"check_file.h"
#include	"my_string.h"

int		my_pars(char **arr)
{
  t_room	**room;
  int		size;

  arr = check_file(arr);
  if (arr == NULL)
    return (-1);
  arr = skip_bad_line(arr);
  my_valid_file(arr);
  size = nb_room(arr) + 1;
  room = malloc(sizeof(t_room *) * size);
  if (room == NULL || arr == NULL)
    return (84);
  my_create_room(room, arr);
  arr = check_nbr_room(room, arr);
  display_arr(arr);
  my_free_room(room);
  return (0);
}
