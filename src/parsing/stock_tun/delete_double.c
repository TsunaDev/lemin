/*
** delete_double.c for lemin in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Tue Apr 25 14:17:51 2017 Anaïs Breant
** Last update Tue Apr 25 14:31:15 2017 Anaïs Breant
*/

static int	check_tun(int **tun, int cpt, int save_cpt)
{
  int		cpt_bis;

  cpt_bis = save_cpt;
  if (tun[cpt][0] == tun[cpt_bis][0]
      || tun[cpt][0] == tun[cpt_bis][1])
    {
      if (tun[cpt][1] == tun[cpt_bis][0]
	  || tun[cpt][1] == tun[cpt_bis][1])
	{
	  while (cpt_bis < tun[0][0])
	    {
	      tun[cpt_bis] = tun[cpt_bis + 1];
	      cpt_bis++;
	    }
	  return (1);
	}
    }
  return (0);
}

void		delete_double(int **tun)
{
  int		return_value;
  int		cpt_bis;
  int		cpt;

  cpt = 1;
  while (cpt <= tun[0][0])
    {
      cpt_bis = cpt + 1;
      while (cpt_bis <= tun[0][0])
	{
	  return_value = check_tun(tun, cpt, cpt_bis);
	  if (return_value == 1)
	    tun[0][0] -= 1;
	  else
	    cpt_bis++;
	}
      cpt++;
    }
}
