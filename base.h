#ifndef _base_h_
#define _base_h_

typedef struct	s_player
{
	int	point;
}	t_player;

typedef struct	s_brick
{
	int	x;
	int	y;
}	t_brick;

typedef struct	s_mur
{
	t_brick	brick;
	struct	s_mur* next;
}	t_mur;

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
	t_player player;
}	t_env;

void	init_mur(t_mur* mur, t_env* env);
void	init_barre(t_env* env);
void	actua_barre(t_env* env, int direct);
void	move_barre(t_env* env);
void	init_balle(t_env* env);
void	move_balle(t_env* env);
int	id_put(int c);
int	init_env(t_env* env);
void	init_cadre(t_env* env);
#endif
