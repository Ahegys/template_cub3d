#include "./includes/render.h"
#include "includes/type_defs.h"

int	main(int ac, char **av)
{
	(void)ac;
	t_window self;

	self.width = 800;
	self.height = 600;
	self.pos.x = 0;
	self.pos.y = 0;
	self.pos.fov = 2;
	self.pos.z = 0;
	self.win_name = "GameRender";
	printf("%s %uc\n", av[1], 199);
	start(&self);
}
