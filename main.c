#include <stdarg.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

typedef struct s_balle
{
	int     x;
	int     y;
	int     addx;
	int     addy;
}	t_balle;

typedef struct s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
	t_balle	balle;
}	t_env;

int	id_put(int c)
{
	char	d;

	d = c;
	write(1, &d, 1);
}

int	init_env(t_env* env)
{
	char*	termtype = getenv("TERM");
	int	success;


	success = tgetent(0, termtype);
	env->w = tgetnum("co");
	env->h = tgetnum("li");
	env->cm = tgetstr("cm", 0);
	env->cl = tgetstr("cl", 0);
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;

	tputs(env->cl, 1, id_put);
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		write(1, '#', 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, '#', 1);
		x = x + 1;
	}
	y = 1;
	while (y < env->h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		write(1, "#", 1);
		tputs(tgoto(env->cm, env->w - 1, y), 1, id_put);
		write(1, "#", 1);
		y = y + 1;
	}
}

void	init_balle(t_env* env)
{
	srand(time(0));
	env->balle.x = (rand() % (env->w - 2)) + 1;
	env->balle.y = (rand() % (env->h - 2)) + 1;
	env->balle.addx = 1 - (rand() % 2) * 2;
	env->balle.addy = 1 - (rand() % 2) * 2;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
}

int	init(t_env* env)
{
	if (init_env(env))
		return (1);
	init_cadre(env);
	init_balle(env);
}

void	check_wall(t_env* env)
{
	int	x;
	int	y;

	x = env->balle.x + env->balle.addx;
	if (x <= 1)
		env->balle.addx = 1;
	else if (x >= env->w - 1)
		env->balle.addx = -1;
	x = env->balle.x + env->balle.addx;
	if (y <= 1)
		env->balle.addy = 1;
	else if (y >= env->h - 1)
		env->balle.addy = -1;
}

void	move_balle(t_env* env)
{
	env->balle.x = env->balle.x + env->balle.addx;
	env->balle.y = env->balle.y + env->balle.addy;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	write(1, "0", 1);
	usleep(500000);
}

int	run(t_env* env)
{
	while (1)
	{
		check_wall(env);
		move_balle(env);
	}
	return 0;
}

int	main(void)
{
	t_env	env;

	if (init(&env))
		return (42);
	if (run(&env))
		return (42);
}
