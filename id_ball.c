#include "base.h"

void	init_balle(t_env* env)
{
	srand(time(0));
	env->balle.x = (env->w / 2) - ((env->w / 100) * 3);
	env->balle.y = 5 * (env->h / 6) - 1;
	env->balle.addx = 1 - (rand() % 2) * 2;
	env->balle.addy = -1;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	id_print_str("\033[01;40m0");
}

void	move_balle(t_env* env)
{
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	id_print_str("\033[01;40m ");
	env->balle.x = env->balle.x + env->balle.addx;
	env->balle.y = env->balle.y + env->balle.addy;
	tputs(tgoto(env->cm, env->balle.x, env->balle.y), 1, id_put);
	id_print_str("\033[01;40m0");
	usleep(50000);
}
