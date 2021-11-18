#include <stdio.h>

int	ft_printf(const char *fstr, ...);

int	main(void)
{
	int				count = 0;
	int				dec = 143100;
	int				lowest = -2147483648;
	char			*str = "StRoKa";
	int				hexa = 0xf0a01;


	count = ft_printf("FIVE-%d");
	printf("\n[%d] - len\n", count);

}