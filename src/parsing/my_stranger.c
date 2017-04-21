/*
** my_stranger.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/parsing
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Fri Apr 21 14:19:39 2017 Anaïs Breant
** Last update Fri Apr 21 15:41:34 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	compare_next_start_end(char **str, int *cpt_bis)
{
  int		cpt_space;
  int		cpt;

  cpt = 0;
  cpt_space = 0;
  (*cpt_bis)++;
  while (str[*cpt_bis][0] == '\0')
    (*cpt_bis)++;
  while (str[*cpt_bis][cpt] != '\0')
    {
      if (str[*cpt_bis][cpt] == ' ')
	cpt_space++;
      cpt++;
    }
  if (cpt_space != 2)
    return (1);
  return (0);
}

int		my_stranger(char **arr)
{
  int		return_value;
  int		cpt;

  cpt = 0;
  while (arr[cpt] != NULL)
    {
      return_value = my_strcmp(arr[cpt], "##start");
      if (return_value == 0)
	{
	  return_value = compare_next_start_end(arr, &cpt);
	  if (return_value == 1)
	    arr[cpt] = NULL;
	}
      return_value = my_strcmp(arr[cpt], "##end");
      if (return_value == 0)
	{
	  return_value = compare_next_start_end(arr, &cpt);
	  if (return_value == 1)
	    arr[cpt] = NULL;
	}
      else
	cpt++;
    }
  return (0);
}
