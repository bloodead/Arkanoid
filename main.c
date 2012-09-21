#include <stdarg.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <term.h>
#include "base.h"



void	destroy_brick(t_mur* mur, t_env* env)
{
	int	x;
	int	count;

	count = 0;
	x = mur->brick.x;
	while (count != 4)
	{
		tputs(tgoto(env->cm, x, mur->brick.y), 1, id_put);
		write(1, " ", 1);
		count = count + 1;
		x = x + 1;
	}
	 mur->brick.y = 0;
	 mur->brick.x = 0;

}

void	check_wall(t_env* env, t_mur* mur)
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
	while (mur->next != 0)
	{
		if (y == mur->brick.y)
			if (x >= mur->brick.x && x < mur->brick.x + 4)
			{
				destroy_brick(mur, env);
				env->balle.addy = 1;
				break;
			}
		mur = mur->next;
	}
		
}

int	init(t_env* env, t_mur* mur)
{
	if (init_env(env))
		return (1);
	init_cadre(env);
	init_mur(mur, env);
	init_balle(env);
	init_barre(env);
}

int	run(t_env* env, t_mur* mur)
{
	sleep(10);
	while (1)
	{
		move_barre(env);
		check_wall(env, mur);
		move_balle(env);
	}
	return 0;
}

int	main(void)
{
	t_env	env;
	t_mur	mur;

	init(&env, &mur);
	run(&env, &mur);
}
