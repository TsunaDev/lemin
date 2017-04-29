/*
** create_tools.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 14:38:09 2017 LaFleche
** Last update Sat Apr 29 13:59:31 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

static int		my_malloc_size(int num_room, int nb_pipes, int **tab)
{
  int		i;
  int		size;

  i = 1;
  size = 0;
  while (i != (nb_pipes + 1))
    {
      if (tab[i][0] == num_room)
	size++;
      else if (tab[i][1] == num_room)
	size++;
      i++;
    }
  return (size);
}

static int		*fill_one_tool(int *tool, int nb_pipes, int num_room, int **tab)
{
  int		j;
  int		i;

  j = 1;
  i = 0;
  while (j != (nb_pipes + 1))
    {
      if (tab[j][0] == num_room)
	{
	  tool[i] = tab[j][1];
	  i++;
	}
      else if (tab[j][1] == num_room)
	{
	  tool[i] = tab[j][0];
	  i++;
	}
      j++;
    }
  return (tool);
}

static int		**fill_my_tools(int **tools, int nb_rooms, int nb_pipes, int **tab)
{
  int		i, j;
  int		size;

  i = 0;
  ///    printf("--start tools\n");
  while (i != nb_rooms)
    {
      size = my_malloc_size(i, nb_pipes, tab) + 1;
      tools[i] = malloc(sizeof(int) * (size));
      if (tools == NULL)
	return (NULL);
      fill_one_tool(tools[i], nb_pipes, i, tab);
      tools[i][size - 1] = -1;
      j = 0;
      while (tools[i][j] != -1)
	{
	  //  printf("%d ", tools[i][j]);
	  j++;
	}
      //  printf("\n");
      i++;
    }
  //  printf("--end tools\n");
  return (tools);
}

static int		**create_tools(int nb_rooms, int nb_pipes, int **tab)
{
  int		**tools;

  tools = malloc(sizeof(int *) * (nb_rooms));
  if (tools == NULL)
    return (NULL);
  tools = fill_my_tools(tools, nb_rooms, nb_pipes, tab);
  if (tools == NULL)
    return (NULL);
  return (tools);
}

int		**pathfinding(int **tab_pipes, int nb_pipes, int nb_rooms)
{
  int		**tools;
  int		**ret;

  if (tab_pipes == NULL || nb_pipes == 0 || nb_rooms == 0)
    exit(0);
  //  int x, i = 1;
  tools = create_tools(nb_rooms, nb_pipes, tab_pipes);
  if (tools == NULL)
    return (NULL);
  if (tools[0][0] == -1) //////////////////////////
    exit(0);
  if (tools[1][0] == -1) //////////////////////////
    exit(0);
  //  exit(0);
  //  printf("\n");
  ret = find_all_path(tools, nb_rooms, nb_pipes);
    if (ret == NULL)
    return (NULL);
    //printf("\n\n---->%d\n", ret[0][0]);
    /*while (i != (ret[0][0] + 1))
    {
      x = 0;
      while (ret[i][x] != -1)
	{
	  printf("%d ", ret[i][x]);
	  x++;
	}
      printf("\n");
      i++;
      }*/
  //      exit(0);
  return (ret);
}
