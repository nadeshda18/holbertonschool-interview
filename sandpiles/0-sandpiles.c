#include <stdio.h>
#include "sandpiles.h"

void print_grid(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;

    // Sum the grids
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Check and topple until stable
    while (!stable)
    {
        stable = 1;
        int temp[3][3] = {0};

        // Check stability and prepare toppling
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    stable = 0;
                    temp[i][j] -= 4;
                    if (i > 0) temp[i - 1][j] += 1;
                    if (i < 2) temp[i + 1][j] += 1;
                    if (j > 0) temp[i][j - 1] += 1;
                    if (j < 2) temp[i][j + 1] += 1;
                }
            }
        }

        // Print grid if unstable
        if (!stable)
        {
            printf("=\n");
            print_grid(grid1);
        }

        // Apply toppling
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                grid1[i][j] += temp[i][j];
            }
        }
    }
}

void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
