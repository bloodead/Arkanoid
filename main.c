#include <stdarg.h>
#include <stdlib.h>
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
	 mur->brick.y = -1;
	 mur->brick.x = -1;

}


void	actu_score(t_env* env)
{
	int	x;

	x = 0;
	env->player.point = env->player.point + 10;
	while (x != env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		write(0,' ',1);
		x = x + 1;
	}
	tputs(tgoto(env->cm, 0, 0), 1, id_put);
	id_print_str("\033[22;32mPlayer Score: ");
	id_print_nbr(env->player.point);
	

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
	if (y <= 5)
		env->balle.addy = 1;
	else if (y >= env->h - 1)
		env->balle.addy = -1;
	if (y == env->barre.y  && x >= env->barre.x && x <= env->barre.size)
		env->balle.addy = -1;
	while (mur->next != 0)
	{
		if (y == mur->brick.y + 1 || y == mur->brick.y - 1)
			if (x >= mur->brick.x && x < mur->brick.x + 4)
			{
				if (mur->brick.bonus == 1)
					bonus(mur,env);
				destroy_brick(mur, env);
				actu_score(env);
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
	start_wait(env,10);
	while (1)
	{
		if (env->bonus == 1)
			bonus_down(mur, env);
		move_barre(env);
		check_wall(env, mur);
		resize_env(env, mur);
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
