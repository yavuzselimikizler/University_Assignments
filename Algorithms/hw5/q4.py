def min_energy_cost(parts, energy_cost_matrix):
    n = len(parts)

    # Initialize a 2D memoization table to store intermediate results
    memo = [[float('inf')] * n for _ in range(n)]

    # Base case: the cost of assembling a single part is the energy cost from the current position
    for i in range(n):
        memo[i][i] = 0  # Set the base case energy cost to 0 as it's assembling from the same position

    # Fill in the memoization table using bottom-up dynamic programming
    
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            for k in range(i, j):
                # Calculate the energy cost for assembling parts[i] to parts[j] from the current position
                cost = memo[i][k] + memo[k + 1][j] + energy_cost_matrix[parts[i]][parts[k]]
                
                # Update the memo table with the minimum cost
                memo[i][j] = min(memo[i][j], cost)



    # The minimum energy cost for assembling the entire product is stored in the top-right cell of the memo table
    return memo[0][n - 1]

# Example usage

