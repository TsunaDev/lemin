/*
** find_all_path.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 19:19:26 2017 LaFleche
** Last update Sat Apr 29 15:53:04 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

void		display_tab(int *tab)
{
  int		i = 0;

  printf("---\n");
  while (tab[i] != -1)
    {
      printf("%d ", tab[i]);
      i++;
    }
  printf("---\n");
}

void            my_display_list(t_node *head)
{
  t_node        *tmp;
  int		i;

  tmp = head;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->path[i] != -1)
	{
	  printf("%d ", tmp->path[i]);
	  i++;
	}
      printf("\n");
      tmp = tmp->next;
    }
}

static int	good_path(t_list *list, int i, int length, t_list *all_path)
{
  static int	limit = 0;

  limit++;
  printf("limit : %d -------\n", limit);
  if (limit == 11)
    return (1);
  if (i != 0)
    {
      i++;
      list->tail->path[i] = 1;
    }
  printf("****\n");
  display_tab(list->tail->path);
   printf("****\n");
  if (84 == my_push_to_list_all_path(list, all_path, length))//////// segfault
    return (84);
  //printf("HI\n");
  display_tab(all_path->tail->path);
  return (0);
}

static int	cp_path_and_add_one_pipe(int *src, t_list *list, t_pathf *pathf, int new_pipe, t_list *all_path)
{
  int		i;
  int		x;

  i = 0;
  if (int_cmp(src, new_pipe) == 0)
    return (del_last_node(list));
  while (src[i] != -1)
    {
      list->tail->path[i] = src[i];
      i++;
    }
  list->tail->path[i] = new_pipe;
  x = 0;
  while (pathf->tools[1][x] != -1)
    {
      if (pathf->tools[1][x] == new_pipe)
	return (good_path(list, i, (pathf->nb_pipes * pathf->nb_rooms + 2), all_path));
      x++;
    }
  return (0);
}

static int	first_step(t_list *list, t_list *all_path, t_pathf *pathf, int i)
{
  //  int		i;
  int		x, yolo;

  // i = 0;
  while (pathf->tools[0][i] != -1)
    {
      if (84 == add_node_end(list, (pathf->nb_rooms * pathf->nb_pipes + 2)))
	return (84);
      list->tail->path[0] = 0;
      list->tail->path[1] = pathf->tools[0][i];
      //printf("(%d   %d)\n", list->tail->path[0], list->tail->path[1]);
      x = 0;
      yolo = 0;
      while (pathf->tools[1][x] != -1 && yolo == 0)
	{
	  // printf("couucou\n");
	  if (pathf->tools[1][x] == list->tail->path[1])//// j'ai del node
	    {
	      //  printf("hello\n");
	      list->tail->path[2] = 1;
	      //my_display_list(list->head);
	      //display_tab(list->tail->path);
		/*display_tab(pathf->tools[0]);
		  display_tab(pathf->tools[1]);*/
	      //exit(0);
	      
	      if (1 == good_path(list, 0, (pathf->nb_pipes * pathf->nb_rooms + 2), all_path))
		return (1);
	      yolo++;
	    }
	  x++;
	}
      if (pathf->tools[0][i] == 1)
	if (1 == good_path(list, 0, (pathf->nb_pipes * pathf->nb_rooms + 2), all_path))
	return (1);
      i++;
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
  while (tmp != NULL) //// on parcour tout notre liste chainé (peut elle s'agrandir en live ? espérons)
    {
      i = 0;
      while (tmp->path[i + 1] != -1) /// je veux ê à la dernière valeur de mon path
	i++;
      x = 0;
      while (pathf->tools[tmp->path[i]][x] != -1) // je veux créé une new node pour tout les chemins ouvert à moi
	{
	  if (84 == add_node_end(list, (pathf->nb_pipes * pathf->nb_rooms + 2)))// j'ai changé nb_rooms pour nb_pipes
	    return (84);
	  ret =  cp_path_and_add_one_pipe(tmp->path, list, pathf, pathf->tools[tmp->path[i]][x], all_path);
	  if (ret == 1 || ret == 84)
	    return (ret);
	  x++;
	}
      tmp = tmp->next;
    }
  if (all_path->head == NULL)
    exit(0); ////////////////// pas de chemin vers la sortie
  return (0);
}

static double	*my_cmp(double *cmp, double new_cmp0, double new_cmp1, int i)
{
  double	best_speed;
  double	speed;

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

static double	*find(t_node *tmp, int *src, double *cmp, int i, int nb_unique_path)
{
  double	new_cmp[2];
  int		x, pass;

  x = 1;
  new_cmp[0] = (double)tab_intlen(src);
  new_cmp[1] = 1.0;
  while (tmp != NULL)
    {
      //printf("-> ");
      //display_tab(src);printf("\n | "); display_tab(tmp->path);printf(" <-\n");
      if (0 == (pass = int_tab_cmp(src, tmp->path)))
	{
	  new_cmp[0] += (double)tab_intlen(tmp->path);
	  new_cmp[1] += 1.0;
	  x++;
	  if (x != nb_unique_path)
	    return (my_cmp(cmp, new_cmp[0], new_cmp[1], i));
	}
      //      printf("PASS : %d\n\n", pass);	  
      tmp = tmp->next;
    }
  return (my_cmp(cmp, new_cmp[0], new_cmp[1], i));
}

static double	*find_my_unique_path(t_list *all_path, int nb_unique_path)
{
  t_node	*tmp;
  double	*cmp;
  int		i;

  i = 0;
  cmp = malloc(sizeof(double) * 3);
  if (cmp == NULL)
    return (NULL);
  cmp[0] = 0.0;
  cmp[1] = 1000000.0;
  cmp[2] = 10.0;
  tmp = all_path->head;
  while (tmp != NULL)
    {
      cmp = find(tmp, tmp->path, cmp, i, nb_unique_path);
      i++;
      tmp = tmp->next;
    }
  return (cmp);
}

static double	*lets_find_all_path(t_list *list, t_list *all_path, t_pathf *pathf)
{
  int		nb_unique_path;
  double	*cmp;

  nb_unique_path = (tab_intlen(pathf->tools[0]) >= tab_intlen(pathf->tools[1])) ?
    (tab_intlen(pathf->tools[1])) : (tab_intlen(pathf->tools[0]));
  if (1 != first_step(list, all_path, pathf, 0))
    next_steps(list, all_path, pathf);
  printf("-----------------------------\n");
  my_display_list(list->head);
  printf("-----------------------------\n");
  my_display_list(all_path->head);
  printf("-----------------------------\n");
  //free_linked_list(list);
  //  nb_unique_path = (tab_intlen(pathf->tools[0]) >= tab_intlen(pathf->tools[1])) ?
  //(tab_intlen(pathf->tools[1])) : (tab_intlen(pathf->tools[0]));
  //printf("---------------------------\n");
  cmp = find_my_unique_path(all_path, nb_unique_path);
  if (cmp == NULL)
    return (NULL);
  //printf("---------------------------\n");
  return (cmp);
}

int		**find_all_path(int **tools, int nb_rooms, int nb_pipes)
{
  t_list        *list;
  t_list        *all_path;
  t_pathf	*pathf;
  double	*combination;

  list = malloc(sizeof(*list));
  if (list == NULL)
    return (NULL);
  list->head = NULL;
  list->tail = NULL;
  all_path = malloc(sizeof(*list));
  if (all_path == NULL)
    return (NULL);
  all_path->head = NULL;
  all_path->tail = NULL;
  pathf = malloc(sizeof(*pathf));
  if (pathf == NULL)
    return (NULL);
  pathf->tools = tools;
  pathf->nb_rooms = nb_rooms;
  pathf->nb_pipes = nb_pipes;
  combination = lets_find_all_path(list, all_path, pathf);
  if (combination == NULL)
    return (NULL);
  return (get_tab_combination(combination, all_path, pathf));
}
