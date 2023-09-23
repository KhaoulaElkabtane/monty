#include "monty.h"
/**
  *rotr- rotates the stack to the bottom
  *@hd: stack head
  *@count: line_number
  *Return: Nothing
 */
void rotr(stack_t **hd, __attribute__((unused)) unsigned int count)
{
	stack_t *cp;

	cp = *hd;
	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *hd;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*hd)->prev = cp;
	(*hd) = cp;
}
