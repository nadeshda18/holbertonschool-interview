#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - Checks if a string is composed of digits.
 * @str: The string to check.
 *
 * Return: 1 if the string is composed of digits, 0 otherwise.
 */
int is_digit(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

/**
 * print_error - Prints an error message and exits with status 98.
 */
void print_error(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * multiply - Multiplies two large numbers represented as strings.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: The result as a string.
 */
char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int *result = calloc(len1 + len2, sizeof(int));
    char *final_result;
    int i, j;

    if (!result)
        print_error();

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
        print_error();

    for (i = 0, j = 0; i < len1 + len2; i++)
    {
        if (j || result[i])
            final_result[j++] = result[i] + '0';
    }
    final_result[j] = '\0';

    free(result);
    return (final_result[0] ? final_result : "0");
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: The arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        print_error();

    result = multiply(argv[1], argv[2]);
    printf("%s\n", result);
    free(result);

    return (0);
}