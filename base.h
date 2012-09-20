#ifndef _base_h_
#define _base_h_

typedef struct	s_balle
{
	int	x;
	int	y;
	int	addx;
	int	addy;
}	t_balle;

typedef struct	s_barre
{
	int	x;
	int	y;
	int	size;
}	t_barre;

typedef struct	s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
	t_balle	balle;
	t_barre barre;
}	t_env;

void	init_barre(t_env* env);
void	actua_barre(t_env* env, int direct);
void	move_barre(t_env* env);
#endif
