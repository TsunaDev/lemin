/*
** check_room.c for check_room.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:57:42 2017 Anaïs Breant
** Last update Wed Apr 19 20:33:49 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"my_string.h"
#include	"lemin.h"

static int	check_str(char *str)
{
  int		nbr_hyphen;
  int		cpt;

  cpt = 0;
  nbr_hyphen = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] == '-')
	nbr_hyphen++;
      cpt++;
    }
  if (nbr_hyphen == 1)
    return (1);
  return (0);
}

static int	find_nbr_tunnel(char **arr)
{
  int		return_value;
  int		cpt;

  cpt = 0;
  while (arr[cpt] != NULL)
    {
      return_value = check_str(arr[cpt]);
      if (return_value == 1)
	return (cpt);
      cpt++;
    }
  return (-1);
}

static int	check_nbr_room_bis(char *str, t_room **room)
{
  char		**tab;
  int		return_value;
  int		cpt_tab;
  int		cpt_room;

  cpt_tab = 0;
  tab = my_str_to_wordtab_hyphen(str);
  while (tab[cpt_tab] != NULL)
    {
      cpt_room = 0;
      while (room[cpt_room] != NULL)
	{
	  return_value = my_strcmp(tab[cpt_tab], room[cpt_room]->name);
	  if (return_value == 0)
	    return (1);
	  cpt_room++;
	}
      cpt_tab++;
    }
  return (0);
}

char		**check_nbr_room(t_room **room, char **arr)
{
  int		return_value;
  int		cpt;
  int		cpt_tunnel;

  cpt = 0;
  cpt_tunnel = find_nbr_tunnel(arr);
  if (cpt_tunnel == -1)
    return (arr);
  while (arr[cpt_tunnel] != NULL)
    {
      return_value = check_nbr_room_bis(arr[cpt], room);
      if (return_value == 1)
	{
	  arr[cpt_tunnel] = NULL;
	  return (arr);
	}
    }
  return (arr);
}
