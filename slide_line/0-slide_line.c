#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: number of elements in line
 * @direction: left or right
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for (i = size - 1; (int)i >= 0; i--)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; (int)j >= 0; j--)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }
        for (i = size - 1; (int)i >= 0; i--)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; (int)j >= 0; j--)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    return (1);
}
