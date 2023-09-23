#include "monty.h"
/**
 * push - add node to the stack
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void push(stack_t **hd, unsigned int count)
{
	int i, j = 0, lag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				lag = 1; }
		if (lag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			frStack(*hd);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		frStack(*hd);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		nodeAdd(hd, i);
	else
		addQueue(hd, i);
}
