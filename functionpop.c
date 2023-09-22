#include "monty.h"

/**
 * fctMul - Adds the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctMul(stack_t **stack, unsigned int nub)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fctError2(8, nub, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * fctMod - Adds the tstr two elements of the stack.
 * @stack: Pointer to a pointer pointing to tstr nd of the stack.
 * @nub: Interger representing the line number of of the str.
 */
void fctMod(stack_t **stack, unsigned int nub)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		fctError2(8, nub, "mod");


	if ((*stack)->n == 0)
		fctError2(9, nub);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
