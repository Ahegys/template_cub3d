# ifndef RENDER_H
#define RENDER_H

#define MAP_SIZE 10

#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./player_word_prop.h"
#include "./type_defs.h"
#include <math.h>

int			tracker();
void		crosshair(t_window *this, int gap_size);
void		drawLine(t_window *this, double x1, double y1, double x2, double y2, int color);
int			mouse_hook();
void		setup(t_window *this);
void		start(t_window *this);
int			loop(t_window *this);
void		create_space_camera(t_window *this);
t_vector	create_vector(double x, double y);
t_vector	rotate_vector(t_vector vector, double angle);
void		rotate_camera(t_window *camera, double angle);
void		render_floor(t_window *this);
void		pixel(t_window *this, int x, int y, int color);
int			check_keys(int key, t_window *this);
void		render_background(t_window *this);
void		draw_cube(t_window *this);

#endif // RENDER_H
