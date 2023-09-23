#include "monty.h"
/**
 * pall - prints the stack
 * @hd: stack head
 * @count: no used
 * Return: Nothing
*/
void pall(stack_t **hd, unsigned int count)
{
	stack_t *stc;
	(void)count;

	stc = *hd;
	if (stc == NULL)
		return;
	while (stc)
	{
		printf("%d\n", stc->n);
		stc = stc->next;
	}
}
