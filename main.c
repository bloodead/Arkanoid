#include <stdarg.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <term.h>
#include "base.h"


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

int	init(t_env* env)
{
	if (init_env(env))
		return (1);
	init_cadre(env);
	init_balle(env);
	init_barre(env);
}

int	run(t_env* env)
{
	sleep(10);
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
