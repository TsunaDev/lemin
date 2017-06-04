/*
** my_cmp_int.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sun Apr 23 15:10:04 2017 LaFleche
** Last update Sun Apr 30 01:38:36 2017 LaFleche
*/

#include "pathfinding.h"

int		*my_cp_tab(int *src, int *dest)
{
  int		i;

  i = 0;
  while (src[i] != -1)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = -1;
  return (dest);
}

int		int_cmp(int *src, int cmp)
{
  int		i;

  i = 0;
  while (src[i] != -1)
    {
      if (src[i] == cmp)
	return (0);
      i++;
    }
  return (1);
}

int		tab_intlen(int *tab)
{
  int		i;

  i = 0;
  while (tab[i] != -1)
    i++;
  return (i);
}

int		int_tab_cmp(int *tab, int *tab2)
{
  int		i;
  int		x;

  i = 0;
  while (tab[i] != -1)
    {
      x = 0;
      while (tab2[x] != -1)
	{
	  if (tab[i] == tab2[x] && tab[i] != 0 && tab[i] != 1)
	    {
	      return (1);
	    }
	  x++;
	}
      i++;
    }
  return (0);
}
