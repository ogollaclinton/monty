#define _GNU_SOURCE
#include "monty.h"
#include <string.h>
#include <stdio.h>
/**
 * token_len - get the len of current op_toks
 * Return: Len of current op_tokn
 */
unsigned int token_len(void)
{
	unsigned int tok_len = 0;

	while (op_tokn[tok_len])
		tok_len++;
	return (tok_len);
}

/**
 * _empty_line - Checks if a line read only contains delimiters.
 * @line: pointer to the line
 * @delims: A string of delimiter characters
 * Return: 0 / -1
 */
int _empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
/**
 * _get_op_func - links an opcode with its corresponding function
 * @opcode: opcode to match.
 * Return: A pointer to the function.
 */
void (*_get_op_func(char *op_code))(stack_t**, unsigned int)
{
	instruction_t _op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int a;

	for (a = 0; _op_funcs[a].op_code; a++)
	{
		if (strcmp(op_code, _op_funcs[a].op_code) == 0)
			return (_op_funcs[a].f);
	}

	return (NULL);
}

/**
 * _exe_monty - main function to execute a Monty bytecodes script.
 * @_script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success /respective error if fails
 */
int _exe_monty(FILE *_script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*_op_func)(stack_t**, unsigned int);

	if (_init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, _script_fd) != -1)
	{
		line_num++;
		op_tokn = _strtow_(line, DELIMS);
		if (op_tokn == NULL)
		{
			if (_empty_line(line, DELIMS))
				continue;
			_free_stack(&stack);
			return (malloc_());
		}
		else if (op_tokn[0][0] == '#') /* comment */
		{
			_free_tokens();
			continue;
		}
		_op_func = _get_op_func(op_tokn[0]);
		if (_op_func == NULL)
		{
			_free_stack(&stack);
			exit_status = unknown_op_(op_tokn[0], line_num);
			_free_tokens();
			break;
		}
		prev_tok_len = token_len();
		_op_func(&stack, line_num);
		if (token_len() != prev_tok_len)
		{
			if (op_tokn && op_tokn[prev_tok_len])
				exit_status = atoi(op_tokn[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			_free_tokens();
			break;
		}
		_free_tokens();
	}
	_free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_());
	}

	free(line);
	return (exit_status);
}

/**
 * _free_tokens - Frees the global op_toks array of str
 */
void _free_tokens(void)
{
	size_t a = 0;

	if (op_tokn == NULL)
		return;

	for (a = 0; op_tokn[a]; a++)
		free(op_tokn[a]);

	free(op_tokn);
}
