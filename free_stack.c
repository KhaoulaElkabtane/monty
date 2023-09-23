#include "monty.h"
/**
* freStack - frees a doubly linked list
* @hd: head of the stack
*/
void freStack(stack_t *hd)
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
