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

void	create_space_camera(t_window *this)
{
	int	pixel;

	int	mult;
	t_vector	camera_pixel;
	t_vector	ray_dir;

	pixel = 0;
	while (pixel < this->width)
	{
		mult = 2 * (pixel / this->width) - 1;
		camera_pixel = vector_mult(this->vec.plane, mult);
		ray_dir = vector_add(this->vec.dir, camera_pixel);
		printf("pos.x: %f\npos.y: %f\n", ray_dir.x, ray_dir.y);
		pixel++;
	}
}