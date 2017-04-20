/*
** check_start_end.c for Lem_in$ in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:37:11 2017 Anaïs Breant
** Last update Thu Apr 20 06:10:57 2017 Glenn Gabriel Irakiza
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
  return (nbr_compare);
}

static char	**delete_start_end(char **arr, char *to_delete)
{
  int		cpt;
  int		return_value;

  cpt = 0;
  return_value = my_strcmp(arr[cpt], to_delete);
  while (arr[cpt] != NULL && return_value != 0)
    {
      cpt++;
      return_value = my_strcmp(arr[cpt], to_delete);
    }
  if (arr[cpt] == NULL)
    return (arr);
  cpt++;
  while (arr[cpt] != NULL)
    {
      return_value = my_strcmp(arr[cpt], to_delete);
      if (return_value == 0)
	{
	  arr[cpt] = NULL;
	  return (arr);
	}
      cpt++;
    }
  return (arr);
}

char		**check_start_end(char **arr)
{
  int		cpt_start;
  int		cpt_end;

  cpt_start = start_end(arr, "##start");
  cpt_end = start_end(arr, "##end");
  if (cpt_start > 1)
    {
      arr = delete_start_end(arr, "##start");
      cpt_start = start_end(arr, "##start");
    }
  if (cpt_end > 1)
    {
      arr = delete_start_end(arr, "##start");
      cpt_end = start_end(arr, "##end");
    }
  if (cpt_start < 1 || cpt_end < 1)
    {
      my_putstr(2, "You need one '##start' and one '##end'\n");
      return (NULL);
    }
  return (arr);
}
