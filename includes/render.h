# ifndef RENDER_H
#define RENDER_H

#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./type_defs.h"

int		tracker();
int		mouse_hook();
void	start(t_window *this);
int		render(t_window *this);
void	pixel(t_window *this, int x, int y, int color);
#endif // RENDER_H
