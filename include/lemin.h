/*
** lemin.h for lemin.h in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/include
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:25:21 2017 Glenn Gabriel Irakiza
** Last update Tue Apr 25 16:31:13 2017 Glenn Gabriel Irakiza
*/

#ifndef	LEMIN_H_
# define LEMIN_H_

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
void			my_free_room(t_room **);
int			my_create_room(t_room **, char **);

char			**open_file(int);
int			my_pars(char **);
int			nb_room(char **);

/*
** fonction à supprimer avant le rendu
*/
void			my_show_room(t_room **);

# endif	/* !LEMIN_H_ */
