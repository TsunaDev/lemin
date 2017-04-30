/*
** to_wordtab_to_str.c for to_wordtab_to_str.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string/To_wordtab
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:56:09 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:56:11 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

char		*to_wordtab_to_str(char **arr, int i, int end)
{
  char		*str;
  int		size;

  size = my_strlen_tab(arr) - 1;
  str = my_strcat(arr[i], "\n", 0);
  if (end > size || end < 0)
    return (NULL);
  while (i != end)
    {
      i++;
      str = my_strcat(str, arr[i], 1);
      str = my_strcat(str, "\n", 1);
    }
  return (str);
}
