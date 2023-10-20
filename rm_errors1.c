#include "monty.h"

/**
 * short_stack_ - error msg for monty math funcs with < 2 nodes
 *@line_num_: line with error0
 * @op: Operation where the error occurred
 * Return: EXIT_FAILURE
 */
int short_stack_(unsigned int line_num_, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_num_, op);
	return (EXIT_FAILURE);
}

/**
 * div_ - error msg for division by 0
 * @line_num_: Line number where error occurs
 * Return: EXIT_FAILURE
 */
int div_(unsigned int line_num_)
{
	fprintf(stderr, "L%u: division by zero\n", line_num_);
	return (EXIT_FAILURE);
}

/**
 * pop_ - prints pop error msg for empty stacks
 * @line_num_: Line number with error
 * Return: EXIT_FAILURE
 */
int pop_(unsigned int line_num_)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num_);
	return (EXIT_FAILURE);
}

/**
 * pchar_ - Prints pchar error messages for empty stacks
 * @line_num_: Line number in Monty
 * @_msg: corresponding error message to print
 * Return: EXIT_FAILURE
 */

int pchar_(unsigned int line_num_, char *_msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_num_, _msg);
	return (EXIT_FAILURE);
}

/**
 * pint_ - Prints pint error msg for empty stacks.
 * @line_num_: Line number in Monty
 * Return: EXIT_FAILURE
 */
int pint_(unsigned int line_num_)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num_);
	return (EXIT_FAILURE);
}
