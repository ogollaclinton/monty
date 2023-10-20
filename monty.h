#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_tokn;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *op_code;
	void (*f)(stack_t **stack, unsigned int line_num_);
} instruction_t;

int _init_stack(stack_t **stack);
int _check_mode(stack_t *stack);
void _free_stack(stack_t **stack);
int _empty_line(char *line, char *delims);
unsigned int token_len(void);

void _pint(stack_t **stack, unsigned int line_num_);
void _push(stack_t **stack, unsigned int line_num_);
void _pall(stack_t **stack, unsigned int line_num_);
void _pop(stack_t **stack, unsigned int line_num_);
void _swap(stack_t **stack, unsigned int line_num_);
void _add(stack_t **stack, unsigned int line_num_);
void _sub(stack_t **stack, unsigned int line_num_);
void _div(stack_t **stack, unsigned int line_num_);
void _mul(stack_t **stack, unsigned int line_num_);
void _mod(stack_t **stack, unsigned int line_num_);
void _nop(stack_t **stack, unsigned int line_num_);
void _pchar(stack_t **stack, unsigned int line_num_);
void _pstr(stack_t **stack, unsigned int line_num_);
void _rotl(stack_t **stack, unsigned int line_num_);
void _rotr(stack_t **stack, unsigned int line_num_);
void _stack(stack_t **stack, unsigned int line_num_);
void _queue(stack_t **stack, unsigned int line_num_);


/*errors handlers*/
int usage_(void);
int file_open_(char *file_name);
int malloc_(void);
int unknown_op_(char *op_code, unsigned int line_num_);
int no_int_(unsigned int line_num_);
int pop_(unsigned int line_num_);
int pchar_(unsigned int line_num_, char *_msg);
int pint_(unsigned int line_num_);

void set_op_tok_(int err_code);

char **_strtow_(char *str, char *_delim);
int _is_delim(char c, char *_delim);
int get_w_length(char *str, char *_delim);
int get_w_count(char *str, char *_delim);
char *get_nxt_word(char *str, char *_delim);


int main(int argc, char **argv);
int _exe_monty(FILE *_script_fd);
void _free_tokens(void);
void _free_stack(stack_t **stack);
int short_stack_(unsigned int line_num_, char *op);
int div_(unsigned int line_num_);

char *get_int_(int num);
unsigned int abs_(int);
int get_buff_len(unsigned int num, unsigned int base);
void fill_buff(unsigned int num, unsigned int base,
				       char *buff, int buff_size);


#endif
