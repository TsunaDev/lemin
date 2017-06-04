/*
** display_graphical.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Apr 26 10:18:49 2017 Martin Van Elslande
** Last update Sun Apr 30 21:32:43 2017 Martin Van Elslande
*/

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		<math.h>
#include		"lemin.h"
#include		"graph.h"
#include		"display.h"

void			draw_rooms_and_ants(t_sprites *sprites, sfRenderWindow *window,
					    sfVector2f **move, int remaining)
{
  int			i;

  i = 0;
  while (i < sprites->nb_rooms)
    {
      sfRenderWindow_drawSprite(window, sprites->rooms[i], NULL);
      i++;
    }
  i = 0;
  while (i < sprites->nb_ants)
    {
      if (remaining >= 0)
	sfSprite_move(sprites->ants[i], *(move[i]));
      sfRenderWindow_drawSprite(window, sprites->ants[i], NULL);
      i++;
    }
}

void    change_state(t_state *state, t_room **rooms, int i)
{
  if (state->next != 1)
    rooms[state->idx]->full = 1;
  if (state->ant_room[i] != 0)
    rooms[state->prev_idx[i]]->full = 0;
  state->move[i]->x =
    (float)(rooms[state->idx]->x -
	    rooms[state->prev_idx[i]]->x) / 600.0f;
  state->move[i]->y =
    (float)(rooms[state->idx]->y -
	    rooms[state->prev_idx[i]]->y) / 600.0f;
  state->ant_room[i] = state->next;
  state->prev_idx[i] = state->idx;
  if (state->next == 1)
    state->remaining--;
}

int     round_loop(t_state *state, t_room **rooms, int ants, int **paths)
{
  int   i;

  i = 0;
  while (i < ants)
    {
      if (state->ant_room[i] != 1)
        {
          state->next = next_room(state->ant_room[i],
                                  paths[(i % paths[0][0]) + 1]);
          state->idx = get_actual_room(state->next, rooms);
          if (!rooms[state->idx]->full)
	    change_state(state, rooms, i);
	  else
	    stop_ant(state, i);
        }
      else
	stop_ant(state, i);
      i++;
    }
  return (0);
}

int			window_loop(sfRenderWindow *window, t_sprites *sprites,
				    t_room **rooms, int **paths)
{
  sfSprite		*background;
  sfVector2f		*scale;
  t_state		*state;

  scale = malloc(sizeof(sfVector2f));
  state = malloc(sizeof(t_state));
  if (!scale || !state || init_state(state, sprites->nb_ants) == 84)
    return (84);
  set_scale(scale, 1.1f, 1.1f);
  background = set_sprite("dirt2.jpg", NULL, scale);
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, background, NULL);
      sfRenderWindow_drawSprite(window, sprites->tunnels, NULL);
      if (state->remaining >= 0 && state->tick % 600 == 0)
	round_loop(state, rooms, sprites->nb_ants, paths);
      draw_rooms_and_ants(sprites, window, state->move, state->remaining);
      state->tick++;
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
    }
  return (0);
}

int			display_graphical(int nb_ants, t_room **rooms,
					  int **tunnels, int **paths)
{
  sfRenderWindow        *window;
  t_sprites             *sprites;
  int			nb_rooms;
  int			ret;
  t_my_framebuffer	*framebuffer;

  window = window_open(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprites = malloc(sizeof(t_sprites));
  if (!sprites)
    return (84);
  nb_rooms = count_rooms(rooms);
  sprites->ants = malloc(sizeof(sfSprite *) * nb_ants);
  sprites->rooms = malloc(sizeof(sfSprite *) * nb_rooms);
  sprites->tunnels = sfSprite_create();
  sprites->nb_ants = nb_ants;
  sprites->nb_rooms = nb_rooms;
  if (!sprites->ants || !sprites->rooms || !sprites->tunnels)
    return (84);
  framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  set_rooms_texture_and_pos(rooms, sprites->rooms, sprites->nb_rooms);
  set_ants_texture(sprites->ants, sprites->nb_ants, rooms);
  set_tunnels(framebuffer, rooms, sprites, tunnels);
  ret = window_loop(window, sprites, rooms, paths);
  sfRenderWindow_destroy(window);
  return (ret);
}
