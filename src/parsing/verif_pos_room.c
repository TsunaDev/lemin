/*
** verif_pos_room.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/parsing
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Thu Apr 27 14:20:51 2017 Anaïs Breant
** Last update Thu Apr 27 14:44:58 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"check_file.h"
#include	"my_string.h"

static char	**verif_pos(char **tab, char **arr, int cpt, int cpt_tunnel)
{
  int		return_value;
  char		**tab_bis;

  cpt++;
  while (cpt < cpt_tunnel && arr[cpt] != NULL)
    {
      if (arr[cpt][0] != '\0')
	{
	  tab_bis = my_str_to_wordtab(arr[cpt]);
	  return_value = my_strcmp(tab[1], tab_bis[1]);
	  if (return_value == 0)
	    {
	      return_value = my_strcmp(tab[2], tab_bis[2]);
	      if (return_value == 0)
		{
		  arr[cpt] = NULL;
		  return (arr);
		}
	    }
	  my_free_array(tab_bis);
	}
      cpt++;
    }
  return (arr);
}

char		**verif_pos_room(char **arr)
{
  char		**tab_first;
  int		cpt;
  int		cpt_tunnel;

  cpt_tunnel = find_nbr_tunnel(arr);
  cpt = 1;
  while (cpt < cpt_tunnel && arr[cpt] != NULL)
    {
      if (arr[cpt][0] != '\0')
	{
	  tab_first = my_str_to_wordtab(arr[cpt]);
	  arr = verif_pos(tab_first, arr, cpt, cpt_tunnel);
	  my_free_array(tab_first);
	}
      cpt++;
    }
  return (arr);
}
