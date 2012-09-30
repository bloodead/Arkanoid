#include "base.h"
#include <stdlib.h>

void	show_mur(t_mur* begin, t_env* env)
{
	while (begin->next != 0)
	{
		tputs(tgoto(env->cm, begin->brick.x, begin->brick.y), 1, id_put);
		id_print_str("\033[01;46m ");
		id_print_str("\033[01;46m ");
		id_print_str("\033[01;46m ");
		id_print_str("\033[01;46m ");
		begin = begin->next;
	}

}

void	init_mur(t_mur* mur, t_env* env)
{
	int	numb_mur;
	t_mur* begin;
	int	x;
	int	y;

	numb_mur = (env->w / 6) - 2;
	y = 13;
	env->level.mur = (numb_mur + 1)* ((env->level.n_mur - y) / 2);
	begin = mur;
	while (y != env->level.n_mur)
	{
		numb_mur = (env->w / 6) - 2;
		x = 4;
		while (numb_mur >= 0)
		{	
			mur->brick.x = x;
			mur->brick.y = y;
			if (numb_mur == 20)
			mur->brick.bonus = 1;
			mur->next = (t_mur*)malloc(sizeof(*mur));
			mur = mur->next;
			x = x + 6;
			numb_mur = numb_mur - 1;
			
		}
	y = y + 2;
	}
	show_mur(begin, env);
}
