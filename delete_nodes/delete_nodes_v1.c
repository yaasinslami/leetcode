/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_nodes_v1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 04:18:03 by yslami            #+#    #+#             */
/*   Updated: 2024/09/08 04:18:03 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100001 //  100001 <==> 10^5 + 1

//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * set_hash_table - Fills a boolean hash table with true values for
 *                  elements present in the given array.
 * @hash_table: Boolean array used as the hash table.
 * @arr: Array of integers whose presence needs to be tracked.
 * @size: Size of the array.
*/

void	set_hash_table(bool	*hash_table, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		hash_table[arr[i]] = true;
		i++;
	}
}

/**
 * modifiedList - Removes nodes from the linked list whose values are present
 *                in the given array.
 * @nums: Array of integers indicating values to be removed.
 * @numsSize: Size of the nums array.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Pointer to the modified linked list with specified nodes removed.
*/

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head)
{
	bool	hash_table[MAX_SIZE] = {false};
	set_hash_table(hash_table, nums, numsSize);

	
	struct ListNode	*dummy;// temporally node to handle the removed head cas
	dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!dummy)
	{
		return (NULL);
	}
	dummy->next = head;
	struct ListNode	*dummy_pointer;
	dummy_pointer = dummy;//dummy_pointer moves independently and adjusts the connections between nodes as needed
	struct ListNode	*current = head; // pointer that will move on List
	while (current != NULL)
	{
		if (hash_table[current->val]) //true mean we should removing the current val <==> moves dummy_pointer to the next step
		{
			dummy_pointer->next = current->next;
		}
		else
		{
			dummy_pointer = current;
		}
		current = current->next;//always we moving the current pointer
	}
	struct ListNode	*result;// the resulted List
	result = dummy->next;
	free(dummy);
	return (result);
}
