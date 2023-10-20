#include "monty.h"

/**
 * _add - adds the 2 vals of a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number:  current working line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _sub - Subtracts 2ND value from the top of a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _div - Divides the 2nd value from the top of
 * a stack_t linked list by the top value
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_(div_(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mul - Multiplies 2nd value at head
 * stack_t linked list by the top value.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mod - find modulus of the 2nd val top of a
 * stack_t linked list  by the top value.
 * @stack:  pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_(short_stack_(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_(div_(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}
