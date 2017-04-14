/*
** lemin.h for lemin.h in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/include
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Mon Apr 10 14:25:21 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 12 16:15:57 2017 Glenn Gabriel Irakiza
*/

#ifndef	LEMIN_H_
# define LEMIN_H_

typedef struct		s_room
{
  char			*name;
  int			x;
  int			y;
  int			type;
}			t_room;

/*struct s_room		*connect;*/
/*struct s_room		*next;*/
/*struct s_room		*previous;*/

char			**open_file(int);
int			my_recup_room(char **);
int			my_pars(char **);

# endif	/* !LEMIN_H_ */
