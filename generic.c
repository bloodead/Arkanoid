#include "base.h"



void	start_wait(t_env* env, int i)
{
	int	x;
	int	y;

	x = env->w / 2;
	y = env->h / 2;
	tputs(tgoto(env->cm, x - 11, y), 1, id_put);
	id_print_str("La partie va commencer");
	i = i - 1;
	while (i != 0)
	{
		tputs(tgoto(env->cm, x, y + 1), 1, id_put);
		write(0,' ',1);
		tputs(tgoto(env->cm, x, y + 1), 1, id_put);
		id_print_nbr(i);
		i = i - 1;
		sleep(1);
	}
	tputs(tgoto(env->cm, x, y + 1), 1, id_put);
	id_print_str("    ");
	tputs(tgoto(env->cm, x - 11, y), 1, id_put);
	id_print_str("                      ");
}
