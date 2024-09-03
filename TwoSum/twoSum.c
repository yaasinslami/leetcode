#include <stdlib.h>

int	check_sum(int n1, int n2, int target)
{
	if (n1 + n2 == target)
		return (1);
	return (0);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int	i;
	int	j;
	int	T;
	int	*arr;

	*returnSize = 2;
	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
		return (NULL);
	i = 0;
	T = 0;
	while (i < numsSize)
	{
		j = i;
		while(j < numsSize)
		{
			if (check_sum(nums[i], nums[j], target) && i != j)
			{
				arr[0] = i;
				arr[1] = j;
				T = 1;
			}
			j++;
		}
		if (T)
			break;
		i++;
	}
	return (arr);
}

#include <stdio.h>

int main()
{
  int tab[] = {1, 8, 6, 9, 5, 13, 4};
  int *arr;
  int size;
  int i;

  arr = twoSum(tab, 7, 11, &size);
  i = 0;
  while (i < size)
  {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
  return (0);
}





