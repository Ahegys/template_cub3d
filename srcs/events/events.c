#include "../includes/render.h"

void	setup(t_window *this)
{
	this->vec.pos = create_vector(5, 5);
	this->vec.dir = create_vector(0, -1.5);
	this->vec.plane = create_vector(0.66, 0);
}

int	loop(t_window *this)
{
	render_background(this);
	render_floor(this);
	create_space_camera(this);
	mlx_clear_window(this->mlx, this->win);
	mlx_put_image_to_window(this->mlx, this->win, this->img.img, 0, 0);
	return (1);
}

int	mouse_hook()
{

	return (1);
}

int	tracker()
{
	return (1);
}

int	check_keys(int key, t_window *this)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(this->mlx, this->win);
		mlx_destroy_display(this->mlx);
		free(this->mlx);
		exit(0);
	}
	else if (key == XK_Left)
		this->pos.x-= 0.5;
	else if (key == XK_Right)
		this->pos.x+= 0.5;
	else if (key == XK_Up)
		this->pos.y-= 0.5;
	else if (key == XK_Down)
		this->pos.y+= 0.5;
	else if (key == XK_w)
		this->pos.fov += 0.5;
	else if (key == XK_s)
		this->pos.fov -= 0.5;
	else
		printf("key Press &> %i\n", key);
	return (0);
}