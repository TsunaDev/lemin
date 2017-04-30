/*
** my_swap_room.c for my_swap_room.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/parsing
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Fri Apr 21 12:09:47 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 16:18:54 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"lemin.h"

static void	my_swap_room(t_room **a, t_room **b, int start_end)
{
  t_room	*tmp;

  if (start_end != 0)
    return ;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

static void	change_type_name(t_room **room, int start_end)
{
  int		i;
  int		name;

  i = 0;
  name = 0;
  if (start_end != 0)
    return ;
  while (room[i] != NULL)
    {
      if (room[i]->type != 0 && name == 0)
	name += 2;
      if (room[i]->type != 1 && name == 1)
	name += 2;
      room[i]->new_name = name;
      name++;
      i++;
    }
}

void		my_sort_room(t_room **room, int start_end)
{
  int		i;

  i = 0;
  if (start_end != 0)
    return ;
  if (room == NULL)
    return ;
  while (room[i] != NULL)
    {
      if (room[i + 1] != NULL)
	{
	  if (room[i]->type > room[i + 1]->type)
	    {
	      my_swap_room(&room[i], &room[i + 1], start_end);
	      i = 0;
	    }
	  else
	    i++;
	}
      else
	i++;
    }
  change_type_name(room, start_end);
}
