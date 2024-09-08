/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:23:41 by yslami            #+#    #+#             */
/*   Updated: 2024/09/07 21:23:41 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};


/**
 * exist_check - checking function for existing of a number in an array.
 * 
 * @arr: the input array of numbers.
 * @size: size of the @arr array.
 * @num: the number that we will check if exist in @arr or not.
 * 
 * Description: check for each number in the linked_list if is it exist or not.
 * 
 * Return: return 1 if @num doesnt exist in @arr, otherwise 0.
*/

int	exist_check(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

/**
 * create_node - Function that create a node and assigning to it the @num
 * 
 * @num = number from head that will be stored.
 * 
 * Description: allocing memory for a node then assigning to it a number that's exist in the array.
 * 
 * Return: the malloced node.
 */

struct ListNode	*create_node(int num)
{
	struct ListNode	*new_node;

	new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!new_node)
		return (NULL);
	new_node->val = num;
	new_node->next = NULL;
	return (new_node);
}

/**
 * append_node - Function that append the malloced node.
 * 
 * @head: a pointer to the pointer that point to a node
 * @num: number that will be added to created node
 * 
 * Description: append the malloced node to the result List.
*/

void	append_node(struct ListNode **head, int num)
{
	struct	ListNode	*new_node;

	new_node = create_node(num);
	if (new_node == NULL)
		return;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		struct ListNode	*current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

/**
 * modifiedList - function that will create the result List and do all things
 * 
 * @nums: the input array
 * @numsSize: nums.length()
 * @head: the address of The origine linked list
 * 
 * Return: return the resulting List after removing numbers that exist in @head and @nums.
 */

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode	*result;
	struct ListNode *current;

	result = NULL;
	current = head;
	while (current != NULL)
	{
		if (exist_check(nums, numsSize, current->val))
		{
			append_node(&result, current->val);
		}
		current = current->next;
	}
	return (result);
}


void	print_list(struct ListNode	*head)
{
	struct ListNode	*current;

	current = head;
	if (current == NULL)
	{
		printf("The list is vide!");
	}
	while (current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
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

int main()
{
	struct ListNode	*head = NULL;
	struct ListNode	*result;
	int	arr[] = {5};

	append_node(&head, 1);
	append_node(&head, 2);
	append_node(&head, 3);
	append_node(&head, 4);
	// now for the result linked_list
	result = modifiedList(arr, 1, head);
	print_list(result);
	free_list(head);
	free_list(result);
	return (0);
}
