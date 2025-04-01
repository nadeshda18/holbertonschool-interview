#!/usr/bin/python3
""" Usage: If the user called the program with the wrong number of arguments,
print Usage: nqueens N, followed by a new line, and exit with the status 1
where N must be an integer greater or equal to 4
If N is not an integer, print N must be a number, followed by a new line,
and exit with the status 1
If N is smaller than 4, print N must be at least 4, followed by a new line,
and exit with the status 1
The program should print every possible solution to the problem
One solution per line
Format: see example
You don’t have to print the solutions in a specific order
You are only allowed to import the sys module
"""
import sys


def is_safe(board, row, col):
    """
    Check if it's safe to place a queen at board[row][col].
    """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, len(board)), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens(board, col, solutions):
    """
    Solve the N Queens problem using backtracking.
    """
    if col == len(board):
        solution = []
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return

    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 1
            solve_nqueens(board, col + 1, solutions)
            board[i][col] = 0


def nqueens(N):
    """
    Solve the N Queens problem and print all solutions.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_nqueens(board, 0, solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    nqueens(len(sys.argv))
