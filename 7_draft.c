#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct elem
{
	int n;
	struct elem* next;
};

typedef struct elem element;

typedef struct
{
	element* head, * current, * tail;
}sll;
//1
element *create_element(int n);
//2
void print_element(element *e);
//3
void insert_front(sll* list, element* e);
//4
void destroy(sll* list);
//5
void print_after_current(sll* list);
//6
void print_from(element *e);

void print_all(sll* list);
//7
void insert_back(sll* list, element* e);
//8
void remove_front(sll* list);
//9
void remove_back(sll* list);
//10
element *find(sll* list,int n);
//11
element* find_index(sll* list,int index);
//12
void insert_after_current(sll* list,element* e);
//13
void insert_before_current(sll* list,element* e);
//14
void remove_after_current(sll* list);
//15
void remove_current(sll* list);
//16
void remove_first_of_value(sll* list,int n);
//17
void remove_all_of_value(sll* list,int n);
//18
sll split_after_current(sll* list);
//19
sll split_at_current(sll* list);
//20
sll concat_lists(sll* list1, sll* list2);

void list_init(sll *list);

int main(void)
{
	sll list1,list2;
	list_init(&list1);
	list_init(&list2);
	//
	insert_back(&list1,create_element(1));
	insert_back(&list1, create_element(2));
	insert_back(&list1, create_element(3));
	insert_back(&list1, create_element(4));
	insert_back(&list1, create_element(5));
	print_all(&list1);
	list1.current = find_index(&list1, 1);
	list2 = split_after_current(&list1);
	print_all(&list2);
	remove_back(&list1);
	print_all(&list2);
	//
	/*destroy(&list1);
	destroy(&list2);*/
}

void list_init(sll *list)
{

	list->head = NULL;
	list->current = NULL;
	list->tail = NULL;
}

element *create_element(int n)
{
	element *e=(element*)malloc(sizeof(element));
	e->n = n;
	e->next = NULL;
	return e;
}

void print_element(element *e)
{
	if (e != NULL) printf("%d ", e->n);
	return;
}

void print_from(element* e)
{
	if (e == NULL) return;
	while (e != NULL)
	{
		print_element(e);
		e = e->next;
	}
	printf("\n");
}

void print_after_current(sll* list)
{
	print_from(list->current->next);
}

void print_all(sll* list)
{
	if(list->head==NULL) printf("Empty\n");
	print_from(list->head);
}

void insert_front(sll* list,element* e)
{
	if (!list->tail) list->tail = e;
	e->next = list->head;
	list->head=e;
	if (list->tail == NULL) list->tail = e;
}

void insert_back(sll* list,element* e)
{
	if (!list->head) list->head = e;
	e->next = NULL;
	if(list->tail != NULL) list->tail->next = e;
	list->tail = e;
}

void destroy(sll* list)
{
	if (list->head == NULL) return;
	element* pos;
	while (list->head->next != NULL)
	{
		pos = list->head->next;
		free(list->head);
		list->head = pos;
	}
	free(list->head);
	list->head = NULL;
}

void remove_front(sll* list)
{
	element *tmp= list->head->next;
	free(list->head);
	list->head = tmp;
}

void remove_back(sll* list)
{
	element* tmp,*pos= list->head;
	while (pos->next->next != NULL)
	{
		pos = pos->next;
	}
	tmp = pos;
	tmp->next = NULL;
	free(list->tail);
	list->tail = tmp;
}

element *find(sll* list,int n)
{
	element* pos = list->head;
	while (pos != NULL)
	{
		if (pos->n == n)
		{
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}

element *find_index(sll* list,int index)
{
	element* pos= list->head;
	int i = 0;
	while (pos != NULL && i<index)
	{
		pos = pos->next;
		i++;
	}
	if (i != index) return NULL;
	return pos;
}

void insert_after_current(sll* list,element* e)
{
	if (list->current == list->tail)
	{
		insert_back(list,e);
		return;
	}
	e->next = list->current->next;
	list->current->next = e;
}

void insert_before_current(sll* list,element* e)
{
	if (list->current == list->head)
	{
		insert_front(list,e);
		return;
	}
	element* tmp = list->head;
	while (tmp->next != list->current)
	{
		tmp = tmp->next;
	}
	e->next = list->current;
	tmp->next = e;
}

void remove_after_current(sll* list)
{
	if (list->current->next == NULL) return;
	if (list->current->next == list->tail)
	{
		remove_back(list);
		return;
	}
	list->current = list->current->next;
	remove_current(list);
}

void remove_current(sll* list)
{
	if (list->current == list->head)
	{
		remove_front(list);
		return;
	}
	if (list->current == list->tail)
	{
		remove_back(list);
		return;
	}
	element* pos = list->head;
	while (pos->next != list->current)
	{
		pos = pos->next;
	}
	pos->next = list->current->next;
	free(list->current);
}

void remove_first_of_value(sll* list,int n)
{
	element* pos= list->current;
	list->current = find(list,n);
	remove_current(list);
	list->current = pos;
}

void remove_all_of_value(sll* list,int n)
{
	element* pos= list->current;
	while (find(list,n) != NULL)
	{
		list->current = find(list,n);
		remove_current(list);
	}
	list->current = pos;
}

sll split_after_current(sll* list)
{
	sll split;
	element* pos = list->current->next;
	list_init(&split);
	while (pos != NULL)
	{
		insert_back(&split,create_element(pos->n));
		pos = pos->next;
	}
	return split;
}

sll *sac2(sll* list)
{
	sll *split=malloc(sizeof(sll));
	list_init(split);
	split->head = list->current->next;
	split->tail = list->tail;
	return split;
}

//sll split_at_current(sll* list)
//{
//
//}
//
//sll concat_lists(sll* list1, sll* list2)
//{
//
//}