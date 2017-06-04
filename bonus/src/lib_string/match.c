/*
** match.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Apr 29 16:34:20 2017 Martin Van Elslande
** Last update Sun Apr 30 22:18:20 2017 Martin Van Elslande
*/

int	skip_wildcard(char *str, char *str2, int *count)
{
  int	i;

  if (str2[0] == '*')
    {
      i = 0;
      while (str[i] && str[i] != str2[1])
	i++;
      if (!str[i] && str2[1])
	return (0);
      (*count)++;
      return (i);
    }
  return (0);
}

void	incr_condition(char s1, char s2, int *i, int *j)
{
  if (s1 && s2)
    {
      (*i)++;
      (*j)++;
    }
}

int	match(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] && s2[j])
    {
      if (s1[i] != s2[j] && s1[i] != '*' && s2[j] != '*')
	return (0);
      j += skip_wildcard(&s2[j], &s1[i], &i);
      i += skip_wildcard(&s1[i], &s2[j], &j);
      incr_condition(s1[i], s2[j], &i, &j);
    }
  j += skip_wildcard(&s2[j], &s1[i], &i);
  i += skip_wildcard(&s1[i], &s2[j], &j);
  if (s1[i] != s2[j])
    return (0);
  return (1);
}
