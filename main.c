#include "includes/render.h"
#include "includes/type_defs.h"


int	main(int ac, char **av)
{
	(void)ac;
	t_window self;

	self.width = 1280;
	self.height = 720;
	self.pos.x = 5;
	self.pos.y = 5;
	self.pos.fov = 2;
	self.pos.z = 0;
	int game_map[MAP_SIZE][MAP_SIZE] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,1,0,1,0,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,1,0,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	// Copiando o mapa criado para a struct
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			self.game_map[i][j] = game_map[i][j];
		}
	}
	(void)av;
	self.win_name = "GameRender";
	start(&self);
}
