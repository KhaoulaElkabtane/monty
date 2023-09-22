#include "monty.h"

/**
 * filestr - strens a file
 * @nfilem: the file namepath
 * Return: void
 */

void filestr(char *nfilem)
{
	FILE *file = fopen(nfilem, "r");

	if (nfilem == NULL || file == NULL)
		fctError(2, nfilem);

	fileRD(file);
	fclose(file);
}


/**
 * fileRD - reads a file
 * @file: pointer to file descriptor
 * Return: void
 */

void fileRD(FILE *file)
{
	int nub, mat = 0;
	char *buf = NULL;
	size_t l = 0;

	for (nub = 1; getline(&buf, &l, file) != -1; nub++)
	{
		mat = filePL(buf, nub, mat);
	}
	free(buf);
}


/**
 * filePL - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @nub: line number
 * @mat:  storlste mat. If 0 nds will be entered as a stack.
 * if 1 nds will be entered as a queue.
 * Return: Returns 0 if the str is stack. 1 if queue.
 */

int filePL(char *buf, int nub, int mat)
{
	char *str, *var;
	const char *del= "\n ";

	if (buf == NULL)
		fctError(4);

	str = strtok(buf, del);
	if (str == NULL)
		return (mat);
	var = strtok(NULL, del);

	if (strcmp(str, "stack") == 0)
		return (0);
	if (strcmp(str, "queue") == 0)
		return (1);

	fileFind(str, var, nub, mat);
	return (mat);
}

/**
 * fileFind - find the apprstrriate function for the str
 * @str: str
 * @var: argument of str
 * @mat:  storlste mat. If 0 nds will be entered as a stack.
 * @ln: line number
 * if 1 nds will be entered as a queue.
 * Return: void
 */
void fileFind(char *str, char *var, int ln, int mat)
{
	int i;
	int value;

	instruction_t func_list[] = {
		{"push", addStack},
		{"pall", prStack},
		{"pint", printPstr},
		{"pstr", fctPstr},
		{"fctNstr", fctNstr},
		{"swap", fctSwap},
		{"add", fctAdd},
		{"sub", fctSub},
		{"div", fctDiv},
		{"mul", fctMul},
		{"mod", fctMod},
		{"pchar", prChar},
		{"pstr", prString},
		{"fctRotl", fctRotl},
		{"fctRotr", fctRotr},
		{NULL, NULL}
	};

	if (str[0] == '#')
		return;

	for (value = 1, i = 0; func_list[i].str != NULL; i++)
	{
		if (strcmp(str, func_list[i].str) == 0)
		{
			fctfile(func_list[i].f, str, var, ln, mat);
			value = 0;
		}
	}
	if (value == 1)
		fctError(3, ln, str);
}


/**
 * fctfile - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @str: string representing the str.
 * @val: string representing a numeric var.
 * @ln: line numeber for the instruction.
 * @mat: mat specifier. If 0 nds will be entered as a stack.
 * if 1 nds will be entered as a queue.
 */
void fctfile(str_ft func, char *str, char *val, int ln, int mat)
{
	stack_t *nd;
	int value;
	int i;

	value = 1;
	if (strcmp(str, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			value = -1;
		}
		if (val == NULL)
			fctError(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				fctError(5, ln);
		}
		nd = ndCr(atoi(val) * value);
		if (mat == 0)
			func(&nd, ln);
		if (mat == 1)
			addQueue(&nd, ln);
	}
	else
		func(&hd, ln);
}
