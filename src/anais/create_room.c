/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 19:03:34 2017 Anaïs Breant
*/

#include	"my_string.h"
#include	"lemin.h"

static void	my_pos_room(int start, int i, char *str, t_room *room)
{
  char		*tmp;

  while (str[i] != ' ' && str[i] != '\0')
    i++;
  tmp = my_strndup_end(str, start, i);
  room->x = my_getnbr(tmp);
  free(tmp);
  i++;
  start = i;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  tmp = my_strndup_end(str, start, i);
  room->y = my_getnbr(tmp);
  free(tmp);
}

static t_room	*my_init_room(char *str, int type)
{
  t_room	*room;
  int		i;

  i = 0;
  room = malloc(sizeof(t_room));
  if (room == NULL)
    return (NULL);
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  room->name = my_strndup_end(str, 0, i);
  i++;
  my_pos_room(i, i, str, room);
  room->type = type;
  return (room);
}

t_room		**my_recup_room(char **arr)
{
  t_room	**room;
  int		size;
  int		nb_words;
  int		cmp;
  int		i;
  int		y;

  y = 1;
  i = 0;
  size = nb_room(arr) + 1;
  room = malloc(sizeof(t_room *) * size);
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words(arr[y]);
      cmp = my_strcmp("##start", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  room[i] = my_init_room(arr[y], 0);
	  i++;
	}
      cmp = my_strcmp("##end", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  room[i] = my_init_room(arr[y], 2);
	  i++;
	}
      if (nb_words == 3)
	{
	  room[i] = my_init_room(arr[y], 1);
	  i++;
	}
      y++;
    }
  room[i] = NULL;
  return (room);
}
