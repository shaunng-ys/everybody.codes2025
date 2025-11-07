// more teeth = more power

// Therefore if 2 times more teeth than the smaller one, the smaller will generate 2 times more turns

// divide each other I guess

// 102 / 13 = 

// ./a.out 128 64 32 16 8

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	float	turns;
	float	multiplier;
	int		result;

	if (argc < 3)
		return (1);
	else
	{
		i = 1;
		turns = 2025;
		while (i < argc)
		{
			if (i + 1 == argc)
				break;
			multiplier = (float)atoi(argv[i]) / (float)atoi(argv[i + 1]);
			printf("This is the current multiplier: %f\n", multiplier);
			printf("The current gear, gear #%d takes %f turns\n", i, turns);
			turns = turns * multiplier;
			printf("Thus, the next gear over, gear #%d takes %f turns\n\n", ++i, turns);
		}
		result = turns;
		printf("Based on the sequence of gears, the final gear takes %d turns!\n", result);
	}
	return (0);
}