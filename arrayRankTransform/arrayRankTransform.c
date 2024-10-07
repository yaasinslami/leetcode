#include <stdlib.h>

typedef struct s_hash {
	int num;
	int index;
} t_hash;

int cmp(const void *a, const void *b)
{
	return (((t_hash *)a)->num - ((t_hash *)b)->num);
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
	*returnSize = arrSize;	
	int *result;

	// Handle empty array case
    if (arrSize == 0 || arr == NULL) {
        return NULL;
    }

	t_hash *pairs = (t_hash *)malloc(sizeof(t_hash) * arrSize);
	result = (int *)malloc(sizeof(int) * arrSize);
	if (!pairs || !result)
	{
		free(pairs);
		free(result);
		return (NULL);
	}

	int i = 0;
	while (i < arrSize)
	{
		pairs[i].num = arr[i];
		pairs[i].index = i;
		i++;
	}

	qsort(pairs, arrSize, sizeof(t_hash), cmp);

	int rank = 1;
	result[pairs[0].index] = rank;
	i = 1;
	while (i < arrSize)
	{
		if (pairs[i].num != pairs[i - 1].num)
		{
			rank++;
		}
		result[pairs[i].index] = rank;
		i++;
	}

	free(pairs);
	return (result);
}

#include <stdio.h>

int main()
{
	int arr[] = {40, 10, 20, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	int size = 0;
	int *result;

	result = arrayRankTransform(arr, n, &size);

	int i = 0;
	while (i < size)
	{
		printf("%d\n", result[i]);
		i++;
	}

	free(result);
	return (0);
}
