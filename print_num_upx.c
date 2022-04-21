#include "main.h"

/**
 * prinnupx - prints number in uppercase hex
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinnupx(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hex, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'X', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = fill_hex_array(binary, hex, 1, 8);
	for (first_digit = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hex[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hex);
	return (count + 2);
}
