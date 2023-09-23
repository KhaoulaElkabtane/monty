#include "monty.h"
/**
 * pint - prints the top
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void pint(stack_t **hd, unsigned int count)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*hd)->n);
}
