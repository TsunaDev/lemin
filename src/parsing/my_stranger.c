/*
** my_stranger.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/parsing
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Fri Apr 21 14:19:39 2017 Anaïs Breant
** Last update Sun Apr 30 16:47:30 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"
#include	"lemin.h"

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

static void	my_stop_read(char **arr, int cpt)
{
  free(arr[cpt]);
  arr[cpt] = NULL;
}

void		my_stranger(char **arr)
{
  int		return_value;
  int		cmp[2];
  int		cpt;

  cpt = 0;
  while (arr[cpt] != NULL)
    {
      cpt = skip_line_void(arr, cpt);
      cmp[0] = my_strcmp(arr[cpt], "##start");
      cmp[1] = my_strcmp(arr[cpt], "##end");
      if (cmp[0] == 0 || cmp[1] == 0)
	{
	  cpt = skip_line_void(arr, cpt);
	  return_value = compare_next_start_end(arr, &cpt);
	  if (return_value == 1)
	    my_stop_read(arr, cpt);
	}
      else
	cpt++;
    }
}
