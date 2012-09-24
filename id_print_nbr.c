void	id_print_char(char c);

void    id_print_nbr(int n)
{
        int     divisor;
        int     negative;

        divisor = 1;
        negative = 0;
        if (n < 0)
        {
                id_print_char('-');
                n = -n - 1;
                negative = 1;
        }
        while (n / divisor > 9)
        {
                divisor = divisor * 10;
        }
        while (divisor >= 1)
        {
                if (negative == 1 && divisor == 1)
                {
                        id_print_char(n / divisor % 10 + '1');
                }
                else
                {
                        id_print_char(n / divisor % 10 + '0');
                }
                divisor = divisor / 10;
        }
        id_print_char(' ');
}

