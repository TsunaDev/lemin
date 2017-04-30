/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 20:04:25 2017 Martin Van Elslande
*/

#include	"stock_tun.h"
#include	"lemin.h"
#include	"check_file.h"
#include	"my_string.h"
#include	"pathfinding.h"

static int	nb_of_rooms(t_room **room)
{
  int		i;

  i = 0;
  while (room[i] != NULL)
    i++;
  return (i);
}

int		my_pars(char **arr)
{
  int		nbr_ants;
  t_room	**room;
  int		**tab_tun;
  int		status_room;
  int		size;
  int		**paths;
  int		ret;

  if (arr == NULL)
    return (84);
  nbr_ants = check_file(arr);
  if (nbr_ants == -1)
    return (1);
  arr = skip_bad_line(arr);
  my_valid_file(arr);
  size = nb_room(arr) + 1;
  room = malloc(sizeof(t_room *) * size);
  if (room == NULL || arr == NULL)
    return (84);
  status_room = 0;
  my_create_room(room, arr, &status_room);
  if (status_room == 84)
    return (84);
  my_sort_room(room);
  arr = check_nbr_room(room, arr);
  display_arr(arr);
  suppr_double_tun(arr);
  tab_tun = create_tab_int(room, arr);
  ret = pathfinding(tab_tun, tab_tun[0][0], nb_of_rooms(room), &paths);
  if (ret == 0)
    display_graphical(nbr_ants, room, tab_tun, paths);
  return (ret);
}
