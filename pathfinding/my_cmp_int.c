/*
** my_cmp_int.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sun Apr 23 15:10:04 2017 LaFleche
** Last update Tue Apr 25 22:59:50 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

static int      *clean_tab(int *src, int length)
{
  int           i;

  i = 0;
  while (i != length)
    {
      src[i] = -1;
      i++;
    }
  return (src);
}

int		*my_cp_tab(int *src, int *dest)
{
  int		i;
  int		length;

  i = 0;
  length = tab_intlen(src) + 1;
  dest = clean_tab(dest, length);
  while (src[i] != -1)
    {
      dest[i] = src[i];
      i++;
    }
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
  int		opt;
  int		i, x;

  i = 0;
  ///  opt = (tab_intlen(tab) >= tab_intlen(tab2)) ? (0) : (1);
  //if (opt == 0)
  //{
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
  /*}
  if (opt == 1)
    {
      while (tab2[i] != -1)
	{
	  if (tab[i] == tab2[i] && tab[i] != 0 && tab[i] != 1)
	    return (1);
	  i++;
	}
	}*/
  return (0);
}
