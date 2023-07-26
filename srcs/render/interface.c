#include "../../includes/render.h"

static void window_properties(t_window *this, char *win_name)
{
	this->mlx = mlx_init();
	this->win = mlx_new_window(this->mlx, this->width, this->height, win_name);
}

int exitState(t_window *this)
{
	mlx_destroy_window(this->mlx, this->win);
	mlx_destroy_display(this->mlx);
	if (this->mlx)
		free(this->mlx);
	exit(0);
	return 1;
}

static void	event_caller(t_window *this)
{
	this->img.img = mlx_new_image(this->mlx, this->width, this->height);
	this->img.addr = mlx_get_data_addr(this->img.img, &this->img.bpp, &this->img.line_len, &this->img.endian);

	mlx_hook(this->win, 6, 1L << 6, tracker, this);
	mlx_hook(this->win, 4, 1L << 2, &mouse_hook, this);
	mlx_hook(this->win,  17 , 0, exitState, this);
	mlx_hook(this->win, 2, 1L << 0, check_keys, this);
	mlx_loop_hook(this->mlx, &loop, this);
	mlx_loop(this->mlx);
	mlx_pixel_put(this->mlx, this->win, 700, 550, 0xfffff);

}

void start(t_window *this)
{
	window_properties(this, this->win_name);
	event_caller(this);
}
