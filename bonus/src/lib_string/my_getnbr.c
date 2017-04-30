/*
** my_getnbr.c for my_getnbr in /home/Zerty10/delivery/CPool_Day07/lib
** 
** Made by Quentin Gandon
** Login   <Zerty10@epitech.net>
** 
** Started on  Tue Oct 11 09:47:16 2016 Quentin Gandon
** Last update Fri Nov 25 09:19:03 2016 Quentin Gandon
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
