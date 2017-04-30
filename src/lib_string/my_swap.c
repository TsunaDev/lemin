/*
** my_swap.c for my_swap.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:53:57 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:53:58 2017 Glenn Gabriel Irakiza
*/

void     my_swap_char(char *a, char *b)
{
  char          tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
