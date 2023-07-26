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
double	magnitude(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
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
	int mult;
	t_vector camera_pixel;
	t_vector ray_dir;
	double delta_dist_x;
	double delta_dist_y;
	double dist_to_side_x;
	double dist_to_side_y;
	t_vector map_pos;
	int hit;
	int step_x;
	int step_y;
	double dda_line_x;
	double dda_line_y;
	int hit_side;
	double perpe_dist;

	t_vector wall_map_pos;

	pixelg = 0;
	while (pixelg < this->width) {
		mult = 2 * (pixelg / this->width) - 1;
		camera_pixel = vector_mult(this->vec.plane, mult);
		ray_dir = vector_add(this->vec.dir, camera_pixel);

		if (ray_dir.x == 0) {
			delta_dist_x = 1;
			delta_dist_y = 0;
		} else {
			delta_dist_x = ft_abs(1 / ray_dir.x);
		}

		if (ray_dir.y == 0) {
			delta_dist_x = 0;
			delta_dist_y = 1;
		} else {
			delta_dist_y = ft_abs(1 / ray_dir.y);
		}

		map_pos = create_vector(floor(this->vec.pos.x), floor(this->vec.pos.y));
		if (ray_dir.x < 0) {
			dist_to_side_x = (this->vec.pos.x - map_pos.x) * delta_dist_x;
			step_x = -1;
		} else {
			dist_to_side_x = (map_pos.x + 1 - this->vec.pos.x) * delta_dist_x;
			step_x = 1;
		}

		if (ray_dir.y < 0) {
			dist_to_side_y = (this->vec.pos.y - map_pos.y) * delta_dist_y;
			step_y = -1;
		} else {
			dist_to_side_y = (map_pos.y + 1 - this->vec.pos.y) * delta_dist_y;
			step_y = 1;
		}

		hit = FALSE;
		dda_line_x = dist_to_side_x;
		dda_line_y = dist_to_side_y;
		wall_map_pos = vector_copy(map_pos);
		while (hit == FALSE) {
			if (dda_line_x < dda_line_y) {
				wall_map_pos.x += step_x;
				dda_line_x += delta_dist_x;
				hit_side = 0;
			} else {
				wall_map_pos.y += step_y;
				dda_line_y += delta_dist_y;
				hit_side = 1;
			}

			if (this->game_map[(int)wall_map_pos.x][(int)wall_map_pos.y] > 0)
				hit = TRUE;
		}

		if (hit_side == 0)
			perpe_dist = ft_abs(wall_map_pos.x - this->vec.pos.x + ((1 - step_x) / 2)) / ray_dir.x;
		else
			perpe_dist = ft_abs(wall_map_pos.y - this->vec.pos.y + ((1 - step_y) / 2)) / ray_dir.y;

		double wall_line_height = this->height / perpe_dist;
		double line_start_y = this->height / 2 - wall_line_height / 2;
		double line_end_y = this->height / 2 + wall_line_height / 2;
		int color;
		if (hit_side == 1)
			color = 255;
		else
			color = 128;
		drawLine(this, pixelg, line_start_y, pixelg, line_end_y, color);
		pixelg++;
	}
}