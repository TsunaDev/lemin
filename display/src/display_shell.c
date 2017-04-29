/*
** display_shell.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/display
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Apr 25 15:01:46 2017 Martin Van Elslande
** Last update Sat Apr 29 15:18:10 2017 Martin Van Elslande
*/

#include	<stdlib.h>
#include	"lemin.h"

void	memset_int_array(int *arr, int size, int def)
{
  int	i;

  i = 0;
  while (i < size)
    {
      arr[i] = def;
      i++;
    }
}

int	next_room(int actual, int *path)
{
  int	i;

  i = 0;
  while (path[i] != actual && path[i] != -1)
    i++;
  return (path[i + 1]);
}

int	get_actual_room(int room, t_room **rooms)
{
  int	i;

  i = 0;
  while (rooms[i]->new_name != room)
    i++;
  return (i);
}

int	display_shell(int **paths, t_room **rooms, int ants)
{
  int	*ant_room;
  int	remaining;
  int	i;
  int	idx;
  int	*prev_idx;
  int	next;
  int	check;

  i = 0;
  remaining = ants;
  if (!ants)
    printf("Insert message here");
  else
    {
      ant_room = malloc(sizeof(int) * ants);
      prev_idx = malloc(sizeof(int) * ants);
      if (!ant_room || !prev_idx)
	return (84);
      memset_int_array(ant_room, ants, 0);
      memset_int_array(prev_idx, ants, 0);      
      while (remaining > 0)
	{
	  i = 0;
	  check = 0;
	  while (i < ants)
	    {
	      if (ant_room[i] != 1)
		{
		  next = next_room(ant_room[i], paths[(i % paths[0][0]) + 1]);
		  idx = get_actual_room(next, rooms);
		  if (!rooms[idx]->full)
		    {
		      if (check != 0)
			printf(" ");
		      if (next != 1)
			rooms[idx]->full = 1;
		      if (ant_room[i] != 0)
			rooms[prev_idx[i]]->full = 0;
		      prev_idx[i] = idx;
		      ant_room[i] = next;
		      printf("P%d-%s", i + 1, rooms[idx]->name);
		      check = 1;
		      if (next == 1)
			remaining--;
		    }
		}
	      i++;
	    }
	  if (check == 1)
	    printf("\n");
	}
    }
  return (0);
}
