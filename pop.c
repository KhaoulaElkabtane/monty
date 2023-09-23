#include "monty.h"
/**
 * pop - prints the top
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void pop(stack_t **hd, unsigned int count)
{
	stack_t *stc;

	if (*hd == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	stc = *hd;
	*hd = stc->next;
	free(stc);
}
