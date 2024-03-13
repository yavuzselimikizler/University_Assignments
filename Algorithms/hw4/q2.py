

def find_unique_brightest_pixel(matrix, start_row, end_row, start_col, end_col):
    # Base case: if the submatrix is a single pixel, return its value
    if start_row == end_row and start_col == end_col:
        return matrix[start_row][start_col]

    # Find the middle row and column of the submatrix
    mid_row = (start_row + end_row) // 2
    mid_col = (start_col + end_col) // 2

    # Compare the middle pixel with its neighbors to determine the monotonicity
    brightest = matrix[mid_row][mid_col]

    # Check if the middle pixel is brighter than its neighbors
    if (mid_row > 0 and brightest <= matrix[mid_row - 1][mid_col]) or \
       (mid_row < len(matrix) - 1 and brightest <= matrix[mid_row + 1][mid_col]) or \
       (mid_col > 0 and brightest <= matrix[mid_row][mid_col - 1]) or \
       (mid_col < len(matrix[0]) - 1 and brightest <= matrix[mid_row][mid_col + 1]):
        # Recursively search in the quadrant with the potential unique brightest pixel
        if mid_row > 0 and brightest < matrix[mid_row - 1][mid_col]:
            # Search in the top submatrix
            return find_unique_brightest_pixel(matrix, start_row, mid_row - 1, start_col, end_col)
        elif mid_row < len(matrix) - 1 and brightest < matrix[mid_row + 1][mid_col]:
            # Search in the bottom submatrix
            return find_unique_brightest_pixel(matrix, mid_row + 1, end_row, start_col, end_col)
        elif mid_col > 0 and brightest < matrix[mid_row][mid_col - 1]:
            # Search in the left submatrix
            return find_unique_brightest_pixel(matrix, start_row, end_row, start_col, mid_col - 1)
        elif mid_col < len(matrix[0]) - 1 and brightest < matrix[mid_row][mid_col + 1]:
            # Search in the right submatrix
            return find_unique_brightest_pixel(matrix, start_row, end_row, mid_col + 1, end_col)
    else:
        return brightest  # Found the unique brightest pixel

# Example usage:
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]

result = find_unique_brightest_pixel(matrix, 0, len(matrix) - 1, 0, len(matrix[0]) - 1)
print(result)
