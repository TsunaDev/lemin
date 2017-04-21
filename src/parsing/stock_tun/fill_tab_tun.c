/*
** fill_tab_tun.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Fri Apr 21 19:20:12 2017 Anaïs Breant
** Last update Fri Apr 21 19:40:30 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"lemin.h"
#include	"my_string.h"

static int	*fill_with_arr(char *str, int *tun, t_room **room)
{
  int		cpt_tun;
  int		cpt_room;
  int		cpt_tab;
  int		return_value;
  char		**tab;

  cpt_tab = 0;
  cpt_tun = 0;
  tab = my_strnchar_to_wordtab(str, '-');
  while (tab[cpt_tab] != NULL)
    {
      cpt_room = 0;
      while (room[cpt_room] != NULL)
	{
	  return_value = my_strcmp(tab[cpt_tab], room[cpt_room]->name);
	  if (return_value == 0)
	    {
	      tun[cpt_tun] = room[cpt_room]->new_name;
	      cpt_tun++;
	    }
	  cpt_room++;
	}
      cpt_tab++;
    }
  return (tun);
}

void		fill_tab_tun(char **arr, int **tun, int cpt_arr, t_room **room)
{
  int		cpt_tun;

  cpt_tun = 1;
  while (arr[cpt_arr] != NULL)
    {
      if (arr[cpt_arr][0] != '\0')
	{
	  tun[cpt_tun] = fill_with_arr(arr[cpt_arr], tun[cpt_tun], room);
	  cpt_tun++;
	}
      cpt_arr++;
    }
}
