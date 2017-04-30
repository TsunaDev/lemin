/*
** display_arr.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 19 16:06:54 2017 Anaïs Breant
** Last update Sun Apr 30 20:17:36 2017 Glenn Gabriel Irakiza
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
  int		cmp[2];
  int		cpt;

  cpt = 0;
  nbr_space = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] == ' ')
	nbr_space++;
      cpt++;
    }
  cmp[0] = my_strcmp(str, "##start");
  cmp[1] = my_strcmp(str, "##end");
  if ((nbr_space == 2 && cpt_room == 0) || cmp[0] == 0 || cmp[1] == 0)
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
  cpt = 0;
  my_putstr(1, "#number_of_ants\n");
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
