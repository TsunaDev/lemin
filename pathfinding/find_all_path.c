/*
** find_all_path.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 19:19:26 2017 LaFleche
** Last update Sun Apr 30 04:10:31 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

int	good_path(t_list *list, int i, t_pathf *pathf, t_list *all_path)
{
  pathf->limit++;
  if (pathf->limit >= 11)
    return (1);
  if (i != 0)
    {
      i++;
      list->tail->path[i] = 1;
    }
  if (84 == my_push_to_list_all_path(list, all_path))
    return (84);
  return (0);
}

static int	add_a_room(int *src, t_list *list, t_pathf *pathf,
			   t_list *all_path)
{
  int           i;
  int           x;

  i = 0;
  if (int_cmp(src, pathf->new_pipe) == 0)
    return (del_last_node(list));
  while (src[i] != -1)
    {
      list->tail->path[i] = src[i];
      i++;
    }
  list->tail->path[i] = pathf->new_pipe;
  x = 0;
  while (pathf->tools[1][x] != -1)
    {
      if (pathf->tools[1][x] == pathf->new_pipe)
	return (good_path(list, i, pathf, all_path));
      x++;
    }
  return (0);
}

static int	next_steps(t_list *list, t_list *all_path, t_pathf *pathf)
{
  t_node        *tmp;
  int		i;
  int		x;
  int		ret;

  tmp = list->head;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->path[i + 1] != -1)
	i++;
      x = 0;
      while (pathf->tools[tmp->path[i]][x] != -1)
	{
	  if (84 == add_node_end(list, (pathf->nb_pipes * pathf->nb_rooms + 2)))
	    return (84);
	  pathf->new_pipe = pathf->tools[tmp->path[i]][x];
	  ret = add_a_room(tmp->path, list, pathf, all_path);
	  if (ret == 1 || ret == 84)
	    return (ret);
	  x++;
	}
      tmp = tmp->next;
    }
  return (0);
}

static int	lets_find_all_path(t_list *list, t_list *all_path, t_pathf *pathf)
{
  int		ret;

  ret = first_step(list, all_path, pathf);
  if (ret == 84)
    return (84);
  if (ret != 1)
    {
      ret = next_steps(list, all_path, pathf);
      if (ret == 84)
	return (ret);
      if (all_path->head == NULL)
	return (-1);
    }
  find_my_unique_path(all_path, pathf);
  if (pathf->combination == NULL)
    return (84);
  return (0);
}

int		find_all_path(t_pathf *pathf)
{
  t_list	*list;
  t_list	*all_path;
  int		ret;

  list = malloc(sizeof(*list));
  if (list == NULL)
    return (84);
  list->head = NULL;
  list->tail = NULL;
  all_path = malloc(sizeof(*list));
  if (all_path == NULL)
    return (84);
  all_path->head = NULL;
  all_path->tail = NULL;
  ret = lets_find_all_path(list, all_path, pathf);
  if (ret != 0)
    return (ret);
  if (84 == get_tab_combination(all_path, pathf))
    return (84);
  return (0);
}
