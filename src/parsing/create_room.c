/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Thu Apr 20 08:56:27 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"
#include	"lemin.h"

static void	my_pos_room(int start, int i, char *str, t_room *room)
{
  char		*tmp;

  while (str[i] != '\0' && str[i] != ' ')
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

static t_room	*my_init_room(char *str, int *type)
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
  if (type == NULL)
    room->type = 1;
  else if (type[0] == 0)
    room->type = 0;
  else
    room->type = 2;
  return (room);
}

static int	skip_line_void(char **arr, int y)
{
  int		len;

  len = my_strlen(arr[y]);
  while (len == 0)
    {
      y++;
      len = my_strlen(arr[y]);
    }
  return (y);
}

int		my_create_room(t_room **room, char **arr)
{
  int		nb_words;
  int		cmp[2];
  int		i;
  int		y;

  y = 0;
  i = 0;
  while (arr[y] != NULL)
    {
      y++;
      nb_words = my_nb_words(arr[y]);
      cmp[0] = my_strcmp("##start", arr[y]);
      cmp[1] = my_strcmp("##end", arr[y]);
      if (cmp[0] == 0 || cmp[1] == 0)
	{
	  y++;
	  y = skip_line_void(arr, y);
	  room[i++] = my_init_room(arr[y], cmp);
	}
      if (nb_words == 3)
	room[i++] = my_init_room(arr[y], NULL);
    }
  room[i] = NULL;
  return (0);
}
