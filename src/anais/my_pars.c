/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 12 11:42:37 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"
#include	"lemin.h"

static void	my_init_room(char *str, int cmp)
{
  t_room	*room;
  char		*nb;
  int		start;
  int		i;

  i = 0;
  start = 0;
  room = malloc(sizeof(t_room));
  if (room == NULL)
    return;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  room->name = my_strndup_end(str, 0, i);
  start = i;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  nb = my_strndup_end(str, start, i);
  printf("%s %s\n", room->name, nb);
  free(nb);
  free(room->name);
  free(room);
}

static int	my_recup_room(char **arr)
{
  int		nb_words;
  int		cmp;
  int		y;

  y = 1;
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words(arr[y]);
      cmp = my_strcmp("##start", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  my_init_room(arr[y], 0);
	}
      cmp = my_strcmp("##end", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  my_init_room(arr[y + 1], 2);
	}
      if (nb_words == 3)
	my_init_room(arr[y], 1);
      y++;
    }
  return (0);
}

int		my_pars(char **arr)
{
  int		ants;

  ants = my_getnbr(arr[0]);
  printf("%d\n", ants);
  my_recup_room(arr);
  return (0);
}
