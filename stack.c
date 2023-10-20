#include "monty.h"
#include <string.h>

/**
 * _free_stack - Frees stack_t
 * @stack: A pointer head / queue of a stack_t.
 */
void _free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * _init_stack - Initializes a stack_t stack
 * @stack: pointer to an unitialized stack_t stack
 * Return: EXIT_FAILURE / EXIT_SUCCESS.
 */
int _init_stack(stack_t **stack)
{
	stack_t *b;

	b = malloc(sizeof(stack_t));
	if (b == NULL)
		return (malloc_());

	b->n = STACK;
	b->prev = NULL;
	b->next = NULL;

	*stack = b;

	return (EXIT_SUCCESS);
}

/**
 * _check_mode - cheacks if a stack_t list is in stack / queue mode
 * @stack: A pointer to the stack & queue of a stack_t linked list.
 * Return: If STACK (0).
 *         If QUEUE (1).
 *         Otherwise - 2.
 */
int _check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
