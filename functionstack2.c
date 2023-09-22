#include "monty.h"

/**
 * fctNstr - Does nothing.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctNstr(stack_t **stack, unsigned int nub)
{
	(void)stack;
	(void)nub;
}


/**
 * fctSwap - Swaps the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctSwap(stack_t **stack, unsigned int nub)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fctError2(8, nub, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * fctAdd - Adds the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctAdd(stack_t **stack, unsigned int nub)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fctError2(8, nub, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * fctSub - Adds the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctSub(stack_t **stack, unsigned int nub)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		fctError2(8, nub, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * fctDiv - Adds the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctDiv(stack_t **stack, unsigned int nub)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fctError2(8, nub, "div");

	if ((*stack)->n == 0)
		fctError2(9, nub);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
