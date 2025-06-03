#!/usr/bin/python3
"""
rotate a 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n 2D matrix 90 degrees clockwise in-place.
    """
    n = len(matrix)

    # Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for i in range(n):
        matrix[i].reverse()


def print_matrix(matrix):
    """
    Prints a 2D matrix in a formatted way.
    """
    for row in matrix:
        print(row)
