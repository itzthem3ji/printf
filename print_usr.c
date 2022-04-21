#include "main.h"

/**
 * print_usr - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hex, *binary;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hex = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handl_buf(buf, '\\', ibuf);
			ibuf = handl_buf(buf, 'x', ibuf);
			op = str[i];
			binary = fill_binary_array(binary, op, 0, 32);
			hex = fill_hex_array(binary, hex, 1, 8);
			ibuf = handl_buf(buf, hex[6], ibuf);
			ibuf = handl_buf(buf, hex[7], ibuf);
			sum += 3;
		}
		else
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	free(binary);
	free(hex);
	return (i + sum);
}
