#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int	i;
	int	j;
	int	*arr;

	*returnSize = 2;
	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < numsSize - 1)
	{
		j = i + 1;
		while(j < numsSize)
		{
			if (nums[i] + nums[j] == target)
			{
				arr[0] = i;
				arr[1] = j;
				*returnSize = 2;
				return (arr);
			}
			j++;
		}
		i++;
	}
	*returnSize = 0;
	return (arr);
}
/*
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
*/
