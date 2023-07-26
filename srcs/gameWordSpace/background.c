#include "../includes/render.h"

void draw_cube(t_window *this)
{
	int cube_size;
	int center_x;
	int center_y;
	int x;
	int y;
	
	cube_size = 30 * this->pos.fov;
	center_x = this->width / 2;
	center_y = this->height / 2;

	x = center_x - (cube_size / 2);
	while (x < center_x + (cube_size / 2))
	{
		y = center_y - (cube_size / 2);
		while (y < center_y + (cube_size / 2))
		{
			pixel(this, x + this->pos.x, y + this->pos.y, 0xaaafff);
			y++;
		}
		x++;
	}
}

void	render_background(t_window *this)
{
	int x;
	int y;

	x = 0;
	while (x <= this->width)
	{
		y = 0;
		while (y <= this->height)
		{
			pixel(this, x, y, 0x213e6e);
			y++;
		}
		x++;
	}

}

void	render_floor(t_window *this)
{
	int x;
	int y;

	x = 0;
	while (x <= this->width)
	{
		y = this->height / 2;
		while (y <= this->height)
		{
			pixel(this, x, y, 0x353638);
			y++;
		}
		x++;
	}

}