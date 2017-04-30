/*
** pathfinding.h for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 20:43:46 2017 LaFleche
** Last update Sun Apr 30 04:35:22 2017 LaFleche
*/

#ifndef PATHFINDING_H_
# define PATHFINDING_H_

typedef struct  s_node
{
  int           *path;
  struct s_node *next;
  struct s_node *prev;
}               t_node;

typedef struct  s_list
{
  t_node        *head;
  t_node        *tail;
}               t_list;

typedef struct  s_pathf
{
  int		nb_rooms;
  int		nb_pipes;
  int		new_pipe;
  int		limit;
  double	*combination;
  int		**tools;
  int		**final_path;
}               t_pathf;

void		free_linked_list(t_list *);
int             add_node_beginning(t_list *, int);
int             add_node_end(t_list *, int);
int             del_last_node(t_list *);
int		find_all_path(t_pathf *);
int		good_path(t_list *, int, t_pathf *, t_list *);
int		my_push_to_list_all_path(t_list *, t_list *);
int		int_cmp(int *, int);
int		int_tab_cmp(int *, int *);
int		tab_intlen(int *);
int		get_tab_combination(t_list *, t_pathf *);
int		find_my_unique_path(t_list *, t_pathf *);
int		first_step(t_list *, t_list *, t_pathf *);
int		pathfinding(int **, int, int, int ***);
int		*init_tab(int *, int);
int		*my_cp_tab(int *, int *);

#endif /* !PATHFINDING_H_ */
