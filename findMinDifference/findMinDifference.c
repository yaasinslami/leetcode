#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int		convert_to_minutes(char *time);
void	minutes_sort(int *, int);

int		compare(const void *a,const void *b)
{
  return (*(int *)a - *(int *)b);
}

int	findMinDifference(char** timePoints, int timePointsSize)
{
	int *minutes, i, diff, minimum;

	// allocate an array to store the total_minutes of each string
	minutes = (int *)malloc(sizeof(int) * timePointsSize);
	if (!minutes)
		return (-1);

	// stote each total_minutes in minutes array
	i = 0;
	while (i < timePointsSize)
	{
		minutes[i] = convert_to_minutes(timePoints[i]);
		i++;
	}

	// now, lets sort the minutes array
	//minutes_sort(minutes, timePointsSize);
	qsort(minutes, timePointsSize, sizeof(int), compare);

	// iterate inside minutes array and get the mimimum
	minimum = INT_MAX;
	i = 0;
	while (i < timePointsSize - 1)
	{
		diff = minutes[i + 1] - minutes[i];
		if (diff < minimum)
			minimum = diff;
		i++;
	}

	// handle 00:00 case
	int wrap_around_diff = (1440 - minutes[timePointsSize - 1]) + minutes[0];
	if (wrap_around_diff < minimum)
	{
		minimum = wrap_around_diff;
	}
	free(minutes);
	return (minimum);
}

int	convert_to_minutes(char *time)
{
	int	hours, minutes, result;

	hours = (time[0] - '0') * 10 + time[1] - '0';
	minutes = (time[3] - '0') * 10 + time[4] - '0';

	// result now is total minutes
	result = (hours * 60) + minutes;
	return (result);
}

/*
void	minutes_sort(int *arr, int size)
{
	int *P1, *P2;

	P1 = arr;
	while (P1 < arr + size - 1)
	{
		P2 = P1 + 1;
		while (P2 < arr + size)
		{
			if (*P1 > *P2)
			{
				int tmp = *P1;
				*P1 = *P2;
				*P2 = tmp;
			}
			P2++;
		}
		P1++;
	}
}
*/
int main()
{
	char *str[2] = {"23:30", "00:00"};

	printf("%d\n", findMinDifference(str, 2));
	return (0);
}

