#include "main.h"

List	*insertGCD(struct ListNode* head)
{
	List	*current, *new_node;

	// if there at most one node
	if (!head || !head->next)
	{
		return (head);
	}

	current = head;
	while (current->next != NULL)
	{
		int pgc = pgcd(current->val, current->next->val);
		new_node = create_node_v1(pgc, current->next);
		current->next = new_node;
		current = new_node->next;
	}
	return (head);
}

List	*create_node_v1(int val, List *next)
{
	List *new_node;

	new_node = (List *)malloc(sizeof(List));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->val = val;
	new_node->next = next;
	return (new_node);
}
