/*
** display_shell.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/display
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Apr 25 15:01:46 2017 Martin Van Elslande
** Last update Sun Apr 30 16:13:35 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_string.h"
#include	"lemin.h"

void	one_pipe_loop(t_room **rooms, int nb_ants)
{
  int	i;
  int	idx;

  i = 0;
  idx = get_actual_room(1, rooms);
  while (i < nb_ants)
    {
      my_putstr(1, "P%d-%s\n", i + 1, rooms[idx]->name);
      i++;
    }
}

void	change_state(t_state *state, t_room **rooms, int i)
{
  if (state->next != 1)
    rooms[state->idx]->full = 1;
  if (state->ant_room[i] != 0)
    rooms[state->prev_idx[i]]->full = 0;
  state->ant_room[i] = state->next;
  state->prev_idx[i] = state->idx;
  if (state->next == 1)
    state->remaining--;
}

int	round_loop(t_state *state, t_room **rooms, int ants, int **paths)
{
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (i < ants)
    {
      if (state->ant_room[i] != 1)
	{
	  state->next = next_room(state->ant_room[i],
				  paths[(i % paths[0][0]) + 1]);
	  state->idx = get_actual_room(state->next, rooms);
	  if (!rooms[state->idx]->full)
	    {
	      if (check != 0)
		write(1, " ", 1);
	      change_state(state, rooms, i);
	      my_putstr(1, "P%d-%s", i + 1, rooms[state->idx]->name);
	      check = 1;
	    }
	}
      i++;
    }
  return (check);
}

int		display_shell(int **paths, t_room **rooms, int ants)
{
  t_state	*state;

  if (!ants)
    my_putstr(1, "No ants in the hill\n");
  else if (paths[1][0] == 0 && paths[1][1] == 1)
    one_pipe_loop(rooms, ants);
  else
    {
      state = malloc(sizeof(t_state));
      if (init_state(state, ants) == 84)
	return (84);
      while (state->remaining > 0)
	if (round_loop(state, rooms, ants, paths) == 1)
	  write(1, "\n", 1);
    }
  return (0);
}
