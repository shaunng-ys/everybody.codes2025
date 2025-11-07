#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	long double	turns;
	long double	divisor;
	// long long	result;

	if (argc < 3)
		return (1);
	else
	{
		i = argc - 1;
		turns = 10000000000000;
		while (i > 1)
		{
			if (i == 1)
				break;
			divisor = (long double)atoi(argv[i]) / (long double)atoi(argv[i - 1]);
			printf("This is the current divisor: %Lf\n", divisor);
			printf("The current gear, gear #%d takes %Lf turns\n", i, turns);
			turns = turns * divisor;
			printf("Thus, the next gear over, gear #%d takes %Lf turns\n\n", --i, turns);
		}
		// result = turns;
		printf("Based on the sequence of gears, the first gear takes %Lf turns!\n", turns);
	}
	return (0);
}