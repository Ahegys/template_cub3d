#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

#define ESC 65037
#define FALSE 0
#define TRUE 1

typedef struct l_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_math_map
{
	double	ddist_x;
	double	ddist_y;
	double	sdist_x;
	double	sdist_y;
	double	camera_x;
	double	camera_y;
	double	perpe_wall_dist;
	double	wall_line_height;
	double	line_start_y;
	double	line_end_y;
	int		hit;
	int		pixelg;
	int		color;
	int		stepx;
	int		stepy;
	int		hit_side;
}	t_math_map;

typedef	struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_props
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
} t_props;

typedef struct l_pos
{
	unsigned int			frame_time;
	int						x;
	int						y;
	int						z;
	float					fov;
}	t_pos;

typedef struct s_window
{
	t_img		img;
	t_props		vec;
	void		*mlx;
	void		*win;
	char		*win_name;
	int			height;
	int			width;
	double			game_map[10][10];
	t_pos		pos;
}	t_window;

#endif
