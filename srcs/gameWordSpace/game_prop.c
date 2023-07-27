#include "../includes/render.h"

t_vector	create_vector(double x, double y)
{
	return ((t_vector){x, y});
}

t_vector vector_mult(t_vector v, double scalar)
{	
	return ((t_vector){ v.x * scalar, v.y * scalar});
}

t_vector vector_add(t_vector v, t_vector scalar)
{	
	return ((t_vector){ v.x + scalar.x, v.y + scalar.y});
}

t_vector vector_copy(t_vector source) {
	t_vector copy;
	copy.x = source.x;
	copy.y = source.y;
	return copy;
}

double ft_abs(double num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

void drawLine(t_window *this, double x1, double y1, double x2, double y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xIncrement = (float)dx / steps;
	float yIncrement = (float)dy / steps;
	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++) {
		pixel(this, (int)x, (int)y, color);
		x += xIncrement;
		y += yIncrement;
	}
}

void create_space_camera(t_window *this) {
	int pixelg;
	t_vector ray_dir;
	double delta_dist_x;
	double delta_dist_y;
	t_vector map_pos;
	int step_x;
	int step_y;
	double side_dist_x;
	double side_dist_y;
	int hit_side;
	double perp_wall_dist;

	pixelg = 0;
	while (pixelg < this->width) {
		double camera_x = 2.0 * pixelg / this->width - 1.0;
		ray_dir = vector_add(this->vec.dir, vector_mult(this->vec.plane, camera_x));

		map_pos = create_vector(floor(this->vec.pos.x), floor(this->vec.pos.y));

		if (ray_dir.x == 0)
			delta_dist_x = 0;
		else
			delta_dist_x = fabs(1.0 / ray_dir.x);

		if (ray_dir.y == 0)
			delta_dist_y = 0;
		else
			delta_dist_y = fabs(1.0 / ray_dir.y);

		int hit = 0;

		if (ray_dir.x < 0) {
			step_x = -1;
			side_dist_x = (this->vec.pos.x - map_pos.x) * delta_dist_x;
		} else {
			step_x = 1;
			side_dist_x = (map_pos.x + 1.0 - this->vec.pos.x) * delta_dist_x;
		}

		if (ray_dir.y < 0) {
			step_y = -1;
			side_dist_y = (this->vec.pos.y - map_pos.y) * delta_dist_y;
		} else {
			step_y = 1;
			side_dist_y = (map_pos.y + 1.0 - this->vec.pos.y) * delta_dist_y;
		}

		while (hit == 0) {
			if (side_dist_x < side_dist_y) {
				side_dist_x += delta_dist_x;
				map_pos.x += step_x;
				hit_side = 0;
			} else {
				side_dist_y += delta_dist_y;
				map_pos.y += step_y;
				hit_side = 1;
			}

			if (this->game_map[(int)map_pos.x][(int)map_pos.y] > 0)
				hit = 1;
		}

		if (hit_side == 0)
			perp_wall_dist = (map_pos.x - this->vec.pos.x + (1.0 - step_x) / 2.0) / ray_dir.x;
		else
			perp_wall_dist = (map_pos.y - this->vec.pos.y + (1.0 - step_y) / 2.0) / ray_dir.y;

		double wall_line_height = this->height / perp_wall_dist;
		double line_start_y = this->height / 2.0 - wall_line_height / 2.0;
		double line_end_y = this->height / 2.0 + wall_line_height / 2.0;

		int color;
		if (hit_side == 1)
			color = 0xeb4034;
		else
			color = 0x540d15;
		drawLine(this, pixelg, line_start_y, pixelg, line_end_y, color);

		pixelg++;
	}
}
