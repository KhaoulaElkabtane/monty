#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void add(stack_t **hd, unsigned int count)
{
	stack_t *stc;
	int l = 0, a;

	stc = *hd;
	while (stc)
	{
		stc = stc->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	stc = *hd;
	a = stc->n + stc->next->n;
	stc->next->n = a;
	*hd = stc->next;
	free(stc);
}
