#include "monty.h"
/**
  *rotl- rotates the stack to the top
  *@hd: stack head
  *@count: line_number
  *Return: Nothing
 */
void rotl(stack_t **hd,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *hd, *a;

	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	a = (*hd)->next;
	a->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *hd;
	(*hd)->next = NULL;
	(*hd)->prev = tmp;
	(*hd) = a;
}
