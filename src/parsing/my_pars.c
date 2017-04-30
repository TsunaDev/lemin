/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 18:10:44 2017 Glenn Gabriel Irakiza
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

static void	my_display_arr(char **arr, t_room **room)
{
  arr = check_nbr_room(room, arr);
  display_arr(arr);
  suppr_double_tun(arr);
}

static int	my_path_tun(t_room **room, int nbr_ants, char **arr)
{
  int		**paths;
  int		**tab_tun;
  int		nb_room;
  int		ret;

  nb_room = nb_of_rooms(room);
  tab_tun = create_tab_int(room, arr);
  ret = pathfinding(tab_tun, tab_tun[0][0], nb_room, &paths);
  if (ret == 0)
    display_shell(paths, room, nbr_ants);
  return (ret);
}

int		my_pars(char **arr)
{
  t_room	**room;
  int		nbr_ants;
  int		size;
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
  ret = 0;
  my_create_room(room, arr, &ret);
  if (ret == 84)
    return (84);
  my_sort_room(room);
  my_display_arr(arr, room);
  ret = my_path_tun(room, nbr_ants, arr);
  return (ret);
}
