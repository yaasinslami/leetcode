#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_node
{
	char	*name;
	int		age;
	struct list_node	*next;
} node;

// allocate or each node (as long as we call new_code().)
node	*create_node(const char *name, int age)
{
	node	*new_node;

	new_node = (node *)malloc((sizeof(node)));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->name = strdup(name);
	new_node->age = age;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(node **head, const char *name, int age)
{
	node	*new_node;

	new_node = create_node(name, age);
	if (!new_node)
		return;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		// Traverse to the end of the list.
		node	*current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node; // Link the last node to the new node.
	}
}

void	print_list(node *head)
{
	node	*current;

	current = head;
	if (current == NULL)
		printf("The list is NULL\n");
	while (current != NULL)
	{
		printf("name: %s\tage: %d\n", current->name, current->age);
		current = current->next;
	}
}

void	free_list(node *head)
{
	while (head != NULL)
	{
		node	*tmp;
		tmp = head;
		head = head->next;
		free (tmp->name);
		free(tmp);
	}
}

int main()
{
	node	*head;

	head = NULL;
	append_node(&head, "Yassine", 19);
	append_node(&head, "Ahmed", 12);
	append_node(&head, "Akram", 20);
	append_node(&head, "oussama", 40);

	print_list(head);
	free_list(head);
	return (0);
}
