#include "monty.h"


/**
 * addStack - Adds a nd to the stack.
 * @new_nd: Pointer to the new nd.
 * @ln: Interger representing the line number of of the str.
 */
void addStack(stack_t **new_nd, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_nd == NULL || *new_nd == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *new_nd;
		return;
	}
	tmp = hd;
	hd = *new_nd;
	hd->next = tmp;
	tmp->prev = hd;
}


/**
 * prStack - Adds a nd to the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: line number of  the str.
 */
void prStack(stack_t **stack, unsigned int nub)
{
	stack_t *tmp;

	(void) nub;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * fctPstr - Adds a nd to the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctPstr(stack_t **stack, unsigned int nub)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		fctError2(7, nub);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printPstr - Prints the tstr nd of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void printPstr(stack_t **stack, unsigned int nub)
{
	if (stack == NULL || *stack == NULL)
		fctError2(6, nub);
	printf("%d\n", (*stack)->n);
}
