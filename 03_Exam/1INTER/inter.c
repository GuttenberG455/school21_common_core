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

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !used[(unsigned char) argv[i][j]])
					used[(unsigned char) argv[i][j]] = 1;
				else if (i == 1 && used[(unsigned int) argv[i][j]] == 1)
				{
					putchar(argv[i][j]);
					used[(unsigned char) argv[i][j]] = 2;
				}
				j++;
			}
		i--;
		}
	}
	putchar('\n');
	return (0);
}