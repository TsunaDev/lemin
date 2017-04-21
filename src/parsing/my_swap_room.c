/*
** my_swap_room.c for my_swap_room.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/parsing
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Fri Apr 21 12:09:47 2017 Glenn Gabriel Irakiza
** Last update Fri Apr 21 12:58:38 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"lemin.h"

static void	my_swap_room(t_room **a, t_room **b)
{
  t_room	*tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void		my_sort_room(t_room **room)
{
  int		i;

  i = 0;
  if (room == NULL)
    return ;
  while (room[i] != NULL)
    {
      if (room[i + 1] != NULL)
	{
	  if (room[i]->type > room[i + 1]->type)
	    {
	      my_swap_room(&room[i], &room[i + 1]);
	      i = 0;
	    }
	  else
	    i++;
	}
      else
	i++;
    }
}
