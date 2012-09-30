#include "base.h"


void	bonus(t_mur* mur, t_env* env)
{
	
	env->bonusx = mur->brick.x;
	env->bonusy = mur->brick.y;

	env->bonus = 1;
}


void	bonus_down(t_env* env)
{

		tputs(tgoto(env->cm, env->bonusx, env->bonusy - 1), 1, id_put);
		id_print_char(' ');
		tputs(tgoto(env->cm, env->bonusx, env->bonusy), 1, id_put);
		id_print_char('#');
		env->bonusy =  env->bonusy + 1;
		
	if ( env->bonusy == env->h - 1)
		env->bonus = 0;
}
