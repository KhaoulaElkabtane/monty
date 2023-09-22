#include "monty.h"

/**
 * prChar - Prints the Ascii var.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void prChar(stack_t **stack, unsigned int nub)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		fctErrorStr(11, nub);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		fctErrorStr(10, nub);
	printf("%c\n", ascii);
}

/**
 * prString - Prints a string.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @ln: Interger representing the line number of of the str.
 */
void prString(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * fctRotl - Rotates the first nd of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @ln: Interger representing the line number of of the str.
 */
void fctRotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * fctRotr - Rotates the last nd of the stack to the tstr.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @ln: Interger representing the line number of of the str.
 */
void fctRotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
