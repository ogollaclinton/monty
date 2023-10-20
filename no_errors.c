#include <stdio.h>
#include "monty.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * usage_ - prints usage error & returns error code
 * Return: EXIT_FAILURE
 */
int usage_(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	return (EXIT_FAILURE);
}

/**
 * file_open_ - prints file open error with file name
 * @file_name: name of file failed to open
 * Return: EXIT_FAILURE
 */

int file_open_(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * malloc_ - prints malloc error info and returns error code
 * Return: EXIT_FAILURE
 */

int malloc_(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	return (EXIT_FAILURE);
}

/**
 *unknown_op_ - prints error msg for unknown instruction
 *@op_code: opcode where error occurred
 *@line_num_: line number with error
 *Return: EXIT_FAILURE
 */

int unknown_op_(char *op_code, unsigned int line_num_)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_num_, op_code);
	return (EXIT_FAILURE);
}

/**
 * no_int_ - prints error upon upon invalid argument
 * @line_num_: line with error
 * Return: EXIT_FAILURE
 */

int no_int_(unsigned int line_num_)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num_);
	return (EXIT_FAILURE);
}
