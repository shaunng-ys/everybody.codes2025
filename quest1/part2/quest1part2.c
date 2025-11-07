// Sarnnix,Zormal,Quirzrak,Zyrgyth,Briveldrin,Ascaleon,Skarfeth,Durnpyros,Calasis,Vyrkris,Arakwyris,Shaemdren,Krynnalar,Sillith,Zynardith,Draithnar,Tarlparth,Kazaxar,Ilmarnar,Nylthyris

// L5,R7,L14,R11,L15,R13,L11,R14,L19,R7,L5,R12,L5,R19,L5,R13,L5,R11,L5,R18,L7,R11,L11,R10,L16,R6,L9,R6,L15

#include <stdio.h>
#include <stdlib.h>

int	move_calculator(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == 'L')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == 'R')
		{
			sign = 1;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			result = result + (sign * atoi(str + i));
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			i++;
	}
	return (result);
}

int	name_finder(int names, int moves, char *str)
{
	int	ultimate_move;
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	//400
	if (moves >= 0)
	{
		ultimate_move = moves;
		while (ultimate_move > names)
			ultimate_move = ultimate_move - names;
	}
	//-400
	else if ((moves * -1) > names)
	{
		ultimate_move = moves * -1;
		while (ultimate_move > names)
			ultimate_move = ultimate_move - names;
		ultimate_move = names + (ultimate_move * -1);
	}
	//-4
	else if (moves < 0)
		ultimate_move = names + moves;
	printf("This is ultimately the number of moves to make: %d\n", ultimate_move);
	if (ultimate_move == 0 || ultimate_move == names)
	{
		printf("And this is the name found: ");
		while (str[i] != ',' && str[i])
				printf("%c", str[i++]);
		return (0);
	}
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma++;
			if (comma == ultimate_move)
			{
				i++;
				while (str[i] != ',' && str[i])
					printf("%c", str[i++]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	comma;
	int	moves;
	if (argc != 3)
		return (1);
	else
	{
		i = 0;
		comma = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == ',')
				comma++;
			i++;
		}
		moves = move_calculator(argv[2]);
		name_finder(comma + 1, moves, argv[1]);
	}
	return (0);
}