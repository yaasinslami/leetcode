#include "main.h"

void	testFunction()
{
	List *head;

	head = NULL;
	append_node(&head, 18);
	append_node(&head, 6);
	append_node(&head, 10);
	append_node(&head, 3);

	//print the head List
	print_list(head);

	// now lets call our head list
	head = insertGCD(head);

	// let's print our head list
	print_list(head);

	//free_list(head);
	free_list(head);
}

int main()
{
	testFunction();
	return (0);
}
