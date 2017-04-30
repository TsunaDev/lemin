/*
** first_step.c for Lemin in /home/lafleche/norm/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sun Apr 30 03:59:59 2017 LaFleche
** Last update Sun Apr 30 04:04:51 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

static int	prep_new_path(t_list *list, t_pathf *pathf, int i)
{
  if (84 == add_node_end(list, (pathf->nb_rooms * pathf->nb_pipes + 2)))
    return (84);
  list->tail->path[0] = 0;
  list->tail->path[1] = pathf->tools[0][i];
  return (0);
}

static int	find_short_path(t_list *list, t_list *all_path, t_pathf *pathf)
{
  int		x;
  int		next;
  int		ret;

  x = 0;
  next = 0;
  while (pathf->tools[1][x] != -1 && next == 0)
    {
      if (pathf->tools[1][x] == list->tail->path[1])
	{
	  list->tail->path[2] = 1;
	  ret = good_path(list, 0, pathf, all_path);
	  if (ret != 0)
	    return (ret);
	  next++;
	}
      x++;
    }
  return (0);
}

int		first_step(t_list *list, t_list *all_path, t_pathf *pathf)
{
  int		i;
  int		ret;

  i = 0;
  while (pathf->tools[0][i] != -1)
    {
      if (84 == prep_new_path(list, pathf, i))
	return (84);
      if (pathf->tools[0][i] == 1)
	return (good_path(list, 0, pathf, all_path));
      ret = find_short_path(list, all_path, pathf);
      if (ret != 0)
	return (ret);
      i++;
    }
  return (0);
}
