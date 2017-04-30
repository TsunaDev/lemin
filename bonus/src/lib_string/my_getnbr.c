/*
** my_getnbr.c for my_getnbr.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:50:41 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:50:42 2017 Glenn Gabriel Irakiza
*/

int	getplus(int final, char *str, int i)
{
  if (final >= 214748364)
    return (0);
  final = final * 10 + str[i] - 48;
  return (final);
}

int	my_getnbr(char *str)
{
  int	i;
  int	final;
  int	value;

  final = 0;
  value = 1;
  i = 0;
  if (str[i] == '-')
    {
      value = -1;
      i++;
    }
  while (str[i] != '\0')
    {
      final = getplus(final, str, i);
      i++;
    }
  i = 0;
  if (value == -1)
    final = (final * (-1));
  return (final);
}
