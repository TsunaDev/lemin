/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Fri Apr 21 12:13:11 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"
#include	"lemin.h"

void		my_free_room(t_room **arr)
{
  int		i;

  i = 0;
  if (arr == NULL)
    return ;
  while (arr[i] != NULL)
    {
      free(arr[i]->name);
      free(arr[i]);
      i++;
    }
  free(arr);
}

void		my_show_room(t_room **room)
{
  int		i;

  i = 0;
  while (room[i] != NULL)
    {
      printf("%s : %d - %d - %d\n", room[i]->name, room[i]->x,
	     room[i]->y, room[i]->type);
      i++;
    }
}

int		nb_room(char **arr)
{
  int		nb_words;
  int		cmp[2];
  int		i;
  int		y;

  y = 1;
  i = 0;
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words(arr[y]);
      cmp[0] = my_strcmp("##start", arr[y]);
      cmp[1] = my_strcmp("##end", arr[y]);
      if (cmp[0] == 0 || cmp[1] == 0)
	{
	  y++;
	  i++;
	}
      if (nb_words == 3)
	i++;
      y++;
    }
  return (i);
}
