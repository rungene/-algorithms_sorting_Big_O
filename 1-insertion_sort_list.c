#include "sort.h"
/**
* insertion_sort_list -  sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
* @list: first params, double pointer to the linked list
*
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *p;
	listint_t *head;

	/*zero or one element*/
	if (*list == NULL || (*list)->next == NULL)
		return;
	/*Head is the first element in a sorted linked list*/
	head = NULL;
	while ( *list != NULL)
	{
		current = *list;
		*list = (*list)->next;
		if (head == NULL || current->n < head->n)
		{
			/*insert into the head of the sorted list*/
			/*or as the first element into an empty sorted list*/
			current->next = head;
			head = current;
		}
		else
		{
			/*insert current element in non-empty sorted list*/
			p = head;
			while (p != NULL)
			{
				if (p->next == NULL || /*last element of sorted list*/ current->n < p->prev->n)/*middle of the list*/
				{
					/*insert into the middle of the list or as the last element*/
					current->next = p->prev;
					p->prev = current;
					break; /*Done*/
				}
				p = p->prev;	
			}
		}
		
	}
}
