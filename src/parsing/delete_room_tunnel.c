/*
** delete_room_tunnel.c for Lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Fri Apr 21 11:45:51 2017 Anaïs Breant
** Last update Fri Apr 21 19:30:50 2017 Anaïs Breant
*/

#include	<stdlib.h>
#include	"check_file.h"

char		**delete_room_tunnel(char **arr)
{
  int		return_value;
  int		cpt_tunnel;

  cpt_tunnel = find_nbr_tunnel(arr);
  if (cpt_tunnel == -1)
    return (arr);
  while (arr[cpt_tunnel] != NULL)
    {
      if (arr[cpt_tunnel][0] != '\0')
	{
	  return_value = check_str(arr[cpt_tunnel]);
	  if (return_value == 0)
	    {
	      arr[cpt_tunnel] = NULL;
	      return (arr);
	    }
	}
      cpt_tunnel++;
    }
  return (arr);
}
