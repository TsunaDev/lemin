/*
** main.c for main.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Mon Apr 10 14:24:34 2017 Glenn Gabriel Irakiza
** Last update Mon Apr 10 14:25:11 2017 Glenn Gabriel Irakiza
*/

#include	"lemin.h"
#include	"my_string.h"

int		main()
{
  char		** arr;

  arr = open_file(0);
  my_showtab(arr);
  my_free_array(arr);
  return (0);
}
