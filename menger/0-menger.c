#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (is_hole(row, col))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}

/**
 * is_hole - Determines if a position is part of a hole in the Menger Sponge
 * @row: The row index
 * @col: The column index
 *
 * Return: 1 if the position is a hole, 0 otherwise
 */
int is_hole(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3;
        col /= 3;
    }
    return (0);
}