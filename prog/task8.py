def is_safe(board, row, col):
    # Check previous columns
    for i in range(col):
        if board[i] == row or abs(board[i] - row) == abs(i - col):
            return False
    return True


def solve(board, col, n, solutions):
    if col == n:  # All queens placed
        solutions.append(board[:])  # store a copy
        return True

    res = False
    for i in range(n):
        if is_safe(board, i, col):
            board[col] = i
            res = solve(board, col + 1, n, solutions) or res
            board[col] = -1  # backtrack
    return res


def print_board(solution):
    n = len(solution)
    for row in range(n):
        line = ""
        for col in range(n):
            if solution[col] == row:
                line += " Q "
            else:
                line += " . "
        print(line)
    print()  # blank line between solutions


def eight_queens():
    N = 8
    board = [-1] * N
    solutions = []
    solve(board, 0, N, solutions)

    # Print all solutions visually
    for idx, sol in enumerate(solutions, 1):
        print(f"Solution {idx}: {sol}")
        print_board(sol)

    print(f"\nTotal solutions for 8-Queens: {len(solutions)}")


if __name__ == "__main__":
    eight_queens()