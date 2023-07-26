# ifndef RENDER_H
#define RENDER_H

#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./player_word_prop.h"
#include "./type_defs.h"

int			tracker();
int			mouse_hook();
void		setup(t_window *this);
void		start(t_window *this);
int			loop(t_window *this);
void		create_space_camera(t_window *this);
t_vector	create_vector(double x, double y);
void		render_floor(t_window *this);
void		pixel(t_window *this, int x, int y, int color);
int			check_keys(int key, t_window *this);
void		render_background(t_window *this);
void		draw_cube(t_window *this);

#endif // RENDER_H
