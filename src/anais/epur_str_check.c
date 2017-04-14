/*
** epur_str_check.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Thu Apr 13 16:55:15 2017 Anaïs Breant
** Last update Fri Apr 14 13:27:57 2017 Anaïs Breant
*/

static char	*check_last_char(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    cpt++;
  cpt--;
  if (cpt >= 0 && str[cpt] == ' ')
    str[cpt] = '\0';
  return (str);
}

char		*epur_str_check(char *str)
{
  int		cpt_bis;
  int		cpt;

  cpt = 0;
  cpt_bis = 0;

  while (str[cpt] != '\0')
    {
      if (str[cpt] != '\t' && str[cpt] != ' ')
	{
	  str[cpt_bis] = str[cpt];
	  cpt_bis++;
	}
      if ((str[cpt] == '\t' || str[cpt] == ' ')
	  && (str[cpt - 1] != '\t' && str[cpt - 1] != ' ')
	  && cpt > 0)
	{
	  str[cpt_bis] = ' ';
	  cpt_bis++;
	}
      cpt++;
    }
  str[cpt_bis] = '\0';
  str = check_last_char(str);
  return (str);
}
