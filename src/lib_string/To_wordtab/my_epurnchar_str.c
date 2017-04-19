/*
** my_epurnchar_str.c for my_epurnchar_str.c in /home/gaby/projet_Epitech/PSU/minishell2/PSU_2016_minishell2/src/lib_string/To_wordtab
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Apr  5 16:13:46 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 12:27:35 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	my_nbchar(char *str, char c)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != c)
	cpt++;
      i++;
    }
  return (cpt);
}

static char	*my_cpy(char *new, char *str, char c)
{
  int		i;
  int		b;

  i = 0;
  b = 0;
  while (str[i] != '\0' && (str[i] == c))
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  new[b++] = c;
	  while (str[i] != '\0' && (str[i] == c))
	    i++;
	}
      if (str[i] != c && str[i] != '\0')
	new[b++] = str[i];
      if (str[i] != '\0')
	i++;
    }
  new[b] = '\0';
  return (new);
}

char		*my_epurnchar_str(char *str, char c)
{
  int		nb_words;
  int		nb_char;
  char		*new;

  if (str == NULL)
    return (NULL);
  nb_words = my_nb_words_char(str, c, 0);
  nb_char = my_nbchar(str, c);
  new = malloc(sizeof(char) * (nb_char + nb_words + 3));
  if (new == NULL)
    exit(84);
  new = my_cpy(new, str, c);
  return (new);
}
