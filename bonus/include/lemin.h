/*
** lemin.h for lemin.h in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/include
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:25:21 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 20:05:30 2017 Martin Van Elslande
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

void			my_sort_room(t_room **);
void			suppr_double_tun(char **);
void			my_free_room(t_room **);
void			my_create_room(t_room **, char **, int *);

char			**open_file(int);
int			my_pars(char **);
int			nb_room(char **);
int			display_graphical(int, t_room **, int **, int **);

int			next_room(int, int *);
int			get_actual_room(int, t_room **);

#endif			/* !LEMIN_H_ */
