#include "./includes/render.h"
#include "includes/type_defs.h"
#define MAP_SIZE 10

void printGameMap(t_window * game) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%2d ", game->game_map[i][j]);
		}
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	t_window self;

	self.width = 800;
	self.height = 600;
	self.pos.x = 5;
	self.pos.y = 5;
	self.pos.fov = 2;
	self.pos.z = 0;
	int game_map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			self.game_map[i][j] = game_map[i][j];
		}
	}

	printGameMap(&self);
	(void)av;
	self.win_name = "GameRender";
	start(&self);
}
