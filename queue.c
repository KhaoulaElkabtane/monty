#include "monty.h"
/**
 * queue - prints the top
 * @hd: stack head
 * @count: line_number
 * Return: Nothing
*/
void queue(stack_t **hd, unsigned int count)
{
	(void)hd;
	(void)count;
	bus.lifi = 1;
}

/**
 * addQueue - add node to the tail stack
 * @nv: new_value
 * @hd: head of the stack
 * Return: Nothing
*/
void addQueue(stack_t **hd, int nv)
{
	stack_t *node, *a;

	a = *hd;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
	}
	node->n = nv;
	node->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*hd = node;
		node->prev = NULL;
	}
	else
	{
		a->next = node;
		node->prev = a;
	}
}
