/*
** my_linked_list_ft.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 20:49:30 2017 LaFleche
** Last update Sun Apr 30 04:18:46 2017 LaFleche
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
      free(list->tail);
      list->tail = tmp;
      list->tail->next = NULL;
    }
  return (0);
}

static int	add_node_to_all_path(t_list *all_path)
{
  t_node	*new_node;
  t_node	*tmp;

  new_node = malloc(sizeof(*new_node));
  if (new_node == NULL)
    return (84);
  new_node->next = NULL;
  if (all_path->head == NULL)
    {
      all_path->head = new_node;
      all_path->tail = new_node;
      new_node->prev = NULL;
    }
  else
    {
      tmp = all_path->tail;
      new_node->prev = all_path->tail;
      all_path->tail = new_node;
      tmp->next = all_path->tail;
    }
  return (0);
}

int		my_push_to_list_all_path(t_list *list, t_list *all_path)
{
  int		ret;

  ret = add_node_to_all_path(all_path);
  if (ret == 84)
    return (84);
  all_path->tail->path = list->tail->path;
  del_last_node(list);
  return (0);
}

int		add_node_end(t_list *list, int length)
{
  t_node        *new_node;
  t_node        *tmp;

  new_node = malloc(sizeof(*new_node));
  if (new_node == NULL)
    return (84);
  new_node->path = init_tab(new_node->path, length);
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
