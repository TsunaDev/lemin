/*
** create_tools.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 14:38:09 2017 LaFleche
** Last update Tue Apr 25 23:14:19 2017 LaFleche
*/

#include <stdlib.h>
#include "pathfinding.h"

//int tab[12][2];///////////////////////////////////////////////////////////////////////////////

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

int		**pathfinding("inserer le nombre de room", "insérer le nombre de pipes")
{
  int		**tools;
  int		**ret;
  int		i = 1, x = 0;

  /*  tab[0][0] = 0;
  tab[0][1] = 4;
  
  tab[1][0] = 0;
  tab[1][1] = 6;
  
  tab[2][0] = 1;
  tab[2][1] = 3;
  
  tab[3][0] = 4;
  tab[3][1] = 3;

  tab[4][0] = 5;
  tab[4][1] = 2;
  
  tab[5][0] = 3;
  tab[5][1] = 5;
  
  tab[6][0] = 4;
  tab[6][1] = 2;
  
  tab[7][0] = 2;
  tab[7][1] = 1;

  tab[8][0] = 7;
  tab[8][1] = 6;
  
  tab[9][0] = 7;
  tab[9][1] = 2;
  
  tab[10][0] = 7;
  tab[10][1] = 4;
  
  tab[11][0] = 6;
  tab[11][1] = 5;*/

  ///  tab[0][0] = 0;
  ///tab[0][1] = 1;
  
  /*  tab[1][0] = 0;
  tab[1][1] = 3;
  
  tab[2][0] = 2;
  tab[2][1] = 1;

  tab[3][0] = 3;
  tab[3][1] = 1;
  
  tab[4][0] = 2;
  tab[4][1] = 3;

  tab[5][0] = 0;
  tab[5][1] = 4;

  tab[6][0] = 1;
  tab[6][1] = 4;*/
  
  /*tab[0][0] = 0;
  tab[0][1] = 2;

  tab[1][0] = 3;
  tab[1][1] = 2;

  tab[2][0] = 3;
  tab[2][1] = 4;

  tab[3][0] = 6;
  tab[3][1] = 4;
  
  tab[4][0] = 4;
  tab[4][1] = 5;

  tab[5][0] = 5;
  tab[5][1] = 1;

  tab[6][0] = 0;
  tab[6][1] = 6;
  
  tab[7][0] = 1;
  tab[7][1] = 6;*/
  
  tools = create_tools("inserer le nombre de room", "insérer le nombre de pipes");
  if (tools == NULL)
    return (84);
      printf("\n");
  ret = find_all_path(tools, "inserer le nombre de room", "insérer le nombre de pipes");
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
