#include <stdarg.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <term.h>
#include "base.h"

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
	tputs(tgetstr("vi", 0), 1, id_put);
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	tputs(env->cl, 1, id_put);
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		write(1, ".", 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, ".", 1);
		x = x + 1;
	}
	y = 1;
	while (y < env->h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		write(1, "#", 1);
		tputs(tgoto(env->cm, env->w, y), 1, id_put);
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
	init_barre(env);
}

void	check_wall(t_env* env)
{
	int	x;
	int	y;

	x = env->balle.x + env->balle.addx;
	if (x <= 0)
		env->balle.addx = 1;
	else if (x >= env->w - 1)
		env->balle.addx = -1;
	y = env->balle.y + env->balle.addy;
	if (y <= 0)
		env->balle.addy = 1;
	else if (y >= env->h - 1)
		env->balle.addy = -1;
	if (y == env->barre.y  && x >= env->barre.x && x <= env->barre.size)
		env->balle.addy = -1;
}

void	move_balle(t_env* env)
{
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	write(1, " ", 1);
	env->balle.x = env->balle.x + env->balle.addx;
	env->balle.y = env->balle.y + env->balle.addy;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	write(1, "0", 1);
	usleep(40000);
}

int	run(t_env* env)
{
	while (1)
	{
		move_barre(env);
		check_wall(env);
		move_balle(env);
	}
	return 0;
}

int	main(void)
{
	t_env	env;

	init(&env);
	run(&env);
}
