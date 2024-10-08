#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

long long dividePlayers(int* skill, int skillSize)
{
	long long result = 0;
	int total_sum = 0;

	for (int i = 0; i < skillSize; i++)
	{
		total_sum += skill[i];
	}

	// if There is no way to divide the players into
	// teams such that the total skill of each team is equal.
	if (total_sum % (skillSize / 2) != 0)
	{
		return (-1);
	}

	const int target_sum = total_sum / (skillSize / 2);

	// sort the nums array
	qsort(skill, skillSize, sizeof(int), compare);

	int left = 0;
	int right = skillSize - 1;
	while (left <= right)
	{
		int team_sum = skill[left] + skill[right];
		if (team_sum != target_sum)
			return (-1);

		// Add the chemistry of the team (product of skills) to the result
		result += (long long)skill[left] * skill[right];

		left++;
		right--;
	}

	return (result);
}

#include <stdio.h>

int main()
{
	int skill[] = {1, 1, 2, 3};
	int skillSize = sizeof(skill) / sizeof(skill[0]);

	long long result = dividePlayers(skill, skillSize);
	printf("%lld\n", result);
}
