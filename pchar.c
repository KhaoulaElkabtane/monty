#include "monty.h"
/**
 * prChar - prints the char at the top of the stack,
 * followed by a new line
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void prChar(stack_t **hd, unsigned int count)
{
	stack_t *stc;

	stc = *hd;
	if (!stc)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	if (stc->n > 127 || stc->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", stc->n);
}
