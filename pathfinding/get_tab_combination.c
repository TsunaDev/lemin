/*
** get_tab_combination.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Mon Apr 24 09:42:34 2017 LaFleche
** Last update Sun Apr 30 01:40:09 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

int		print_comb_tab(t_node *tmp, int *src, t_pathf *pathf)
{
  int		x;

  x = 1;
  pathf->final_path[x] = tmp->path;
  x++;
  while (tmp != NULL)
    {
      if (int_tab_cmp(src, tmp->path) == 0)
	{
	  pathf->final_path[x] = tmp->path;
	  x++;
	  if (x != (pathf->final_path[0][0] + 1))
	    return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		find_my_combination(t_list *all_path, t_pathf *pathf, int x)
{
  t_node        *tmp;
  int		i;

  i = 0;
  tmp = all_path->head;
  while (i != x)
    {
      i++;
      tmp = tmp->next;
    }
  print_comb_tab(tmp, tmp->path, pathf);
  return (0);
}

int		get_tab_combination(t_list *all_path, t_pathf *pathf)
{
  int		i;

  i = 1;
  pathf->final_path = malloc(sizeof(int *) * ((int)pathf->combination[2] + 3));
  if (pathf->final_path == NULL)
    return (84);
  pathf->final_path[0] = malloc(sizeof(int));
  if (pathf->final_path[0] == NULL)
    return (84);
  pathf->final_path[0][0] = (int)pathf->combination[2];
  while (i != ((int)pathf->combination[2] + 3))
    {
      pathf->final_path[i] = NULL;
      i++;
    }
  find_my_combination(all_path, pathf, (int)pathf->combination[0]);
  i = 1;
  while (pathf->final_path[i] != NULL)
    i++;
  pathf->final_path[0][0] = i - 1;
  return (0);
}
