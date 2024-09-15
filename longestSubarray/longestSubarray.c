int max_num(int *arr, int size)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return (max);
}

int	longestSubarray(int* nums, int numsSize)
{
	int	max, i = 0, max_length = 0, current_length = 0;

	max = max_num(nums, numsSize);
	while (i < numsSize)
	{
		if (nums[i] == max)
		{
			current_length++;
			if (current_length > max_length)
			{
				max_length = current_length;
			}
		}
		else
		{
			current_length = 0;
		}
		i++;
	}
	return (max_length);
}

/*
#include <stdio.h>

int main()
{
  int arr[7] = {3, 3, 2, 3, 3, 3, 0};

  printf("%d\n", longestSubarray(arr, 7));
  return (0);
}
*/
