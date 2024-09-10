#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} List;

int min(int, int);
int pgcd(int, int);
List	*insertGCD(struct ListNode* head);
List	*create_node_v1(int val, List *next);
List	*create_node(int val);
void	append_node(List **head, int val);
void	print_list(List *head);
void	free_list(List *head);

#endif
