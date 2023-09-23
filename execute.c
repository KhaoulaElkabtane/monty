#include "monty.h"
/**
* execute - executes the opcode
* @stk: head linked list - stack
* @count: line_counter
* @f: poiner to monty file
* @cont: line content
* Return: Nothing
*/
int execute(char *cont, stack_t **stk, unsigned int count, FILE *f)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", pop},
				{"swap", f_swap},
				{"add", add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", divides},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *str;

	str = strtok(cont, " \n\t");
	if (str && str[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && str)
	{
		if (strcmp(str, opst[i].opcode) == 0)
		{	opst[i].f(stk, count);
			return (0);
		}
		i++;
	}
	if (str && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
		fclose(f);
		free(cont);
		free_stack(*stk);
		exit(EXIT_FAILURE); }
	return (1);
}
