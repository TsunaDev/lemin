/*
** my_initialization.c for Lemin in /home/lafleche/norm/CPE_2016_Lemin
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sun Apr 30 04:16:43 2017 LaFleche
** Last update Sun Apr 30 04:21:00 2017 LaFleche
*/

#include	<stdlib.h>
#include	"pathfinding.h"

int		*init_tab(int *tab, int length)
{
  int		i;

  i = 0;
  tab = malloc(sizeof(int) * (length));
  if (tab == NULL)
    return (NULL);
  while (i != (length - 1))
    {
      tab[i] = -1;
      i++;
    }
  return (tab);
}
