/*
** get_tab_combination.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Mon Apr 24 09:42:34 2017 LaFleche
** Last update Sat Apr 29 20:36:01 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

/*static void	clean_tab(int *tab, int length)
{
  int           i;

  i = 0;
  while (i != length)
    {
      tab[i] = -1;
      i++;
    }
    }*/

int   **print_comb_tab(t_node *tmp, int *src, int nb_unique_path, int **path_comb)
{
  int           x;

  x = 1;
  path_comb[x] = tmp->path;
  //path_comb[x] = my_cp_tab(tmp->path, path_comb[x]);
  x++;
  while (tmp != NULL)
    {
      if (int_tab_cmp(src, tmp->path) == 0)
	{
	  path_comb[x] = tmp->path;
	  //path_comb[x] = my_cp_tab(tmp->path, path_comb[x]);
	  x++;
	  if  (x != (nb_unique_path + 1))
	    return (path_comb);
	}
      tmp = tmp->next;
    }
  //path_comb[x + 1] = NULL;
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

int		**get_tab_combination(double *combination, t_list *all_path, t_pathf *pathf)
{
  int		**path_comb;
  int		i;

  i = 1;
  //  printf("--------------<<<<<<<<<<<<<<<<<<<<<<<<< %d\n", ((int)combination[2]));
  path_comb = malloc(sizeof(int *) * ((int)combination[2] + 3));
  if (path_comb == NULL)
    return (NULL);
  path_comb[0] = malloc(sizeof(int));
  if (path_comb[0] == NULL)
    return (NULL);
  path_comb[0][0] = (int)combination[2];

  while (i != ((int)combination[2] + 3))
    {
      path_comb[i] = NULL;
      i++;
    }

  /*  while (i != (int)combination[2] + 1)
    {
      path_comb[i] = malloc(sizeof(int) * (pathf->nb_pipes * pathf->nb_rooms + 2));
      if (path_comb[i] == NULL)
        return (NULL);
      clean_tab(path_comb[i], (pathf->nb_pipes * pathf->nb_rooms + 2));
      i++;
      }*/
  return (find_my_combination(all_path, (int)combination[2], path_comb, (int)combination[0]));
}
