#include <stdio.h>
#include <stdlib.h>

void	reset(int *arr, int size)
{
	int i = 0;
	while (i < size + 1)
	{
		arr[i] = 0;
		i++;
	}
}

int shortestSequence(int* rolls, int rollsSize, int k)
{
	/* rolls = [4,2,1,2,3,3,2,4,1], k = 4 */
	int	i, count = 0, countUniq = 0;
	int	*seem;
	int resetMarker = 0;

	seem = (int *) calloc(k + 1, sizeof(int));
	if (!seem)
		return (0);

	i = 0;
	while (i < rollsSize)
	{
		if (seem[rolls[i]] <= resetMarker)
		{
			seem[rolls[i]] = resetMarker + 1;
			countUniq++;
		}
		if (countUniq == k)
		{
			count++;
			countUniq = 0;
			resetMarker++;
		}
		i++;
	}

	free(seem);
	return (count + 1);
}

int main(void)
{
	int	rolls[] = {4,2,1,2,3,3,2,4,1};
	int rollsSize = sizeof(rolls) / sizeof(int);

	printf("%d\n", shortestSequence(rolls, rollsSize, 4));
	return (0);
}
