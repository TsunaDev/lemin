/*
** display_utils.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr 30 16:05:45 2017 Martin Van Elslande
** Last update Sun Apr 30 16:14:52 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	"lemin.h"

void		memset_int_array(int *arr, int size, int def)
{
  int		i;

  i = 0;
  while (i < size)
    {
      arr[i] = def;
      i++;
    }
}

int		next_room(int actual, int *path)
{
  int		i;

  i = 0;
  while (path[i] != actual && path[i] != -1)
    i++;
  return (path[i + 1]);
}

int		get_actual_room(int room, t_room **rooms)
{
  int		i;

  i = 0;
  while (rooms[i]->new_name != room)
    i++;
  return (i);
}

int		init_state(t_state *state, int nb_ants)
{
  state->ant_room = malloc(sizeof(int) * nb_ants);
  state->prev_idx = malloc(sizeof(int) * nb_ants);
  if (!state->ant_room || !state->prev_idx)
    return (84);
  memset_int_array(state->ant_room, nb_ants, 0);
  memset_int_array(state->prev_idx, nb_ants, 0);
  state->remaining = nb_ants;
  state->next = 0;
  state->idx = 0;
  return (0);
}
