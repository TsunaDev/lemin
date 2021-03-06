/*
** my_epurstr.c for my_epurstr.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string/To_wordtab
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:55:21 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:55:21 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	my_nbchar(char *str)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	cpt++;
      i++;
    }
  return (cpt);
}

static char	*my_cpy(char *new, char *str)
{
  int		i;
  int		b;

  i = 0;
  b = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
	new[b++] = ' ';
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	i++;
      if (str[i] != ' ' && str[i] != '\0')
	new[b++] = str[i];
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	i++;
      if (str[i] != '\0')
	i++;
    }
  new[b] = '\0';
  return (new);
}

char		*my_epur_str(char *str)
{
  int		nb_words;
  int		nb_char;
  char		*new;

  if (str == NULL)
    return (NULL);
  nb_words = my_nb_words(str);
  nb_char = my_nbchar(str);
  new = malloc(sizeof(char) * (nb_char + nb_words + 3));
  if (new == NULL)
    return (NULL);
  new = my_cpy(new, str);
  return (new);
}
