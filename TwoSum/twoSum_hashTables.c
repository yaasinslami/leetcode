/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twoSum_hashTables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:18:41 by marvin            #+#    #+#             */
/*   Updated: 2024/09/05 11:18:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

typedef struct
{
	int key;
	int value;
} hashMap;

int	hashFunction(int key, int size)
{
	int	abs;

	abs = key <= 0 ? key * -1 : key;
	return (abs % size);
}

void	insert(hashMap *map, int size, int key, int value)
{
	int	index;

	index = hashFunction(key, size);
	while (!(map[index].key == INT_MAX || map[index].key == key))
	{
		//handles linear probing, which is a collision resolution technique.
		/*The % size ensures that if the index reaches the end of the array (i.e., index == size),
		it wraps around to the beginning of the array, making the search circular*/
		index = (index + 1) % size;
	}
	map[index].key = key;
	map[index].value = value;
}

int	search(hashMap *map, int size, int key)
{
	int	index;

	index = hashFunction(key, size);
	while(map[index].key != INT_MAX)
	{
		if (map[index].key == key)
		{
			return (map[index].value);
		}
		index = (index + 1) % size;
	}
	return (-1);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	hashMap	*map;
	int	*arr;
	int	mapSize;
	int	compliment;
	int	complimentIndex;
	int	i;

	mapSize = numsSize * 2;
	map = (hashMap *)malloc(sizeof(hashMap) * mapSize);
	if (!map)
	{
		free(map);
		return (NULL);
	}
	// initialize the hashTable with key = INT_MAX to indicate its empty slot
	i = 0;
	while (i < mapSize)
	{
		map[i].key = INT_MAX;
		i++;
	}
	*returnSize = 2;
	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	while (i < numsSize)
	{
		compliment = target - nums[i];
		complimentIndex = search(map, mapSize, compliment);
		if (complimentIndex != -1)
		{
			arr[0] = complimentIndex;
			arr[1] = i;
			free(map);
			return (arr);
		}
		insert(map, mapSize, nums[i], i);
		i++;
	}
	// this point will never be achieved because there is at least one solution
	free(map);
	return arr;
}
/*
#include <stdio.h>

int	main()
{
	int	tab[] = {2, 7, 10, 6};
	int	*arr;
	int	i;
	int	size;

	arr = twoSum(tab, 4, 13, &size);
if (!arr)
	{
		free(arr);
		return (0);
	}
	i = 0;
	printf("result[] = { ");
	while (i < size)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf(" }\n");
	return (0);
}
*/
