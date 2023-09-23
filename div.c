#include "monty.h"
/**
 * divides - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void divides(stack_t **hd, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	stc = *hd;
	if (stc->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	a = stc->next->n / stc->n;
	stc->next->n = a;
	*hd = stc->next;
	free(stc);
}
