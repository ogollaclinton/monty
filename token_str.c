#include "monty.h"

/**
 * _strtow_ - separates words in string
 * @str: string to seperate
 * @_delim: delimiters to use to delimit words
 * Return: Pointers to array
 */

char **_strtow_(char *str, char *_delim)
{
	char **_words = NULL;
	int w_count, w_length, n, y = 0;

	if (str == NULL || !*str)
		return (NULL);
	w_count = get_w_count(str, _delim);

	if (w_count == 0)
		return (NULL);
	_words = malloc((w_count + 1) * sizeof(char *));
	if (_words == NULL)
		return (NULL);
	while (y < w_count)
	{
		w_length = get_w_length(str, _delim);
		if (_is_delim(*str, _delim))
		{
			str = get_nxt_word(str, _delim);
		}
		_words[y] = malloc((w_length + 1) * sizeof(char));
		if (_words[y] == NULL)
		{
			while (y >= 0)
			{
				y--;
				free(_words[y]);
			}
			free(_words);
			return (NULL);
		}
		n = 0;
		while (n < w_length)
		{
			_words[y][n] = *(str + n);
			n++;
		}
		_words[y][n] = '\0';
		str = get_nxt_word(str, _delim);
		y++;
	}
	_words[y] = NULL;
	return (_words);
}

/**
 * _is_delim - checks if stream has delimiter char
 * @c: character in stream
 * @deli: Pointer to delimiters
 * Return: 1 or 0
*/

int _is_delim(char c, char *_delim)
{
	int y = 0;

	while (_delim[y])
	{
		if (_delim[y] == c)
			return (1);
		y++;
	}
	return (0);
}

/**
 * get_w_length - gets the word length of word in str
 * @str: string
 * @_delim: delimiters to use to delimit words
 * Return: word length of current word
*/

int get_w_length(char *str, char *_delim)
{
	int w_length = 0, wait_ing = 1, y = 0;

	while (*(str + y))
	{
		if (_is_delim(str[y], _delim))
			wait_ing = 1;
		else if (wait_ing)
		{
			w_length++;
		}
		if (w_length > 0 && _is_delim(str[y], _delim))
			break;
		y++;
	}
	return (w_length);
}

/**
 * get_w_count - gets the word count of a string
 * @str: string
 * @_delim: delimiters to use to delimit words
 * Return: the word count of the string
*/

int get_w_count(char *str, char *_delim)
{
	int w_count = 0, wait_ing = 1, y = 0;

	while (*(str + y))
	{
		if (_is_delim(str[y], _delim))
			wait_ing = 1;
		else if (wait_ing)
		{
			wait_ing = 0;
			w_count++;
		}
		y++;
	}
	return (w_count);
}

/**
 * get_nxt_word - gets the next word in a string
 * @str: string
 * @_delim: delimiters to use to delimit words
 * Return: pointer to first char of next word
*/

char *get_nxt_word(char *str, char *_delim)
{
	int wait_ing = 0;
	int y = 0;

	while (*(str + y))
	{
		if (_is_delim(str[y], _delim))
			wait_ing = 1;
		else if (wait_ing)
			break;
		y++;
	}
	return (str + y);
}
