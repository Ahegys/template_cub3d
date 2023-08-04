#include "../includes/render.h"
#include <math.h>

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

t_vector	rotate_vector(t_vector vector, double angle)
{
	double	rotate_x;
	double	rotate_y;
	rotate_x = vector.x * cos(angle) - vector.y * sin(angle);
	rotate_y = vector.x * sin(angle) + vector.y * cos(angle);
	return ((t_vector){rotate_x, rotate_y});
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
	int steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
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

void	check_hit_map(t_math_map *self, t_vector *map_pos, t_vector *ray_dir, t_window *this)
{
		while (self->hit == 0)
		{
			if (self->sdist_x <= self->sdist_y) {
				self->sdist_x += self->ddist_x;
				map_pos->x += self->stepx;
				self->hit_side = 0;
			}
			else
			{
				self->sdist_y += self->ddist_y;
				map_pos->y += self->stepy;
				self->hit_side = 1;
			}

			if (this->game_map[(int)map_pos->x][(int)map_pos->y] == 1)
				self->hit = 1;
		}

		if (self->hit_side == 0)
			self->perpe_wall_dist = (map_pos->x - this->vec.pos.x + (1.0 - self->stepx) / 2.0) / ray_dir->x;
		else
			self->perpe_wall_dist = (map_pos->y - this->vec.pos.y + (1.0 - self->stepy) / 2.0) / ray_dir->y;

		self->wall_line_height = this->height / self->perpe_wall_dist;
		self->line_start_y = this->height / 2.0 - self->wall_line_height / 2.0;
		self->line_end_y = this->height / 2.0 + self->wall_line_height / 2.0;

		if (self->hit_side == 1)
			self->color = 0xeb4034;
		else
			self->color = 0x540d15;
		drawLine(this, self->pixelg, self->line_start_y, self->pixelg, self->line_end_y, self->color);
}

void create_space_camera(t_window *this) {
	t_math_map	self;
	t_vector ray_dir;
	t_vector map_pos;

	self.pixelg = 0;
	while (self.pixelg <= this->width) {
		self.camera_x = 2.0 * self.pixelg / this->width - 1.0;
		ray_dir = vector_add(this->vec.dir, vector_mult(this->vec.plane, self.camera_x));

		map_pos = create_vector(floor(this->vec.pos.x), floor(this->vec.pos.y));

		if (ray_dir.x == 0)
			self.ddist_x = 0;
		else
			self.ddist_x = fabs(1 /ray_dir.x);
		if (ray_dir.y == 0)
			self.ddist_y = 0;
		else
			self.ddist_y = fabs(1 / ray_dir.y);

		self.hit = 0;

		if (ray_dir.x < 0)
		{
			self.stepx = -1;
			self.sdist_x = (this->vec.pos.x - map_pos.x) * self.ddist_x;
		} 
		else 
		{
			self.stepx = 1;
			self.sdist_x = (map_pos.x + 1.0 - this->vec.pos.x) * self.ddist_x;
		}

		if (ray_dir.y < 0) {
			self.stepy = -1;
			self.sdist_y = (this->vec.pos.y - map_pos.y) * self.ddist_y;
		} 
		else
		{
			self.stepy = 1;
			self.sdist_y = (map_pos.y + 1.0 - this->vec.pos.y) * self.ddist_y;
		}

		check_hit_map(&self, &map_pos, &ray_dir, this);

		this->vec.dir = (t_vector){0.1 , 0.5};
		self.pixelg++;
	}
}
