/*
** my_swap.c for my_swap.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/lib/string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Mar 29 13:10:21 2017 Glenn Gabriel Irakiza
** Last update Wed Mar 29 13:10:26 2017 Glenn Gabriel Irakiza
*/

void     my_swap_char(char *a, char *b)
{
  char          tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
