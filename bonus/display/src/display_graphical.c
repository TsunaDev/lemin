/*
** display_graphical.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Apr 26 10:18:49 2017 Martin Van Elslande
** Last update Sun Apr 30 19:48:03 2017 Martin Van Elslande
*/

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		<math.h>
#include		"graph.h"
#include		"lemin.h"
#include		"display.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  int                   i;
  t_my_framebuffer      *framebuffer;

  i = 0;
  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  if ((framebuffer->pixels = malloc
       (width * height * 4 * sizeof(framebuffer->pixels))) == NULL)
    return (NULL);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer);
}

int			count_rooms(t_room **rooms)
{
  int			i;

  i = 0;
  while (rooms[i])
    i++;
  return (i);
}

sfSprite                *set_sprite(char *file, sfIntRect *area,
                                    sfVector2f *scale)
{
  sfSprite              *sprite;
  sfTexture             *texture;

  sprite = sfSprite_create();
  texture = sfTexture_createFromFile(file, NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  if (area)
    sfSprite_setTextureRect(sprite, *area);
  if (scale)
    sfSprite_scale(sprite, *scale);
  return (sprite);
}

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

int             init_state(t_state *state, int nb_ants)
{
  int		i;

  state->ant_room = malloc(sizeof(int) * nb_ants);
  state->prev_idx = malloc(sizeof(int) * nb_ants);
  if (!state->ant_room || !state->prev_idx)
    return (84);
  state->move = malloc(sizeof(sfVector2f *) * nb_ants);
  i = 0;
  while (i < nb_ants)
    {
      state->move[i] = malloc(sizeof(sfVector2f));
      i++;
    }
  memset_int_array(state->ant_room, nb_ants, 0);
  memset_int_array(state->prev_idx, nb_ants, 0);
  state->remaining = nb_ants;
  state->next = 0;
  state->idx = 0;
  state->tick = 0;
  return (0);
}

void    change_state(t_state *state, t_room **rooms, int i)
{
  if (state->next != 1)
    rooms[state->idx]->full = 1;
  if (state->ant_room[i] != 0)
    rooms[state->prev_idx[i]]->full = 0;
  state->move[i]->x =
    (float)(rooms[state->idx]->x -
	    rooms[state->prev_idx[i]]->x) / 300.0f;
  state->move[i]->y =
    (float)(rooms[state->idx]->y -
	    rooms[state->prev_idx[i]]->y) / 300.0f;
  state->ant_room[i] = state->next;
  state->prev_idx[i] = state->idx;
  if (state->next == 1)
    state->remaining--;
}

void	stop_ant(t_state *state, int i)
{
  state->move[i]->x = 0;
  state->move[i]->y = 0;
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

void			set_scale(sfVector2f *scale, float x, float y)
{
  scale->x = x;
  scale->y = y;
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
      if (state->remaining >= 0 && state->tick % 300 == 0)
	round_loop(state, rooms, sprites->nb_ants, paths);
      draw_rooms_and_ants(sprites, window, state->move, state->remaining);
      state->tick++;
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
    }
  return (0);
}

sfRenderWindow          *window_open(int width, int height)
{
  sfVideoMode           mode;
  sfRenderWindow*       window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Lem-in",
                                 sfResize | sfClose, NULL);
  if (!window)
    return (NULL);
  return (window);
}

void			set_color_and_positions(t_room **rooms,
						sfSprite **rooms_s,
						int nb_rooms, int i)
{
  rooms[i]->x *= (5.0f + ((float)nb_rooms / 5.0f));
  rooms[i]->y *= (5.0f + ((float)nb_rooms / 5.0f));
  rooms[i]->x += 100.0f;
  rooms[i]->y += 100.0f;
  if (rooms[i]->new_name == 1)
    sfSprite_setColor(rooms_s[i], sfGreen);
  else if (rooms[i]->new_name == 0)
    sfSprite_setColor(rooms_s[i], sfRed);
}

int			set_rooms_texture_and_pos(t_room **rooms,
						  sfSprite **rooms_s,
						  int nb_rooms)
{
  int			i;
  sfVector2f		*scale;
  sfVector2f		pos;
  sfVector2f		center;

  i = 0;
  scale = malloc(sizeof(sfVector2f));
  if (!scale)
    return (84);
  scale->x = 0.1f;
  scale->y = 0.1f;
  center.x = 200.0f;
  center.y = 200.0f;
  while (i < nb_rooms)
    {
      rooms_s[i] = set_sprite("room.png", NULL, scale);
      set_color_and_positions(rooms, rooms_s, nb_rooms, i);
      sfSprite_setOrigin(rooms_s[i], center);
      pos.x = rooms[i]->x;
      pos.y = rooms[i]->y;
      sfSprite_setPosition(rooms_s[i], pos);
      i++;
    }
  return (0);
}

void			set_ants_texture(sfSprite **ants, int nb_ants, t_room **rooms)
{
  int			i;
  sfVector2f		*scale;
  sfVector2f		pos;
  int			start;
  sfVector2f		center;

  i = 0;
  start = get_actual_room(0, rooms);
  scale = malloc(sizeof(sfVector2f));
  pos.x = rooms[start]->x;
  pos.y = rooms[start]->y;
  scale->x = 0.06f;
  scale->y = 0.06f;
  center.x = 212.5f;
  center.y = 300.0f;
  while (i < nb_ants)
    {
      ants[i] = set_sprite("ant.png", NULL, scale);
      sfSprite_setRotation(ants[i], 0);
      sfSprite_setPosition(ants[i], pos);
      sfSprite_setOrigin(ants[i], center);
      i++;
    }
}

void			set_tunnels(t_my_framebuffer *framebuffer,
				    t_room **rooms, t_sprites *sprites,
				    int **tun_array)
{
  int			i;
  int			idx1;
  int			idx2;
  sfVector2i		pos_a;
  sfVector2i		pos_b;
  sfTexture		*texture;

  i = 1;
  sprites->tunnels = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprites->tunnels, texture, sfTrue);
  while (i < tun_array[0][0] + 1)
    {
      idx1 = get_actual_room(tun_array[i][0], rooms);
      idx2 = get_actual_room(tun_array[i][1], rooms);
      pos_a.x = rooms[idx1]->x;
      pos_a.y = rooms[idx1]->y;
      pos_b.x = rooms[idx2]->x;
      pos_b.y = rooms[idx2]->y;
      my_draw_line(framebuffer, pos_a, pos_b, sfRed);
      i++;
    }
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
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
