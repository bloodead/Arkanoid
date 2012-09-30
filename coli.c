#include "base.h"


void	coli_brick(t_env* env, t_mur* mur)
{
	int	x;
	int	y;

	x = env->balle.x + env->balle.addx;
	y = env->balle.y + env->balle.addy;
	while (mur->next != 0)
	{
		if (x >= mur->brick.x - 1 && x <= mur->brick.x + 4)
			if (env->balle.addy == -1 && y == mur->brick.y)
			{
				if (mur->brick.bonus == 1)
					bonus(mur,env);
				destroy_brick(mur, env);
				actu_score(env);
				env->balle.addy = 1;
				break;
			}
		if ( env->balle.addy == 1 && y == mur->brick.y)
			if (x >= mur->brick.x - 1 && x <= mur->brick.x + 4)
			{
				if (mur->brick.bonus == 1)
					bonus(mur,env);
				destroy_brick(mur, env);
				actu_score(env);
				env->balle.addy = -1;
				break;
			}
		mur = mur->next;
	}
}
