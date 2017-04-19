/*
** display_arr.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 19 16:06:54 2017 Anaïs Breant
** Last update Wed Apr 19 20:12:59 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	check_tunnel(char *str, int cpt_tunnel)
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
  if (nbr_hyphen == 1 && cpt_tunnel == 0)
    {
      my_putstr(1, "#tunnels\n");
      return (0);
    }
  return (1);
}

static int	check_room(char *str, int cpt_room)
{
  int		nbr_space;
  int		cpt;

  cpt = 0;
  nbr_space = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] == ' ')
	nbr_space++;
      cpt++;
    }
  if (nbr_space == 2 && cpt_room == 0)
    {
      my_putstr(1, "#rooms\n");
      return (0);
    }
  return (1);
}

void		display_arr(char **arr)
{
  int		cpt_room;
  int		cpt_tunnel;
  int		cpt;

  cpt_room = 0;
  cpt_tunnel = 0;
  cpt = 1;
  my_putstr(1, "#number_of_ants\n");
  my_putstr(1, arr[0]);
  my_putstr(1, "\n");
  while (arr[cpt] != NULL)
    {
      if (arr[cpt][0] != '\0')
	{
	  if (cpt_room == 0 && (check_room(arr[cpt], cpt_room) == 0))
	    cpt_room++;
	  if (cpt_tunnel == 0 && (check_tunnel(arr[cpt], cpt_tunnel) == 0))
	    cpt_tunnel++;
	  my_putstr(1, arr[cpt]);
	  my_putstr(1, "\n");
	}
      cpt++;
    }
  my_putstr(1, "#moves\n");
}
