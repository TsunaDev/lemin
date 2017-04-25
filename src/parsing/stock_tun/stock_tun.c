/*
** stock_tun.c for stock_tun.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/parsing/stock_tun
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Fri Apr 21 18:58:58 2017 Anaïs Breant
** Last update Tue Apr 25 14:10:32 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"stock_tun.h"
#include	"check_file.h"
#include	"lemin.h"

static int	**make_malloc_tab_tun(int cpt, char **arr)
{
  int		**tab_tun;
  int		tmp;

  tmp = 0;
  while (arr[cpt] != NULL)
    {
      if (arr[cpt][0] != '\0')
	tmp++;
      cpt++;
    }
  tab_tun = malloc(sizeof(int *) * (tmp + 1));
  if (tab_tun == NULL)
    return (NULL);
  cpt = 0;
  while (cpt <= tmp)
    {
      tab_tun[cpt] = malloc(sizeof(int) * 2);
      if (tab_tun[cpt] == NULL)
	return (NULL);
      cpt++;
    }
  tab_tun[0][0] = tmp;
  return (tab_tun);
}

static int	**make_just_one_line()
{
  int		**tab_empty;

  tab_empty = malloc(sizeof(int *) * 1);
  if (tab_empty == NULL)
    return (NULL);
  tab_empty[0] = malloc(sizeof(int) * 1);
  if (tab_empty[0] == NULL)
    return (NULL);
  tab_empty[0][0] = 0;
  return (tab_empty);
}

int		**create_tab_int(t_room **room, char **arr)
{
  int		**tab_tun;
  int		cpt_hyphen;

  cpt_hyphen = find_nbr_tunnel(arr);
  if (cpt_hyphen == -1)
    tab_tun = make_just_one_line();
  else
    {
      tab_tun = make_malloc_tab_tun(cpt_hyphen, arr);
      fill_tab_tun(arr, tab_tun, cpt_hyphen, room);
    }
  return (tab_tun);
}
