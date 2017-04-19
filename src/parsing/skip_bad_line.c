/*
** skip_bad_line.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 20:02:51 2017 Anaïs Breant
** Last update Wed Apr 19 21:01:02 2017 Anaïs Breant
*/

#include	<unistd.h>
#include	"my_string.h"
#include	"check_file.h"

static char	*modif_str(char **str)
{
  free(*str);
  (*str) = malloc(sizeof(char) * 1);
  if (*str == NULL)
    return (NULL);
  (*str)[0] = '\0';
  return (*str);
}

static int	check_str_connect(char *str)
{
  int		cpt_hyphen;
  int		cpt;

  cpt_hyphen = 0;
  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] == '-')
	cpt_hyphen++;
      cpt++;
    }
  if (cpt_hyphen == 1)
    return (0);
  return (1);
}

static int	check_str_room(char *str)
{
  int		cpt_space;
  int		cpt;

  cpt = 0;
  cpt_space = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] == ' ')
	cpt_space++;
      cpt++;
    }
  if (cpt_space == 2)
    return (0);
  return (1);
}

static char	*skip_comment(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (cpt == 0 && str[cpt] == '#' && str[cpt + 1] != '#')
	str[cpt] = '\0';
      else if (cpt > 0 &&
	  str[cpt] == '#' && str[cpt - 1] != '#' && str[cpt + 1] != '#')
	str[cpt] = '\0';
      else
	cpt++;
    }
  return (str);
}

char		**skip_bad_line(char **arr)
{
  int		cpt;

  cpt = 1;
  while (arr[cpt] != NULL)
    {
      arr[cpt] = skip_comment(arr[cpt]);
      arr[cpt] = epur_str_check(arr[cpt]);
      if ((my_strcmp(arr[cpt], "##start")) == 0)
	cpt++;
      else if ((my_strcmp(arr[cpt], "##end")) == 0)
	cpt++;
      else if ((check_str_room(arr[cpt])) == 0)
	cpt++;
      else if ((check_str_connect(arr[cpt])) == 0)
	cpt++;
      else
	{
	  modif_str(&arr[cpt]);
	  cpt++;
	}
    }
  return (arr);
}
