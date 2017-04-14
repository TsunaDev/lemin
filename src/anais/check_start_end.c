/*
** check_start_end.c for Lem_in$ in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:37:11 2017 Anaïs Breant
** Last update Wed Apr 12 19:51:42 2017 Anaïs Breant
*/

#include	<unistd.h>
#include	"my_string.h"

static int	start_end(char **arr, char *to_compare)
{
  int		cpt;
  int		nbr_compare;
  int		return_value;

  cpt = 0;
  nbr_compare = 0;
  while (arr[cpt] != NULL)
    {
      return_value = my_strcmp(arr[cpt], to_compare);
      if (return_value == 0)
	nbr_compare++;
      cpt++;
    }
  return(nbr_compare);
}

int		check_start_end(char **arr)
{
  int		cpt_start;
  int		cpt_end;

  cpt_start = start_end(arr, "##start");
  cpt_end = start_end(arr, "##end");
  if (cpt_start != 1 || cpt_end != 1)
    {
      my_putstr(2, "You need one '##start' and one '##end'\n");
      return (-1);
    }
  return (0);
}
