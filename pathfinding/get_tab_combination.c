/*
** get_tab_combination.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Mon Apr 24 09:42:34 2017 LaFleche
** Last update Wed Apr 26 17:07:08 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

int   **print_comb_tab(t_node *tmp, int *src, int nb_unique_path, int **path_comb)
{
  int           x;

  x = 1;
  path_comb[x] = tmp->path;
  x++;
  while (tmp != NULL && x != (nb_unique_path + 1))
    {
      if (int_tab_cmp(src, tmp->path) == 0)
	{
	  path_comb[x] = tmp->path;
	  x++;
	}
      tmp = tmp->next;
    }
  return (path_comb);
}

int   **find_my_combination(t_list *all_path, int nb_unique_path, int **path_comb, int x)
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
  return (print_comb_tab(tmp, tmp->path, nb_unique_path, path_comb));
}

int		**get_tab_combination(double *combination, t_list *all_path)
{
  int		**path_comb;

  path_comb = malloc(sizeof(int *) * ((int)combination[2] + 1));
  if (path_comb == NULL)
    return (NULL);
  path_comb[0] = malloc(sizeof(int));
  if (path_comb[0] == NULL)
    return (NULL);
  path_comb[0][0] = (int)combination[2];
  return (find_my_combination(all_path, (int)combination[2], path_comb, (int)combination[0]));
}
