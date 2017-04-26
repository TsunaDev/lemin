/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 26 09:19:15 2017 Martin Van Elslande
*/

#include	"stock_tun.h"
#include	"lemin.h"
#include	"check_file.h"
#include	"my_string.h"

/*
** Toujours afficher même si le nbr fourmis n'est pas bon
** check si on doit skip ou arrêter la ligne pour le nbr de fourmis
** pas bon
*/

static void	diplay_tun(int **tab)
{
  int		cpt;

  cpt = 1;
  printf("%d\n", tab[0][0]);
  while (cpt <= tab[0][0])
    {
      printf("%d", tab[cpt][0]);
      printf("%d\n", tab[cpt][1]);
      cpt++;
    }
}

int		my_pars(char **arr)
{
  int		nbr_ants;
  t_room	**room;
  int		**tab_tun;
  int		size;
  int		**paths;

  nbr_ants = check_file(arr);
  if (nbr_ants == -1)
    return (1);
  arr = skip_bad_line(arr);
  my_valid_file(arr);
  size = nb_room(arr) + 1;
  room = malloc(sizeof(t_room *) * size);
  if (room == NULL || arr == NULL)
    return (84);
  my_create_room(room, arr);
  my_sort_room(room);
  arr = check_nbr_room(room, arr);
  display_arr(arr);
  tab_tun = create_tab_int(room, arr);
  diplay_tun(tab_tun);
  paths = pathfinding();
  display_shell(paths, room, nbr_ants);
  return (0);
}
