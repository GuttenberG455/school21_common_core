#include <unistd.h>

void	putchar(char ch)
{
	write(1, &ch, 1);	
}

int	main(int argc, char **argv)
{
	int	used[255];
	int i;
	int j;

	if (argc == 3 )
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!used[(unsigned char) argv[i][j]])
				{
					used[(unsigned char) argv[i][j]] = 1;
					putchar(argv[i][j]);
				}
				j++;
			}
		i++;
		}
	}
	putchar('\n');
	return (0);
}