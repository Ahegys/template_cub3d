#include "../includes/render.h"

void	setup(t_window *this)
{
	this->vec.pos = create_vector(5, 5);
	this->vec.dir = create_vector(0, -1);
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
		if (this->vec.pos.x < 2.8)
			return (-1);
		printf("pos.x: %f\n", this->vec.pos.x);
		this->vec.pos.x-= 0.1;
	}
	else if (key == XK_Right)
	{
		if (this->vec.pos.x > 6.7)
			return (-1);
		printf("pos.x: %f\n", this->vec.pos.x);
		this->vec.pos.x+= 0.1;
	}
	else if (key == XK_Up)
	{
		if (this->vec.pos.y < 3.2)
			return (-1);
		printf("pos.y: %f\n", this->vec.pos.y);
		this->vec.pos.y+= 0.1;
	}
	else if (key == XK_Down)
	{
		if (this->vec.pos.y > 6.5)
			return(-1);
		printf("pos.y: %f\n", this->vec.pos.y);
		this->vec.pos.y-= 0.1;
	}
	else
		printf("key Press &> %i\n", key);
	return (0);
}
