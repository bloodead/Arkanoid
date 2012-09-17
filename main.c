#include <stdarg.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

typedef struct s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
}	t_env;

int	id_put(int c)
{
	char	d;

	d = c
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
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;

	tputs(env->cl, 1, id_put)
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		write(1, '#', 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, '#', 1);
		x = x + 1;
	}
	y = 1;
	while (y

int	init(t_env* env)
{
	if (init_env(env))
		return 1;
	init_cadre(env);
}

int	run(t_env* env)
{
	return 0;
}

int	main(void)
{
	t_env	env;

}
