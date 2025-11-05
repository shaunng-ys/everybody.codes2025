#include "stdio.h"

// Cyndindor,Erassor,Mornverax,Krynnzor,Gorathindor,Myndthyris,Harnrex,Fyrcion,Naldnix,Sildar

// L1,R3,L2,R6,L1,R5,L1,R5,L2,R7,L7

int	ft_atoi(char *num_str)
{
	int	sign;
	int	i;
	int	temp;
	int	result;

	sign = 1;
	i = 0;
	temp = 0;
	result = 0;
	if (num_str[i] == '-' || num_str[i] == '+')
	{
		if (num_str[i] == '-')
			sign = -1;
		i++;
	}
	while (num_str[i])
	{
		temp = num_str[i] - '0';
		result = result * 10 + temp;
		i++;
	}
	return (result * sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	move_count(char *str)
{
	int	i;
	int	temp;
	int	result;
	
	i = 0;
	temp = 0;
	result = 0;
	while (str[i] != ',' && str[i])
	{
		temp = str[i] - '0';
		result = result * 10 + temp;
		i++;
	}
	return (result);
}

int	name_finder(char *str, int i, char dir, int moves)
{
	int	len;
	int	comma;
	int	k;

	len = ft_strlen(str);
	// printf("This is the length of the string: %d\n", len);
	comma = 0;
	if (dir == 'L')
	{
		while (i >= 0 && i <= len - 1 && comma != moves)
		{
			if (str[i] == ',')
				comma++;
			i--;
		}
		while (i >= 0 && i <= len - 1 && str[i] != ',')
			i--;
		i++;
		k = i;
		// printf("We're now at: ");
		while (str[k] != ',' && str[k])
			printf("%c", str[k++]);
		printf("\n");
	}
	if (dir == 'R')
	{
		while (i >= 0 && i <= len - 1 && comma != moves)
		{
			// printf("%c", str[i]);
			if (str[i] == ',')
				comma++;
			i++;
		}
		if (i >= len)
		{
			while (str[i] != ',' && i != 0)
				i--;
			i++;
		}
		k = i;
		// printf("We're now at: ");
		while (str[k] != ',' && str[k])
			printf("%c", str[k++]);
		printf("\n");
	}
	return (i);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		names;
	int		moves;
	char	dir;


	if (argc != 3)
		return (1);
	else
	{
		i = 0;
		j = 0;
		names = 1;
		while (argv[1][i])
		{
			if (argv[1][i] == ',')
				names++;
			i++;
		}
		// len = ft_strlen(argv[2]);
		printf("These are the %d names:\n%s\n\n%s\n", names, argv[1], argv[2]);
		while (argv[2][j])
		{
			if (argv[2][j] == 'L')
			{
				moves = move_count(argv[2] + j + 1);
				while (ft_isnum(argv[2][j]) == 0)
					j++;
				printf("\nMove left %d times = ", moves);
				i = name_finder(argv[1], i, 'L', moves);
				// printf("This is i: %d, and this is the start of the string from i: %s\n", i, argv[1] + i);
			}
			else if (argv[2][j] == 'R')
			{
				moves = move_count(argv[2] + j + 1);
				while (ft_isnum(argv[2][j]) == 0)
					j++;
				printf("\nMove right %d times = ", moves);   
				i = name_finder(argv[1], i, 'R', moves);
				// printf("This is i: %d, and this is the start of the string from i: %s\n", i, argv[1] + i);
			}
			j++;
		}
	}
	return (0);
}
