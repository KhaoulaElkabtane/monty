#include "monty.h"
/**
* frsStack - frees a doubly linked list
* @hd: head of the stack
*/
void frsStack(stack_t *head)
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
