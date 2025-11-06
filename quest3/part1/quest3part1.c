#include <stdio.h>
#include <stdlib.h>

int	find_largest(int **nums)
{
	int	largest;
	int	itr;

	itr = 0;
	largest = -1;
	while (nums[itr])
	{
		if (largest <= nums[itr][0] && nums[itr][1] != 1)
		{
			largest = nums[itr][0];
		}
		itr++;
	}
	printf("This is the largest remaining number: %d\n", largest);
	return (largest);
}

void	remove_largest(int **nums, int largest)
{
	int	itr;

	itr = 0;
	while (nums[itr])
	{
		if (nums[itr][0] == largest && nums[itr][1] != 1)
		{
			nums[itr][1] = 1;
		}
		itr++;
	}
}

int	main(int argc, char **argv)
{
	int	**nums;
	int	itr;
	int	largest;
	int	result;

	if (argc <= 2)
		return (1);
	else
	{
		nums = malloc((argc - 1) * sizeof(int *));
		itr = 0;
		result = 0;
		while (itr != argc - 2)
		{
			nums[itr] = malloc(2 * sizeof(int));
			nums[itr][0] = atoi(argv[itr + 1]);
			itr++;
		}
		itr = 0;
		while (itr != argc - 2)
		{
			largest = find_largest(nums);
			if (largest == -1)
				break;
			result = result + largest;
			remove_largest(nums, largest);
			itr++;
		}
		printf("The final result after adding all the numbers above is: %d\n", result);
	}
	return (0);
}