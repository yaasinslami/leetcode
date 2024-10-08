
#define MAX_SIZE 1000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long dividePlayers(int* skill, int skillSize)
{
	int countMap[MAX_SIZE + 1] = {0};
	long long total_sum = 0;

	for (int i = 0; i < skillSize; i++)
	{
		total_sum += skill[i];
		countMap[skill[i]]++;
	}

	if (total_sum % (skillSize / 2) != 0) return (-1);

	int target_sum = total_sum / (skillSize / 2);
	long long result = 0;

	for (int i = 1; i <= MIN(MAX_SIZE, target_sum - 1); i++)
	{
		if (countMap[i] > 0)
		{
			int complement = target_sum - i;
			if (complement > MAX_SIZE || (i == complement && countMap[i] < 2) || countMap[complement] == 0)
			{
				return (-1);
			}

			int pairs = (i == complement) ? countMap[i] / 2 : MIN(countMap[i], countMap[complement]);
			result += (long long)pairs * i * complement;
			countMap[i] -= pairs;
			countMap[complement] -= pairs;
		}
	}
	return (result);
}

#include <stdio.h>

int main()
{
	int skill[] = {1, 1};
	int skillSize = sizeof(skill) / sizeof(skill[0]);

	long long result = dividePlayers(skill, skillSize);
	printf("%lld\n", result);

	return (0);
}
