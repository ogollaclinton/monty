#include "monty.h"

/**
 * _rotl - rotates the head of a stack_t linked list to the bottom.
 * @stack:  pointer to the top mode node of a stack_t linked list.
 * @line_num_: The current working line
 */
void _rotl(stack_t **stack, unsigned int line_num_)
{
	stack_t *head, *tail;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	head = (*stack)->next;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;

	head->next->prev = *stack;
	(*stack)->next = head->next;
	tail->next = head;
	head->next = NULL;
	head->prev = tail;

	(void)line_num_;
}

/**
 * _rotr - Rotates the bottom value of a stack_t linked list to the head
 * @stack:  pointer to the top mode node of a stack_t linked list
 * @line_num_: current working line number
 */
void _rotr(stack_t **stack, unsigned int line_num_)
{
	stack_t *head, *tail;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	head = (*stack)->next;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	(*stack)->next = tail;
	tail->prev = *stack;
	tail->next = head;
	head->prev = tail;

	(void)line_num_;
}

/**
 * _stack - Convert a queue to a stack.
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_num_: current working line number
 */
void _stack(stack_t **stack, unsigned int line_num_)
{
	(*stack)->n = STACK;
	(void)line_num_;
}

/**
 * _queue - Converts a stack to a queue
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_num_: current working line number
 */
void _queue(stack_t **stack, unsigned int line_num_)
{
	(*stack)->n = QUEUE;
	(void)line_num_;
}
