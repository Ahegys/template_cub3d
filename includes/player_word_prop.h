#ifndef	PLAYER_WORD_PROP_H
#define	PLAYER_WORD_PROP_H

typedef	struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_props {
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
} t_props;
#endif