#include <term.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <stdarg.h>
#include "base.h"

int	id_put(int c)
{
	char	d;

	d = c;
	write(1, &d, 1);
}

int	init_env(t_env* env)
{
	char*	termtype = getenv("TERM");
	int	success;

	success = tgetent(0, termtype);
	env->w = tgetnum("co");
	env->h = tgetnum("li");
	env->cm = tgetstr("cm", 0);
	env->cl = tgetstr("cl", 0);
	tputs(tgetstr("vi", 0), 1, id_put);
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	tputs(env->cl, 1, id_put);
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		write(1, ".", 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, ".", 1);
		x = x + 1;
	}
	y = 1;
	while (y < env->h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		write(1, "#", 1);
		tputs(tgoto(env->cm, env->w, y), 1, id_put);
		write(1, "#", 1);
		y = y + 1;
	}
}
