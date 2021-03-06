#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "base.h"

int	id_put(int c)
{
	char	d;

	d = c;
	write(1, &d, 1);
	return 0;
}

int	init_env(t_env* env)
{
	char*	termtype = getenv("TERM");
	int	success;

	success = tgetent(0, termtype);
	if (success == 0)
		return 0;
	env->w = tgetnum("co");
	env->h = tgetnum("li");
	env->cm = tgetstr("cm", 0);
	env->cl = tgetstr("cl", 0);
	env->player.point = 0;
	env->bonus = 0;
	tputs(tgetstr("vi", 0), 1, id_put);
	env->level.lvl = 0;
	env->level.n_mur = 17;
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;

	tputs(env->cl, 1, id_put);
	tputs(tgoto(env->cm, 0, 0), 1, id_put);
	id_print_str("\033[22;32mPlayer Score: ");
	id_print_nbr(env->player.point);
	tputs(tgoto(env->cm, 0, 1), 1, id_put);
	id_print_str("\033[22;32mLevel: ");
	id_print_nbr(env->level.lvl);
	
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 4), 1, id_put);
		write(1, ".", 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, ".", 1);
		x = x + 1;
	}
	y = 5;
	while (y < env->h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		write(1, "#", 1);
		tputs(tgoto(env->cm, env->w, y), 1, id_put);
		write(1, "#", 1);
		y = y + 1;
	}
}



void	resize_env(t_env* env,t_mur* mur)
{
	struct	winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	if (env->w != w.ws_col || env->h != w.ws_row)
	{
	env->w = w.ws_col;
	env->h = w.ws_row;
	init_cadre(env);
	show_mur(mur, env);
	init_barre(env);
	}
}
