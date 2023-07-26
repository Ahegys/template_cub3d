#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

#define ESC 65037

typedef struct l_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

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
	t_pos		pos;
}	t_window;



#endif
