/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Fri Apr 21 17:06:25 2017 Glenn Gabriel Irakiza
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

static t_room	*my_init_room(char *str, int *type, int name)
{
  t_room	*room;
  int		i;

  i = 0;
  room = malloc(sizeof(t_room));
  if (room == NULL)
    return (NULL);
  room->new_name = name;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  room->name = my_strndup_end(str, 0, i);
  i++;
  my_pos_room(i, i, str, room);
  if (type == NULL)
    room->type = 2;
  else if (type[0] == 0)
    room->type = 0;
  else
    room->type = 1;
  return (room);
}

static int	skip_line_void(char **arr, int y)
{
  int		len;

  y++;
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
  int		cmp[3];
  int		y[2];

  y[0] = 0;
  y[1] = 0;
  while (arr[y[0]] != NULL)
    {
      y[0]++;
      cmp[0] = my_strcmp("##start", arr[y[0]]);
      cmp[1] = my_strcmp("##end", arr[y[0]]);
      cmp[2] = my_nb_words(arr[y[0]]);
      if ((cmp[0] == 0 || cmp[1] == 0) && arr[y[0] + 1] != NULL)
	{
	  y[0] = skip_line_void(arr, y[0]);
	  room[y[1]] = my_init_room(arr[y[0]], cmp, y[1]);
	  y[1]++;
	}
      if (cmp[2] == 3)
	{
	  room[y[1]] = my_init_room(arr[y[0]], NULL, y[1]);
	  y[1]++;
	}
    }
  room[y[1]] = NULL;
  return (0);
}
