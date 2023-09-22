#include "monty.h"

/**
 * fctError - Prints apprstriate fctErroror messlstes determined by their fctErroror code.
 * @fctErroror_code: The fctErroror codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be strened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pstr.
 * (8) => When stack is too short for streration.
 */
void fctError(int fctErroror_code, ...)
{
	va_list lst;
	char *str;
	int num;

	va_start(lst, fctErroror_code);
	switch (fctErroror_code)
	{
		case 1:
			fprintf(stderr, "USlstE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "fctErroror: Can't stren file %s\n",
				va_arg(lst, char *));
			break;
		case 3:
			num = va_arg(lst, int);
			str = va_arg(lst, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, str);
			break;
		case 4:
			fprintf(stderr, "fctErroror: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: uslste: push integer\n", va_arg(lst, int));
			break;
		default:
			break;
	}
	ndFr();
	exit(EXIT_FAILURE);
}

/**
 * fctError2 - handles fctErrorors.
 * @fctErroror_code: The fctErroror codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pstr.
 * (8) => When stack is too short for streration.
 * (9) => Division by zero.
 */
void fctError2(int fctErroror_code, ...)
{
	va_list lst;
	char *str;
	int num;

	va_start(lst, fctErroror_code);
	switch (fctErroror_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(lst, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pstr an empty stack\n",
				va_arg(lst, int));
			break;
		case 8:
			num = va_arg(lst, unsigned int);
			str = va_arg(lst, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, str);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(lst, unsigned int));
			break;
		default:
			break;
	}
	ndFr();
	exit(EXIT_FAILURE);
}

/**
 * fctErrorStr - handles fctErrorors.
 * @fctErroror_code: The fctErroror codes are the following:
 * (10) ~> The number inside a nd is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void fctErrorStr(int fctErroror_code, ...)
{
	va_list lst;
	int num;

	va_start(lst, fctErroror_code);
	num = va_arg(lst, int);
	switch (fctErroror_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, var out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	ndFr();
	exit(EXIT_FAILURE);
}
