/*
** get_next_line.c for get_next_line.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:50:30 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:50:31 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"my_string.h"

static char	*my_realloc_strcat(char *src, char *dest)
{
  int		i;
  int		k;
  char		*new;

  i = 0;
  k = 0;
  new = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
  if (new == NULL)
    return (NULL);
  if (src != NULL)
    while (src[i] != '\0')
      {
	new[i] = src[i];
	i++;
      }
  while (dest[k] != '\0')
    {
      new[i] = dest[k];
      i++;
      k++;
    }
  new[i] = '\0';
  if (src != NULL)
    free(src);
  return (new);
}

static int	my_line(char *str, int rd)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  rd += rd;
  if (rd == my_strlen(str) || rd == 0)
    return (1);
  return (0);
}

static char	*line_only(char *str, int b)
{
  int		i;
  int		idx;
  char		*new;

  i = 0;
  idx = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  new = malloc(sizeof(char) * (i + 1));
  if (new == NULL)
    return (NULL);
  while (str[idx] != '\0' && str[idx] != '\n')
    new[b++] = str[idx++];
  new[b] = '\0';
  return (new);
}

static char	*my_realloc_static(char *stock, int i, int j)
{
  char		*str;

  while (stock[i] != '\n' && stock[i] != '\0')
    i++;
  if (stock[i] == '\0')
    {
      free(stock);
      return (NULL);
    }
  i += 1;
  j = i;
  while (stock[j] != '\0')
    j++;
  str = malloc(sizeof(char) * (j + 1));
  if (str == NULL)
    return (NULL);
  j = 0;
  while (stock[i] != '\0')
    str[j++] = stock[i++];
  free(stock);
  if (j == 0)
    return (NULL);
  str[j] = '\0';
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*stock = NULL;
  char		buffer[READ_SIZE + 1];
  char		*end;
  int		end_of_line;
  int		rd;

  if (fd == -1 || READ_SIZE <= 0)
    return (NULL);
  end_of_line = -1;
  if (my_line(stock, 0) != 1)
    {
      while (end_of_line != 1)
	{
	  rd = read(fd, buffer, READ_SIZE);
	  if (rd <= 0)
	    return (NULL);
	  buffer[rd] = '\0';
	  stock = my_realloc_strcat(stock, buffer);
	  end_of_line = my_line(buffer, rd);
	}
    }
  end = line_only(stock, 0);
  stock = my_realloc_static(stock, 0, 0);
  return (end);
}
