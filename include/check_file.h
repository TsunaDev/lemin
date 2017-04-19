/*
** check_file.h for check_file.h in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/include
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:45:19 2017 Anaïs Breant
** Last update Wed Apr 19 21:49:36 2017 Anaïs Breant
*/

#ifndef	CHECK_FILE_H_
# define CHECK_FILE_H_

# include	"lemin.h"

void	display_arr(char **);
char	**check_start_end(char **);
char	**check_file(char **);
int	check_nbr_ants(char *);
char	**skip_bad_line(char **);
char	*epur_str_check(char *);
char	**check_nbr_room(t_room **, char **);
int	my_valid_file(char **);
void	my_stranger(char **);

#endif /* !CHECK_FILE_H_ */
