#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
// #include <ctype.h>
// #include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*str1 = "1234567890";

	printf("%s\n", ft_substr(str1, 0, 5));
	return (0);
}
