/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:50:15 by yslami            #+#    #+#             */
/*   Updated: 2024/09/08 09:50:15 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//	* Definition for singly-linked list.

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode	*create_node(int val);
void	append_node(struct ListNode **head, int val);
struct ListNode	*copy_list(struct ListNode *head, int count);
void	print_list(struct ListNode *head);
void	free_list(struct ListNode *head);
void	testFunction();

/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

/**
 * get_length - get the length of a singly linked List
 * 
 * @head: the head of the linked List
 * 
 * Return: return the length of the linked List
*/

int	get_length(struct ListNode *head)
{
	int	length;

	length = 0;
	while (head != NULL)
	{
		length++;
		head = head->next;
	}
	return (length);
}

/**
 * splitListToParts - Split a singly linked List
 * 
 * @head: the head of the input List
 * @k:	the number of parts we will split the linked List
 * @returnSize: take the size's adress of the array
 * 
 * Description: Given the head of a singly linked list and an integer k,
 * 				split the linked list into k consecutive linked list parts.
 * 
 * Return: return an array of the @k parts.
*/

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
	struct ListNode	**result;// the returned array
	int	length, size, extra, actual_size, i;

	length = get_length(head);
	i = 0;
	result = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
	if (!result)
	{
		return (NULL);
	}
	*returnSize = k;
	size = length / k;
	extra = length % k;
	while (i < k)
	{
		// now we should traverse the current pointer
		// to the end of each part
		// take considiration to extra's nodes
		actual_size = size + (i < extra ? 1 : 0);
		result[i] = copy_list(head, actual_size);
		int	j = 0;
		while (j < actual_size && head != NULL)
		{
			head = head->next;
			j++;
		}
		i++;
		/*
			// now current placed at the last node of Linekd List
			// we should save it next's reference so we can assigned to the next part
			// and break the last node of each part
			// make a condition to handle Edge Case where lenght < k
			// because we will access current->next and already we have current == NULL
			// Without this check, trying to access current->next when current is NULL-
			// would lead to a segmentation fault or runtime error.
			if (current != NULL)
			{
				dummy = current->next;
				current->next = NULL;
				current = dummy;
			}
		*/
	}
	return (result);
}

// Test the splitListToParts Function:

int main(void)
{
	testFunction();
	return (0);
}


struct ListNode	*create_node(int val)
{
	struct	ListNode	*new_node;

	new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (new_node == NULL)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(struct ListNode **head, int val)
{
	struct ListNode	*new_node;
	struct ListNode	*current;

	new_node = create_node(val);
	current = *head;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

struct ListNode	*copy_list(struct ListNode *head, int count)
{
	struct ListNode *new_head = NULL, *tail_node = NULL, *new_node;

	while (count-- && head != NULL)
	{
		// create a new node with same value as the current node in the original List
		new_node = create_node(head->val);
		if(!new_node)
			return (NULL);

		if (tail_node == NULL)
		{
			new_head = new_node;
			tail_node = new_node; // here tail_node is a pointer that hold the next node's adresse
		}
		else
		{
			tail_node->next = new_node;
			tail_node = new_node;
		}
		head = head->next;
	}
	return (new_head);
}

void	print_list(struct ListNode *head)
{
	struct ListNode	*current;

	current = head;
	printf("[");
	while (current != NULL)
	{
		printf("%d", current->val);
		current = current->next;
		if (current != NULL)
			printf(" -> ");
	}
	printf("]");
}

void	free_list(struct ListNode *head)
{
	struct ListNode *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	testFunction()
{
	struct	ListNode **result;
	struct	ListNode *head;
	int	i;

	head = NULL;
	i = 0;
	while (i < 10)
	{
		append_node(&head, i + 1);
		i++;
	}

	int	k = 3;
	int	size;
	//Call the splitListToParts function
	result = splitListToParts(head, k, &size);

	//print the singly List
	print_list(head);
	printf("\tk = %d\n\n", k);
	//print the result --> 2D array
	i = 0;
	printf("[");
	while (i < k)
	{
		//printf("Part %d: ", i + 1);
		print_list(result[i]);
		if (i < k - 1)
			printf(",");
		i++;
	}
	printf("]\n");

	// Free each part of the linked List
	i = 0;
	while (i < k)
	{
		//make a condition to handle Edge Case where lenght < k
		if (result[i] != NULL)
		{
			free_list(result[i]);
		}
		i++;
	}

	// free the array itself
	free(result);

	// Free the original singly List
	free_list(head);
}
