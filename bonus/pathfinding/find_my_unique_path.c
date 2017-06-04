/*
** find_my_unique_path.c for Lemin in /home/lafleche/norm/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sun Apr 30 03:53:28 2017 LaFleche
** Last update Sun Apr 30 04:12:11 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

static double	*my_cmp(double *cmp, double new_cmp0, double new_cmp1, int i)
{
  double        best_speed;
  double        speed;

  if (cmp[2] != 0 && new_cmp1 != 0)
    {
      best_speed = cmp[1] / cmp[2];
      speed = new_cmp0 / new_cmp1;
      if (best_speed > speed)
	{
	  cmp[0] = i;
	  cmp[1] = new_cmp0;
	  cmp[2] = new_cmp1;
	  return (cmp);
	}
    }
  return (cmp);
}

static double	*find(t_node *tmp, int *src, t_pathf *pathf, int i)
{
  double        new_cmp[2];
  int           x;
  int           nb_unique_path;

  nb_unique_path = (tab_intlen(pathf->tools[0]) >=
		    tab_intlen(pathf->tools[1])) ?
    (tab_intlen(pathf->tools[1])) : (tab_intlen(pathf->tools[0]));
  x = 1;
  new_cmp[0] = (double)tab_intlen(src);
  new_cmp[1] = 1.0;
  while (tmp != NULL)
    {
      if (0 == int_tab_cmp(src, tmp->path))
	{
	  new_cmp[0] += (double)tab_intlen(tmp->path);
	  new_cmp[1] += 1.0;
	  x++;
	  if (x != nb_unique_path)
	    return (my_cmp(pathf->combination, new_cmp[0], new_cmp[1], i));
	}
      tmp = tmp->next;
    }
  return (my_cmp(pathf->combination, new_cmp[0], new_cmp[1], i));
}

int		find_my_unique_path(t_list *all_path, t_pathf *pathf)
{
  t_node        *tmp;
  int           i;

  i = 0;
  pathf->combination = malloc(sizeof(double) * 3);
  if (pathf->combination == NULL)
    return (84);
  pathf->combination[0] = 0.0;
  pathf->combination[1] = 1000000.0;
  pathf->combination[2] = 10.0;
  tmp = all_path->head;
  while (tmp != NULL)
    {
      pathf->combination = find(tmp, tmp->path, pathf, i);
      i++;
      tmp = tmp->next;
    }
  return (0);
}
