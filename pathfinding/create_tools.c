/*
** create_tools.c for lemin in /home/lafleche/semester_2/CPE_2016_Lemin/pathfinding
** 
** Made by LaFleche
** Login   <vincent.larcher@epitech.eu>
** 
** Started on  Sat Apr 22 14:38:09 2017 LaFleche
** Last update Sun Apr 30 16:28:28 2017 LaFleche
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

static int     	*fill_one_tool(int *tool, int nb_pipes, int num_room, int **tab)
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

static int	**fill_my_tools(int **tools, int nb_rooms, int nb_pipes, int **tab)
{
  int		i, j;
  int		size;

  i = 0;
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
	j++;
      i++;
    }
  return (tools);
}

static int	**create_tools(int nb_rooms, int nb_pipes, int **tab)
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

int		pathfinding(int **tab_pipes, int nb_pipes,
			    int nb_rooms, int ***paths)
{
  t_pathf	*pathf;
  int		ret;

  if (tab_pipes == NULL || nb_pipes == 0 || nb_rooms == 0)
    return (-1);
  pathf = malloc(sizeof(*pathf));
  if (pathf == NULL)
    return (84);
  pathf->tools = create_tools(nb_rooms, nb_pipes, tab_pipes);
  if (pathf->tools == NULL || pathf->tools[0][0] == -1
      || pathf->tools[1][0] == -1)
    return (84);
  pathf->nb_rooms = nb_rooms;
  pathf->nb_pipes = nb_pipes;
  pathf->limit = 0;
  ret = find_all_path(pathf);
  if (ret == 84 || ret == -1)
    return (ret);
  (*paths) = pathf->final_path;
  return (0);
}
