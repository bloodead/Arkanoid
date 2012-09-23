#include "base.h"
#include <stdlib.h>

void	show_mur(t_mur* begin, t_env* env)
{
	while (begin->next != 0)
	{
		tputs(tgoto(env->cm, begin->brick.x, begin->brick.y), 1, id_put);
		write(1, "*", 1);
		write(1, "-", 1);
		write(1, "-", 1);
		write(1, "*", 1);
		begin = begin->next;
	}

}

void	init_mur(t_mur* mur, t_env* env)
{
	int	numb_mur;
	t_mur* begin;
	int	x;
	int	y;

	y = 6;
	begin = mur;
	while (y != 10)
	{
		numb_mur = (env->w / 4) - 2;
		x = 2;
		while (numb_mur >= 0)
		{	
			mur->brick.x = x;
			mur->brick.y = y;
			mur->next = (t_mur*)malloc(sizeof(*mur));
			mur = mur->next;
			x = x + 4;
			numb_mur = numb_mur - 1;
		}
	y = y + 1;
	}
	show_mur(begin, env);
}
