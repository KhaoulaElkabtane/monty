#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: True if 0 Faulse if 1 
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *f;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *stk = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	bus.file = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		cont = NULL;
		readLine = getline(&cont, &size, f);
		bus.content = cont;
		count++;
		if (readLine > 0)
		{
			execute(cont, &stk, count, f);
		}
		free(cont);
	}
	frStack(stk);
	fclose(f);
return (0);
}
