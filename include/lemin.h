/*
** lemin.h for lemin.h in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/include
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:25:21 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 16:11:13 2017 Martin Van Elslande
*/

#ifndef			LEMIN_H_
# define		LEMIN_H_

typedef struct		s_room
{
  char			*name;
  int			type;
  int			new_name;
  int			x;
  int			y;
  int			full;
}			t_room;

typedef struct		s_state
{
  int			*ant_room;
  int			*prev_idx;
  int			remaining;
  int			next;
  int			idx;
}			t_state;

void			my_sort_room(t_room **);
void			suppr_double_tun(char **);
void			my_free_room(t_room **);
int			my_create_room(t_room **, char **);

char			**open_file(int);
int			my_pars(char **);
int			nb_room(char **);
int			display_shell(int **, t_room **, int);

int			next_room(int, int *);
int			init_state(t_state *, int);
int			get_actual_room(int, t_room **);

#endif			/* !LEMIN_H_ */
