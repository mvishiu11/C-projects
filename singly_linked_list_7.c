#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

typedef struct
{
	struct Node* head;
	struct Node* current;
} Linked_List;

struct Node* create_node(int data);
void print_node(struct Node* node);
void insert_Start(struct Node* node, Linked_List* list);
void insert_End(struct Node* node, Linked_List* list);
void insert_after_current(struct Node* node, Linked_List* list);
void insert_before_current(struct Node* node, Linked_List* list);
void remove_after_current(Linked_List* list);
void remove_before_current(Linked_List* list);
void remove_current(Linked_List* list);
void remove_Start(Linked_List* list);
void remove_End(Linked_List* list);
void remove_All(Linked_List* list);
void remove_by_value(int n, Linked_List* list);
void remove_all_by_value(int n, Linked_List* list);
void remove_and_destroy_Start(Linked_List* list);
void remove_and_destroy_End(Linked_List* list);
void print_list(Linked_List* list);
void print_from_current(Linked_List* list);
struct Node* find_by_value(int n, Linked_List* list);
struct Node* find_by_index(int n, Linked_List* list);
Linked_List* split_after_current(Linked_List* list);
Linked_List* split_at_current(Linked_List* list);
Linked_List* list_cat(Linked_List* list_1, Linked_List* list_2);

int main()
{
	Linked_List list_1;
	list_1.head = list_1.current = NULL;
	
	struct Node* first = create_node(1);
	struct Node* second = create_node(2);
	struct Node* third = create_node(3);
	struct Node* last = create_node(4);
	struct Node* last_2 = create_node(4);
	struct Node* last_3 = create_node(4);
	struct Node* last_4 = create_node(4);
	struct Node* last_5 = create_node(4);
	struct Node* insert_1 = create_node(42);
	struct Node* insert_2 = create_node(41);

	insert_Start(first, &list_1);
	insert_Start(second, &list_1);
	insert_Start(last_5, &list_1);
	insert_Start(last_4, &list_1);
	insert_End(last, &list_1);
	insert_End(last_2, &list_1);
	insert_End(last_3, &list_1);
	insert_Start(third, &list_1);
	
	printf("Whole list:\n");
	print_list(&list_1);
	list_1.current = list_1.head->next->next;
	printf("\n");
	printf("Everything after second element:\n");
	print_from_current(&list_1);
	printf("\n");

	struct Node* fourth = find_by_value(4, &list_1);
	printf("Node with data equal to 4:\n");
	print_node(fourth);
	printf("\n");

	struct Node* fifth = find_by_index(2, &list_1);
	printf("Third element:\n");
	print_node(fifth);
	printf("\n");

	printf("After removing first and last element:\n");
	print_list(&list_1);
	remove_Start(&list_1);
	remove_End(&list_1);
	list_1.current = list_1.head->next;
	insert_after_current(insert_1, &list_1);
	insert_before_current(insert_2, &list_1);
	printf("\nAfter adding elements after and before current:\n");
	print_list(&list_1);
	list_1.current = list_1.head->next;
	remove_after_current(&list_1);
	remove_before_current(&list_1);
	printf("\nAfter removing elements after and before current:\n");
	print_list(&list_1);
	remove_by_value(4, &list_1);
	printf("\nAfter removing first occurance of value 4:\n");
	print_list(&list_1);
	remove_all_by_value(4, &list_1);
	printf("\nAfter removing all occurances of value 4:\n");
	print_list(&list_1);

	struct Node* new = create_node(11);
	struct Node* new_2 = create_node(12);
	struct Node* new_3 = create_node(13);

	insert_Start(new, &list_1);
	insert_End(new_2, &list_1);
	insert_Start(new_3, &list_1);
	printf("\nList_1 before split:\n");
	print_list(&list_1);
	list_1.current = find_by_index(3, &list_1);
	Linked_List* list_2 = split_after_current(&list_1);
	printf("\nList_1:\n");
	print_list(&list_1);
	printf("\nList_2:\n");
	print_list(list_2);

	printf("\nSecond split:\n");
	list_1.current = find_by_index(2, &list_1);
	Linked_List* list_3 = split_at_current(&list_1);
	printf("\nList_1:\n");
	print_list(&list_1);
	printf("\nList_3:\n");
	print_list(list_3);

	Linked_List* big_list = list_cat(&list_1, list_cat(list_2, list_3));
	printf("\nConcatenate all three lists together:\n");
	print_list(big_list);

	remove_All(big_list);
	return 0;
}

struct Node* create_node(int data)
{
	struct Node* node = malloc(sizeof(struct Node));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
	}
	return node;
}

void print_node(struct Node* node)
{
	printf("Node: | Data: %d | Next: %p |\n", (int)node->data, node->next);
}

void insert_Start(struct Node* node, Linked_List* list)
{
	node->next = list->head;
	list->head = node;
}

void insert_End(struct Node* node, Linked_List* list)
{
	list->current = list->head;
	while (list->current->next != NULL)
	{
		list->current = list->current->next;
	}
	list->current->next = node;
}

void insert_after_current(struct Node* node, Linked_List* list)
{
	node->next = list->current->next;
	list->current->next = node;
}

void insert_before_current(struct Node* node, Linked_List* list)
{
	struct Node* tmp = list->current;
	if (list->current == list->head)
	{
		insert_Start(node, list);
		tmp = NULL;
	}
	else
	{
		list->current = list->head;
		while (list->current->next != tmp)
		{
			list->current = list->current->next;
		}
		insert_after_current(node, list);
		list->current = list->current->next->next;
	}
}

void remove_after_current(Linked_List* list)
{
	list->current->next = list->current->next->next;
}

void remove_before_current(Linked_List* list)
{
	struct Node* tmp = list->current;
	if (list->current == list->head)
	{
		return;
	}
	else
	{
		list->current = list->head;
		while (list->current->next != tmp)
		{
			list->current = list->current->next;
		}
		remove_current(list);
		list->current = list->current->next;
	}
}

void remove_current(Linked_List* list)
{
	if (list->current == list->head)
	{
		remove_Start(list);
		return;
	}
	else if (list->current->next == NULL)
	{
		remove_End(list);
		return;
	}
	struct Node* tmp = list->current;
	list->current = list->head;
	while (list->current->next != tmp)
	{
		list->current = list->current->next;
	}
	remove_after_current(list);
}

void remove_Start(Linked_List* list)
{
	list->head = list->head->next;
}

void remove_End(Linked_List* list)
{
	list->current = list->head;
	while (list->current->next->next != NULL)
	{
		list->current = list->current->next;
	}
	struct Node* tmp2 = list->current;
	list->current = list->current->next;
	tmp2->next = NULL;
	list->current = NULL;
}

void remove_All(Linked_List* list)
{
	list->head = NULL;
	list->current = NULL;
}

void remove_by_value(int n, Linked_List* list)
{
	struct Node* tmp = find_by_value(n, list);
	list->current = tmp;
	remove_current(list);
}

void remove_all_by_value(int n, Linked_List* list)
{
	if (list->head->data == n)
	{
		remove_Start(list);
	}
	list->current = list->head;
	while (list->current->next != NULL)
	{
		if (list->current->data == n)
		{
			remove_current(list);
		}
		list->current = list->current->next;
	}
	if (list->current->data == n) 
	{
		remove_current(list);
	}
}

void remove_and_destroy_Start(Linked_List* list)
{
	struct Node* tmp = list->head;
	list->head = list->head->next;
	if (list->current == tmp)
		list->current = NULL;
	free(tmp);
}

void remove_and_destroy_End(Linked_List* list)
{
	list->current = list->head;
	while (list->current->next->next != NULL)
	{
		list->current = list->current->next;
	}
	struct Node* tmp2 = list->current;
	list->current = list->current->next;
	tmp2->next = NULL;

	struct Node* tmp = list->current;
	list->current = NULL;
	if (list->current == list->head)
		list->head = NULL;
	free(tmp);
}

void print_list(Linked_List* list) 
{
	list->current = list->head;
	while (list->current != NULL)
	{
		print_node(list->current);
		list->current = list->current->next;
	}
}

void print_from_current(Linked_List* list)
{
	while (list->current != NULL)
	{
		print_node(list->current);
		list->current = list->current->next;
	}
}

struct Node* find_by_value(int n, Linked_List* list)
{
	struct Node* dummy = malloc(sizeof(struct Node));
	if (dummy != NULL)
	{
		dummy->data = 0;
		dummy->next = NULL;
	}
	list->current = list->head;
	while ((int)list->current->data != n)
	{
		if (list->current->next == NULL)
		{
			return dummy;
		}
		list->current = list->current->next;
	}
	return list->current;
}

struct Node* find_by_index(int n, Linked_List* list)
{
	struct Node* dummy = malloc(sizeof(struct Node));
	if (dummy != NULL)
	{
		dummy->data = 0;
		dummy->next = NULL;
	}
	list->current = list->head;
	for (int i = 0; i < n; i++)
	{
		if (list->current->next == NULL)
		{
			return dummy;
		}
		list->current = list->current->next;
	}
	return list->current;
}

Linked_List* split_after_current(Linked_List* list)
{
	Linked_List* list_2 = malloc(sizeof(Linked_List));
	if (list_2 != NULL)
	{
		list_2->current = list_2->head = NULL;
		list_2->head = list->current->next;
		list->current->next = NULL;
	}

	return list_2;
}

Linked_List* split_at_current(Linked_List* list)
{
	if (list->current == list->head)
		return list;
	struct Node* tmp = list->current;
	list->current = list->head;
	while (list->current->next != tmp)
	{
		list->current = list->current->next;
	}
	Linked_List* list_2 = malloc(sizeof(Linked_List));
	if (list_2 != NULL)
	{
		list_2->current = list_2->head = NULL;
		list_2->head = list->current->next;
		list->current->next = NULL;
	}

	return list_2;
}

Linked_List* list_cat(Linked_List* list_1, Linked_List* list_2)
{
	list_1->current = list_1->head;
	while (list_1->current->next != NULL)
	{
		list_1->current = list_1->current->next;
	}
	list_1->current->next = list_2->head;
	return list_1;
}