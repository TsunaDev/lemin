/*
** get_tab_combination.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Mon Apr 24 09:42:34 2017 LaFleche
** Last update Tue Apr 25 14:20:57 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

static int   **print_comb_tab(t_list *list, t_list *all_path, t_node *tmp, int *src, int i, int nb_unique_path, int **path_comb)
{
  int           x;

  x = 1;
  path_comb[x] = src;//my_cp_tab(src, path_comb[x]);
  x++;
  while (tmp != NULL && x != (nb_unique_path + 1))
    {
      if (int_tab_cmp(src, tmp->path) == 0)
	{
	  //path_comb[x] = my_cp_tab(tmp->path, path_comb[x]);
	  path_comb[x] = tmp->path;
	  x++;
	}
      tmp = tmp->next;
    }
  return (path_comb);
}

static int   **find_my_combination(t_list *list, t_list *all_path, t_pathf *pathf, int nb_unique_path, int **path_comb, int x)
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
  return (print_comb_tab(list, all_path, tmp, tmp->path, i, nb_unique_path, path_comb));
}

int		**get_tab_combination(double *combination, t_list *list, t_list *all_path, t_pathf *pathf)
{
  int		**path_comb;
  int		i;

  i = 1;
  path_comb = malloc(sizeof(int *) * ((int)combination[2] + 1));
  if (path_comb == NULL)
    return (NULL);
  path_comb[0] = malloc(sizeof(int) * 1);
  if (path_comb[0] == NULL)
    return (NULL);
  path_comb[0][0] = (int)combination[2];
  /*while (i != (int)combination[2] + 1)
    {
      path_comb[i] = malloc(sizeof(int) * (pathf->nb_pipes * pathf->nb_rooms));
      if (path_comb[i] == NULL)
	return (NULL);
      i++;
      }*/
  return (find_my_combination(list, all_path, pathf, (int)combination[2], path_comb, (int)combination[0]));
}
