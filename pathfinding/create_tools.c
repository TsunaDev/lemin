/*
** create_tools.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 14:38:09 2017 LaFleche
** Last update Wed Apr 26 10:09:43 2017 Martin Van Elslande
*/

#include <stdlib.h>
#include "pathfinding.h"

int tab[1][2];

static int		my_malloc_size(int num_room, int nb_pipes)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (i != nb_pipes)
    {
      if (tab[i][0] == num_room)
	size++;
      else if (tab[i][1] == num_room)
	size++;
      i++;
    }
  return (size);
}

static int		*fill_one_tool(int *tool, int nb_pipes, int num_room)
{
  int		j;
  int		i;

  j = 0;
  i = 0;
  while (j != nb_pipes)
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

static int		**fill_my_tools(int **tools, int nb_rooms, int nb_pipes)
{
  int		i, j;
  int		size;

  i = 0;
  while (i != nb_rooms)
    {
      size = my_malloc_size(i, nb_pipes) + 1;
      tools[i] = malloc(sizeof(int) * (size));
      if (tools == NULL)
	return (NULL);
      fill_one_tool(tools[i], nb_pipes, i);
      tools[i][size - 1] = -1;
      j = 0;
      while (tools[i][j] != -1)
	{
	  printf("%d ", tools[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
  printf("--end tools\n");
  return (tools);
}

static int		**create_tools(int nb_rooms, int nb_pipes)
{
  int		**tools;

  tools = malloc(sizeof(int *) * (nb_rooms));
  if (tools == NULL)
    return (NULL);
  tools = fill_my_tools(tools, nb_rooms, nb_pipes);
  if (tools == NULL)
    return (NULL);
  return (tools);
}

int		**pathfinding()
{
  int		**tools;
  int		**ret;
  int		i = 1, x = 0;

  tab[0][0] = 0;
  tab[0][1] = 1;
  
  tools = create_tools(2, 1);
  if (tools == NULL)
    return (84);
      printf("\n");
  ret = find_all_path(tools, 2, 1);
  if (ret == NULL)
    return (84);
  printf("\n\n---->%d\n", ret[0][0]);
  while (i != (ret[0][0] + 1))
    {
      x = 0;
      while (ret[i][x] != -1)
	{
	  printf("%d ", ret[i][x]);
	  x++;
	}
      printf("\n");
      i++;
    }
  return (ret);
}
