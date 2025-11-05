#include <stdio.h>
#include <stdlib.h>

void	add_complex(int *result, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = result[0];
	y1 = result[1];
	result[0] = x1 + x2;
	result[1] = y1 + y2;
}

void	multiply_complex(int *result)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = result[0];
	y1 = result[1];
	x2 = result[0];
	y2 = result[1];
	result[0] = x1 * x2 - y1 * y2;
	result[1] = x1 * y2 + y1 * x2;
}

void	div_complex(int *result)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = result[0];
	y1 = result[1];
	x2 = 10;
	y2 = 10;
	result[0] = x1 / x2;
	result[1] = y1 / y2;
}

void	cycle(int *result, int x2, int y2)
{
	printf("[%d, %d] * [%d, %d] = ", result[0], result[1], result[0], result[1]);
	multiply_complex(result);
	printf("[%d, %d]\n", result[0], result[1]);
	printf("[%d, %d] / [%d, %d] = ", result[0], result[1], 10, 10);
	div_complex(result);
	printf("[%d, %d]\n", result[0], result[1]);
	printf("[%d, %d] + [%d, %d] = ", result[0], result[1], x2, y2);
	add_complex(result, x2, y2);
	printf("[%d, %d]\n", result[0], result[1]);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*result;

	if (argc != 3)
		return (1);
	else
	{
		i = 1;
		result = malloc(2 * sizeof(int));
		while (i <= 3)
		{
			printf("\nCycle %d\n", i);
			cycle(result, atoi(argv[1]), atoi(argv[2]));
			i++;
		}
		printf("\nThe final result is: [%d,%d]\n", result[0], result[1]);
	}
	return (0);
}