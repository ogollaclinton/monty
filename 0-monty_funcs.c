#include <stdio.h>
#include <stddef.h>
#include "monty.h"
#include <stdlib.h>

/**
 * _push - Push value to a stack_t linked list
 * @stack: Pointer to first node of a stack_t linked list
 * @line_num_: current working line number of a Monty bytecodes file
 */
void _push(stack_t **stack, unsigned int line_num_)
{
	stack_t *tmp, *lat_est;
	int y;

	lat_est = malloc(sizeof(stack_t));
	if (lat_est == NULL)
	{
		set_op_tok_(malloc_());
		return;
	}

	if (op_tokn[1] == NULL)
	{
		set_op_tok_(no_int_(line_num_));
		return;
	}

	for (y = 0; op_tokn[1][y]; y++)
	{
		if (op_tokn[1][y] == '-' && y == 0)
			continue;
		if (op_tokn[1][y] < '0' || op_tokn[1][y] > '9')
		{
			set_op_tok_(no_int_(line_num_));
			return;
		}
	}
	lat_est->n = atoi(op_tokn[1]);

	if (_check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		lat_est->prev = *stack;
		lat_est->next = tmp;
		if (tmp)
			tmp->prev = lat_est;
		(*stack)->next = lat_est;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		lat_est->prev = tmp;
		lat_est->next = NULL;
		tmp->next = lat_est;
	}
}

/**
 * _pall - Prints the values of a stack_t
 * @stack: Pointer to first node of a stack_t
 * @line_num_: current working line number of a Monty bytecodes file
 */
void _pall(stack_t **stack, unsigned int line_num_)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_num_;
}

/**
 * _pint - prints the head value of a stack linked list
 * @stack: Pointer to head of stacked linked list
 * @line_num_: current line num of monty
 */

void _pint(stack_t **stack, unsigned int line_num_)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_(pint_(line_num_));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * _pop - Remove top value element of linked list
 * @stack: Pointer to top node of linked list
 * @line_num_: current working line number of a Monty bytecodes file
 */
void _pop(stack_t **stack, unsigned int line_num_)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_(pop_(line_num_));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * _swap - Swap top two value elements of linked list
 * @stack: Pointer to the top node of linked list
 * @line_num_: current working line number of a Monty bytecodes file
*/
void _swap(stack_t **stack, unsigned int line_num_)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_num_, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
