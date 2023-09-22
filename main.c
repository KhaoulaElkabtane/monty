#include "monty.h"
stack_t *hd = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USlstE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filestr(argv[1]);
	ndFr();
	return (0);
}

/**
 * ndCr - Creates a nd.
 * @n: Number to go inside the nd.
 * Return: Upon sucess a pointer to the nd. Otherwise NULL.
 */
stack_t *ndCr(int n)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		fctError(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * ndFr - Frees nds in the stack.
 */
void ndFr(void)
{
	stack_t *tmp;

	if (hd == NULL)
		return;

	while (hd != NULL)
	{
		tmp = hd;
		hd = hd->next;
		free(tmp);
	}
}


/**
 * addQueue - Adds a nd to the queue.
 * @new_nd: Pointer to the new nd.
 * @ln: line number of the str.
 */
void addQueue(stack_t **new_nd, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_nd;
	(*new_nd)->prev = tmp;

}
