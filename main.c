#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include "base.h"


void	finish(t_env* env)
{
	int	x;
	int	y;
	t_mur	mur;

	x = env->w / 2;
	y = env->h / 2;
	tputs(tgoto(env->cm, x - 11, y), 1, id_put);
	id_print_str("Niveau suivant...");
	sleep(3);
	env->level.lvl = env->level.lvl + 1;
	env->level.n_mur = env->level.n_mur + 2;
	init_cadre(env);
	init_mur(&mur, env);
	init_balle(env);
	init_barre(env);
	tputs(tgoto(env->cm, 0, 1), 1, id_put);
	id_print_str("\033[22;32mLevel: ");
	id_print_nbr(env->level.lvl);
	sleep(3);
	run(env, &mur);
}


void	destroy_brick(t_mur* mur, t_env* env)
{
	int	x;
	int	count;

	count = 0;
	x = mur->brick.x;
	while (count != 4)
	{
		tputs(tgoto(env->cm, x, mur->brick.y), 1, id_put);
		id_print_str("\033[01;40m ");
		count = count + 1;
		x = x + 1;
	}
	mur->brick.y = -1;
	mur->brick.x = -1;
	env->level.mur = env->level.mur - 1;
	if (env->level.mur == 0)
	{
		free(mur);
		finish(env);
	}
}


void	actu_score(t_env* env)
{
	int	x;

	x = 0;
	env->player.point = env->player.point + 10;
	while (x != env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		id_print_char(' ');
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
	coli_brick(env, mur);
}

int	init(t_env* env, t_mur* mur)
{
	if (init_env(env))
		return (1);
	init_cadre(env);
	init_mur(mur, env);
	init_balle(env);
	init_barre(env);
	return 0;
}

int	run(t_env* env, t_mur* mur)
{
	start_wait(env,4);
	while (1)
	{
		if (env->bonus == 1)
			bonus_down(env);
		move_balle(env);
		move_barre(env);
		check_wall(env, mur);
		resize_env(env, mur);
	}
	return 0;
}

int	main(void)
{
	t_env	env;
	t_mur	mur;

	init(&env, &mur);
	run(&env, &mur);
	return 0;
}
