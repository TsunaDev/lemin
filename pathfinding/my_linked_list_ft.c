/*
** my_linked_list_ft.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 20:49:30 2017 LaFleche
** Last update Wed Apr 26 16:58:24 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

void		free_linked_list(t_list *list)
{
  t_node        *tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      tmp = list->head->next;
      free(list->head->path);
      free(list->head);
      list->head = tmp;
    }
  list->head = NULL;
  list->tail = NULL;
}

int		del_last_node(t_list *list)
{
  t_node	*tmp;

  if (list->head == list->tail)
    {
      free(list->head);
      list->head = NULL;
      list->tail = NULL;
    }
  else
    {
      tmp = list->tail->prev;
      //if (opt == 0)
      //free(list->tail->path);
      //free(list->tail);
      list->tail = tmp;
      list->tail->next = NULL;
    }
  return (0);
}

int		my_push_to_list_all_path(t_list *list, t_list *all_path, int length)
{
  int		ret;

  ret = add_node_end(all_path, length);
  if (ret == 84)
    return (84);
  free(all_path->tail->path);
  all_path->tail->path = list->tail->path;
  del_last_node(list);
  return (0);
}

static int	*init_tab(int length)
{
  int		i;
  int		*tab;

  i = 0;
  tab = malloc(sizeof(int) * (length));
  if (tab == NULL)
    return (NULL);
  while (i != length)
    {
      tab[i] = -1;
      i++;
    }
  return (tab);
}

int             add_node_beginning(t_list *list, int length)
{
  t_node        *new_node;
  t_node        *tmp;

  new_node = malloc(sizeof(*new_node));
  if (new_node == NULL)
    return (84);
  new_node->path = init_tab(length);
  if (new_node->path == NULL)
    return (84);
  new_node->prev = NULL;
  if (list->head == NULL)
    {
      list->head = new_node;
      list->tail = new_node;
      new_node->prev = NULL;
    }
  else
    {
      tmp = list->head;
      new_node->next = list->head;
      list->head = new_node;
      tmp->prev= list->head;
    }
  return (0);
}

int             add_node_end(t_list *list, int length)
{
  t_node        *new_node;
  t_node        *tmp;

  new_node = malloc(sizeof(*new_node));
  if (new_node == NULL)
    return (84);
  new_node->path = init_tab(length);
  if (new_node->path == NULL)
    return (84);  
  new_node->next = NULL;
  if (list->head == NULL)
    {
      list->head = new_node;
      list->tail = new_node;
      new_node->prev = NULL;
    }
  else
    {
      tmp = list->tail;
      new_node->prev = list->tail;
      list->tail = new_node;
      tmp->next = list->tail;
    }
  return (0);
}
