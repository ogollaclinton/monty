#include "monty.h"
/**
 * _nop - Does absolutely nothing for 'nop' opcode
 * @stack: Pointer to top node to linked list.
 * @line_num_: current working line number
 */
void _nop(stack_t **stack, unsigned int line_num_)
{
	(void)stack;
	(void)line_num_;
}

/**
 * _pchar - Prints the character in the top value
 * @stack: Pointer to top node of linked list
 * @line_num_: The current working line number
*/
void _pchar(stack_t **stack, unsigned int line_num_)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_(pchar_(line_num_, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_(pchar_(line_num_,
					"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * _pstr - Prints the string contained in linked list
 * @stack: Pointer to the top node of linked list
 * @line_num_: The current working line number
*/
void _pstr(stack_t **stack, unsigned int line_num_)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_num_;
}
