#include "base.h"

void	init_balle(t_env* env)
{
	srand(time(0));
	env->balle.x = (rand() % (env->w - 2)) + 1;
	env->balle.y = (rand() % (env->h - 2)) + 1;
	env->balle.addx = 1 - (rand() % 2) * 2;
	env->balle.addy = 1 - (rand() % 2) * 2;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
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
