#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 *@input_string: input to be parsed
 *@char_end: char_enditer to be used, needs to be one character string
 *Return: array of tokens
 */

char **tokenizer(char *input_string, char *char_end)
{
	int num_char_end = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, char_end, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_char_end, sizeof(*av) * (num_char_end + 1));
		av[num_char_end] = token;
		token = _strtok_r(NULL, char_end, &save_ptr);
		num_char_end++;
	}

	av = _realloc(av, sizeof(*av) * num_char_end, sizeof(*av) * (num_char_end + 1));
	av[num_char_end] = NULL;

	return (av);
}

/**
 *print - prints a string to standar output
 *@string: string to be printed
 *@stream: stream to print out to
 *
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 *remove_newline - removes new line
 *@str: string to be used
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - counts string length
 *@strg: string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *strg)
{
	int len = 0;

	if (strg == NULL)
		return (len);
	for (; strg[len] != '\0'; len++)
		;
	return (len);
}
