#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_tokn = NULL;

/**
 * main - the entry point for Monty Interp
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
*/
int main(int argc, char **argv)
{
	FILE *_script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_());
	_script_fd = fopen(argv[1], "r");
	if (_script_fd == NULL)
		return (file_open_(argv[1]));
	exit_code = _exe_monty(_script_fd);
	fclose(_script_fd);
	return (exit_code);
}
