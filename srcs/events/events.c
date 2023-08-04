#include "../includes/render.h"

void	setup(t_window *this)
{
	this->vec.pos = create_vector(5, 8);
	this->vec.dir = create_vector(0.1, 0.5);
	this->vec.plane = create_vector(1, 0);
}

int	loop(t_window *this)
{
	render_background(this);
	render_floor(this);
	create_space_camera(this);
	crosshair(this, 3);
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
	{
		this->vec.pos.x-= 0.1;
	}
	else if (key == XK_Right)
	{
		this->vec.pos.x+= 0.1;
	}
	else if (key == XK_Up)
	{
		this->vec.pos.y+= 0.1;
	}
	else if (key == XK_Down)
	{
		this->vec.pos.y-= 0.1;
	}
	else if (key == XK_r)
	{
		rotate_camera(this,-0.1);
	}
	else if (key == XK_e)
	{
		rotate_camera(this, 0.1);
	}
	else
		printf("key Press &> %i\n", key);
	return (0);
}
