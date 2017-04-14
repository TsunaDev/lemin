/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Fri Apr 14 08:32:07 2017 Glenn Gabriel Irakiza
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

static t_room	*my_init_free_room(char *str, int cmp, int opt, t_room **arr)
{
  t_room	*room;
  int		i;

  i = 0;
  if (opt == 0)
    {
      room = malloc(sizeof(t_room));
      if (room == NULL)
	return (NULL);
      while (str[i] != ' ' && str[i] != '\0')
	i++;
      room->name = my_strndup_end(str, 0, i);
      i++;
      my_pos_room(i, i, str, room);
      room->type = cmp;
      return (room);
    }
  while (arr[i] != NULL)
    {
      free(arr[i]->name);
      free(arr[i]);
      i++;
    }
  free(arr);
  return (NULL);
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
  int		cmp;
  int		i;
  int		y;

  y = 1;
  i = 0;
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words(arr[y]);
      cmp = my_strcmp("##start", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  i++;
	}
      cmp = my_strcmp("##end", arr[y]);
      if (cmp == 0)
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

int		my_recup_room(char **arr)
{
  t_room	**room;
  int		nb_words;
  int		cmp;
  int		i;
  int		y;
  int		size;

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
	  room[i] = my_init_free_room(arr[y], 0, 0, NULL);
	  i++;
	}
      cmp = my_strcmp("##end", arr[y]);
      if (cmp == 0)
	{
	  y++;
	  room[i] = my_init_free_room(arr[y], 2, 0, NULL);
	  i++;
	}
      if (nb_words == 3)
	{
	  room[i] = my_init_free_room(arr[y], 1, 0, NULL);
	  i++;
	}
      y++;
    }
  room[i] = NULL;
  my_show_room(room);
  my_init_free_room(NULL, 0, 1, room);
  return (0);
}
