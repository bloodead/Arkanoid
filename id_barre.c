#include "base.h"

void	init_barre(t_env* env)
{
	int	x;

	env->barre.x = (env->w / 2) - ((env->w / 100) * 7);
	env->barre.y = 5 * (env->h / 6);
	env->barre.size = (env->w / 2) + ((env->w / 100) * 3);
	x = env->barre.x;
	while (x < env->barre.size)
	{
		tputs(tgoto(env->cm, x, env->barre.y), 1, id_put);
		write(1,"=", 1);
		x = x + 1;
	}
}

void	actua_barre(t_env* env, int direct)
{
	int	x;
	int	count;

	count = 3;
	x = env->barre.x;
	while (x < env->barre.size)
	{
		while (count >= 0)
		{
			if(direct < 0)
			{
				tputs(tgoto(env->cm, env->barre.x - count, env->barre.y), 1, id_put);
				write(1, " ", 1);
			}
			if(direct > 0)
			{
				tputs(tgoto(env->cm, env->barre.size + count, env->barre.y), 1, id_put);
				write(1, " ", 1);
			}
			count = count - 1;
		}
		tputs(tgoto(env->cm, x, env->barre.y), 1, id_put);
		write(1,"=", 1);
		x = x + 1;
	}
}

void	verif_box(t_env* env)
{
	if (env->barre.x < 0)
	{
		while (env->barre.x != 1)
		{
			env->barre.x = env->barre.x + 1;
			env->barre.size = env->barre.size + 1;
		}
	}
	else if (env->barre.size > env->w)
	{
		while (env->barre.size != env->w - 2)
		{
			env->barre.x = env->barre.x - 1;
			env->barre.size = env->barre.size - 1;
		}
	}
}


void	move_barre(t_env* env)
{
	int	y;
	int	direct;

	direct = 0;
	y = env->balle.addy;
	if (y == 1 && (env->balle.x < env->barre.x + 3 || env->balle.x > env->barre.size - 3 )
		       && env->balle.y < env->barre.y - 1)
	{
		direct =  (env->barre.x + ((env->w / 100) * 4)) - env->balle.x;
		if (direct > 0)
		{
			env->barre.size = env->barre.size - 3;
			env->barre.x = env->barre.x - 3;
			verif_box(env);
			actua_barre(env, direct);
		}
		if(direct < 0)
		{
			env->barre.x = env->barre.x + 3;
			env->barre.size = env->barre.size + 3;
			verif_box(env);
			actua_barre(env, direct);
		}
	}
}
