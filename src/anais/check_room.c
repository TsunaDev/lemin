/*
** check_room.c for check_room.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:57:42 2017 Anaïs Breant
** Last update Wed Apr 12 20:02:39 2017 Anaïs Breant
*/

int		check_arr(char **arr)
{

}

int		check_room(char **arr)
{
  int		return_value;

  arr = skip_bad_line(arr);
  return_value = check_arr(arr);
  if (return_value == -1)
    return (-1);
  return (0);
}
