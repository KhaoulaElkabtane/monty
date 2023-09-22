#include "monty.h"

/**
 * fctError - Handles various error cases and exits the program.
 * @errorCode: Error code indicating the type of error.
 * @...: Variable number of additional arguments depending on the error type.
 *
 * Return: Nothing
 */
void fctError(int errorCode, ...)
{
	va_list lst;
	char *str;
	int num;

	va_start(lst, errorCode);
	switch (errorCode)
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
 * fctError2 - Handles various error cases and exits the program.
 * @errorCode: Error code indicating the type of error.
 * @...: Variable number of additional arguments depending on the error type.
 *
 * Return: Nothing
 */
void fctError2(int errorCode, ...)
{
	va_list lst;
	char *str;
	int num;

	va_start(lst, errorCode);
	switch (errorCode)
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
 * fctErrorStr - Handles various error cases and exits the program.
 * @errorCode: Error code indicating the type of error.
 * @...: Variable number of additional arguments depending on the error type.
 *
 * Return: Nothing
 */
void fctErrorStr(int errorCode, ...)
{
	va_list lst;
	int num;

	va_start(lst, errorCode);
	num = va_arg(lst, int);
	switch (errorCode)
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
