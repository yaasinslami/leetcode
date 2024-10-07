#include <stdlib.h>

typedef struct HashNode {
	int key;
	int value;
	struct HashNode *next;
} HashNode;

typedef struct HashMap
{
	int size;
	HashNode **table;
} HashMap;

// Hash function
unsigned int hash(int key, int size) {
    return (unsigned int)(key % size);
}

HashMap *createHashMap(int size)
{
	HashMap *map = (HashMap *)malloc(sizeof(HashMap));
	if (!map)
		return (NULL);

	// for the pointers array that hold the linked lists head
	map->table = (HashNode **)malloc(size * sizeof(HashNode *));
	if (!map->table)
	{
		free(map);
		return (NULL);
	}

	map->size = size;
	for (int i = 0; i < size; i++)
	{
		map->table[i] = NULL;
	}

	return (map);
}

void insertHashMap(HashMap *map, int key, int value)
{
	int idx = hash(key, map->size);
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	if (!node)
		return;
	node->key = key;
	node->value = value;
	node->next = map->table[idx];
	map->table[idx] = node;
}

int getHashMap(HashMap *map, int key)
{
	int idx = hash(key, map->size);
	HashNode *node = map->table[idx];
	while (node)
	{
		if (node->key == key)
		{
			return (node->value);
		}
		node = node->next;
	}

	// the key was not founded
	return (-2);
}

void freeHashMap(HashMap *map)
{
	for (int i = 0; i < map->size; i++)
	{
		HashNode *node = map->table[i];
		while (node)
		{
			HashNode *temp = node;
			node = node->next;
			free(temp);
		}
	}
	free(map->table);
	free(map);
}

int minSubarray(int* nums, int numsSize, int p)
{
	int total_sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		total_sum += nums[i];
	}

	int remain_target = total_sum % p;

	// check if the total_sum already divide p, so we return 0
	if (remain_target == 0)
	{
		return (0);
	}

	int size = numsSize > 100 ? numsSize : 100;
	HashMap *map = createHashMap(size);

	// Initialize for prefix sum modulo 0
	insertHashMap(map, 0, -1);

	int currSum = 0;
	int minLen = numsSize;
	for (int i = 0; i < numsSize; i++)
	{
		currSum = (currSum + nums[i]) % p;

		// Calculate the required modulo value to remove a valid subarray
		int requiredMod = (currSum - remain_target + p) % p;

		// check if the requiredMod exist in the HashMap
		int requiredIdx = getHashMap(map, requiredMod);
		if (requiredIdx != -2)
		{
			minLen = (i - requiredIdx < minLen) ? i - requiredIdx : minLen;
		}
		insertHashMap(map, currSum, i);
	}

	freeHashMap(map);
	return (minLen < numsSize ? minLen : -1);
}

#include <stdio.h>

int main()
{
	int nums[] = {3, 1, 4, 2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	int result = minSubarray(nums, numsSize, 6);
	printf("%d\n", result);
	return (0);
}