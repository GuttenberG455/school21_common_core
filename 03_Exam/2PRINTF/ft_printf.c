# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int spec;
	int width;
	int precision;
} t_flags;
void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	ft_get_flags(const char *fstr)
{
	fstr++;
	if (fstr)
	{
		return ((char) *fstr);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int neg;
	int num;
	int i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_printf(const char *fstr, ...)
{
	int		count;
	int		spec;
	va_list	ap;

	count = 0;
	va_start(ap, fstr);
	while (*fstr)
	{
		if (*fstr == '%')
		{
			spec = ft_get_flags(fstr);
			// count += ft_print_one(ap, spec);
			ft_putchar((char) spec);
			fstr++;
			fstr++;
		}
		else
		{
			ft_putchar(*fstr);
			count++;
			fstr++;
		}
	}
	va_end(ap);
	return (count);
}