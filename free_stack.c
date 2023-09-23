#include "monty.h"
/**
* frStack - frees a doubly linked list
* @hd: head of the stack
*/
void frStack(stack_t *hd)
{
	stack_t *a;

	a = hd;
	while (hd)
	{
		a = hd->next;
		free(hd);
		hd = a;
	}
}
