#include "monty.h"
/**
  *f_sub- sustration
  *@hd: stack head
  *@count: line_number
  *Return: Nothing
 */
void f_sub(stack_t **hd, unsigned int count)
{
	stack_t *a;
	int sub, node;

	a = *hd;
	for (node = 0; a != NULL; node++)
		a = a->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	a = *hd;
	sub = a->next->n - a->n;
	a->next->n = sub;
	*hd = a->next;
	free(a);
}
