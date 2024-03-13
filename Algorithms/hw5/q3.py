def align_dna_sequences(seq1, seq2):
    m, n = len(seq1), len(seq2)
    
    # Initialize a 2D matrix for dynamic programming
    dp_matrix = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Fill in the matrix
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp_matrix[i][j] = j  # cost of inserting j characters
            elif j == 0:
                dp_matrix[i][j] = i  # cost of deleting i characters
            else:
                # Calculate the cost of insertion, deletion, and substitution
                insertion_cost = dp_matrix[i][j - 1] + 1
                deletion_cost = dp_matrix[i - 1][j] + 1
                substitution_cost = dp_matrix[i - 1][j - 1] + (3 if seq1[i - 1] != seq2[j - 1] else 0)
                
                # Choose the minimum cost
                dp_matrix[i][j] = min(insertion_cost, deletion_cost, substitution_cost)
    
    # Trace back to find the sequence of operations with minimum cost
    operations = []
    i, j = m, n
    while i > 0 or j > 0:
        if i > 0 and j > 0 and dp_matrix[i][j] == dp_matrix[i - 1][j - 1] + (3 if seq1[i - 1] != seq2[j - 1] else 0):
            # Substitution or no operation
            if seq1[i - 1] != seq2[j - 1]:
                operations.append(f"Substitute {seq1[i - 1]} at position {i} with {seq2[j - 1]}")
            i -= 1
            j -= 1
        elif j > 0 and dp_matrix[i][j] == dp_matrix[i][j - 1] + 1:
            # Insertion
            operations.append(f"Insert {seq2[j - 1]} at position {i + 1}")
            j -= 1
        else:
            # Deletion
            operations.append(f"Delete {seq1[i - 1]} at position {i}")
            i -= 1
    
    # Reverse the operations to get the correct order
    operations.reverse()
    
    # Calculate the total cost
    total_cost = dp_matrix[m][n]
    
    return operations, total_cost


