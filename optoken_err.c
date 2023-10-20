#include "monty.h"
/**
 * set_op_tok_ - Sets last element of op_toks to be an error code.
 * @err_code: Integer to store as a string in op_toks.
*/
void set_op_tok_(int err_code)
{
	int tokn_len = 0, y = 0;
	char *exit_str = NULL;
	char **new_tokn = NULL;

	tokn_len = token_len();
	new_tokn = malloc(sizeof(char *) * (tokn_len + 2));
	if (!op_tokn)
	{
		malloc_();
		return;
	}
	while (y < tokn_len)
	{
		new_tokn[y] = op_tokn[y];
		y++;
	}
	exit_str = get_int_(err_code);
	if (!exit_str)
	{
		free(new_tokn);
		malloc_();
		return;
	}
	new_tokn[y++] = exit_str;
	new_tokn[y] = NULL;
	free(op_tokn);
	op_tokn = new_tokn;
}
