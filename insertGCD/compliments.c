#include "main.h"

List	*create_node(int val)
{
	List	*new_node;

	new_node = (List *)malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(List **head, int val)
{
	List	*new_node;
	List	*current;

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

void	print_list(List *head)
{
	List	*current;

	current = head;
	printf("[");
	while (current != NULL)
	{
		printf("%d", current->val);
		current = current->next;
		if (current != NULL)
			printf(" -> ");
	}
	printf("]\n");
}

void	free_list(List *head)
{
	List *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
