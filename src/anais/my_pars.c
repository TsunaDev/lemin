/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 12 15:25:09 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

int		my_pars(char **arr)
{
  int		ants;

  ants = my_getnbr(arr[0]);
  printf("%d\n", ants);
  my_recup_room(arr);
  return (0);
}
