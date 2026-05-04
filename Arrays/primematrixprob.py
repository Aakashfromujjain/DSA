import sys

def solve():
    # Precompute primes up to 10,000 using Sieve
    MAX_VAL = 10001
    is_prime = [True] * MAX_VAL
    is_prime[0] = is_prime[1] = False
    for p in range(2, int(MAX_VAL**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, MAX_VAL, p):
                is_prime[i] = False

    # Read N
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    matrix = []
    idx = 1
    for i in range(N):
        matrix.append([int(x) for x in input_data[idx : idx + N]])
        idx += N

    rows_to_mark = [False] * N
    cols_to_mark = [False] * N

    # Identify which rows and columns contain a prime
    for r in range(N):
        for c in range(N):
            val = matrix[r][c]
            if val < MAX_VAL and is_prime[val]:
                rows_to_mark[r] = True
                cols_to_mark[c] = True

    # Build and print the modified matrix
    for r in range(N):
        row_output = []
        for c in range(N):
            if rows_to_mark[r] or cols_to_mark[c]:
                row_output.append("-1")
            else:
                row_output.append(str(matrix[r][c]))
        print(" ".join(row_output))

if __name__ == "__main__":
    solve()
