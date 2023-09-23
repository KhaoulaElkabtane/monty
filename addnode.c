#include "monty.h"
/**
 * nodeAdd - add node to the head stack
 * @hd: head of the stack
 * @nv: new_value
 * Return: Nothing
*/
void nodeAdd(stack_t **hd, int nv)
{

	stack_t *node, *a;

	a = *hd;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (a)
		a->prev = node;
	node->n = nv;
	node->next = *hd;
	node->prev = NULL;
	*hd = node;
}
