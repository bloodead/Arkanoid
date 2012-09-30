#ifndef _base_h_
#define _base_h_

typedef struct	s_player
{
	int	point;
}	t_player;

typedef struct	s_level
{
	int	lvl;
	int	mur;
	int	n_mur;
}	t_level;
typedef struct	s_brick
{
	int	x;
	int	y;
	int	bonus;
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
	int	bonus;
	int	bonusx;
	int	bonusy;
	t_level	level;
	t_balle	balle;
	t_barre barre;
	t_player player;
}	t_env;

void    show_mur(t_mur* begin, t_env* env);
void    resize_env(t_env* env,t_mur* mur);
void    coli_brick(t_env* env, t_mur* mur);
int     run(t_env* env, t_mur* mur);
void    destroy_brick(t_mur* mur, t_env* env);
void    actu_score(t_env* env);
void id_print_char(char c);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));
void    bonus(t_mur* mur, t_env* env);
void    bonus_down(t_env* env);
void    start_wait(t_env* env, int i);
void    id_print_nbr(int n);
void 	id_print_str(char* str);
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
