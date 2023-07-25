#include "../includes/render.h"

void	pixel(t_window *this, int x, int y, int color)
{
	char	*dest;

	dest = this->img.addr + (y * this->img.line_len + x * (this->img.bpp / 8));
	*(unsigned int *)dest = color;
}