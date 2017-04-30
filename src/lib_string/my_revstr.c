/*
** my_revstr.c for my_revstr.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:51:27 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:51:28 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

void		my_revstr(char *str)
{
  int		first;
  int		end;

  first = 0;
  end = (my_strlen(str) -1);
  while (first != end && end > first)
    {
      my_swap_char(&str[first], &str[end]);
      end--;
      first++;
    }
}
