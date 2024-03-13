def secure_perimeter(sensors):
    # Sort sensors based on x-coordinates
    sorted_sensors = sorted(sensors, key=lambda sensor: sensor[0])
    
    # Call the recursive divide-and-conquer function
    return divide_and_conquer(sorted_sensors)

def divide_and_conquer(sorted_sensors):
    n = len(sorted_sensors)
    
    # Base case: if there are fewer than three sensors, activate all of them
    if n <= 2:
        return sorted_sensors
    
    # Divide the region into left and right halves
    mid = n // 2
    left_half = sorted_sensors[:mid]
    right_half = sorted_sensors[mid:]
    
    # Recursively find the optimal solution for the left and right halves
    left_solution = divide_and_conquer(left_half)
    right_solution = divide_and_conquer(right_half)
    
    # Combine the solutions to find the optimal solution for the entire region
    return combine_solutions(left_solution, right_solution)

def combine_solutions(left_solution, right_solution):
    # Merge the solutions from the left and right halves
    merged_solution = left_solution + right_solution
    
    # Sort the merged solution based on y-coordinates
    merged_solution = sorted(merged_solution, key=lambda sensor: sensor[1])
    
    # Initialize the final solution with the first sensor
    final_solution = [merged_solution[0]]
    
    # Iterate through the remaining sensors and add only those that contribute to the secure perimeter
    for sensor in merged_solution[1:]:
        if sensor[1] > final_solution[-1][1]:
            final_solution.append(sensor)
    
    return final_solution




