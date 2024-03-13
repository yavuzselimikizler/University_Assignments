permutations = []

graph_matrix = [ #each row represents a graph value and the numbers represents connected vertices.
    [0, 2, 1, 0, 0],
    [2, 0, 0, 4, 0],
    [1, 0, 0, 0, 3],
    [0, 4, 0, 0, 5],
    [0, 0, 3, 5, 0]
]

cost_matrix = [ #cost matrix between paths
    [0, 8, 4, 5, 7],
    [8, 0, 1, 9, 10],
    [4, 1, 0, 4, 8],
    [5, 9, 4, 0, 2],
    [7, 10, 8, 2, 0]
]
def generatePermutationsHelper(process, current_index, currentAssignment):#generate all the possible sequences.
    
    if not process or (len(process) == 1 and process[0] == current_index + 1): 
        permutations.append(currentAssignment)
        return

    for item in range(len(process)):
        if process[item] != 0 and (item + 1) not in currentAssignment:
            if len(currentAssignment) > 1:

                permutations.append(currentAssignment)
            generatePermutationsHelper(
                graph_matrix[item],  # Use the original graph_matrix here
                item,
                currentAssignment + [item + 1],
            )


def generatePermutations(processes):
 
    for item in range(len(processes)):
        generatePermutationsHelper(processes[item], item, [item + 1])

    return permutations

def calculate_cost_helper(sequence_list):
    total_cost=0
    for item in range(len(sequence_list) - 1): #calculate the costs of each arbitrary element.

        total_cost += cost_matrix[sequence_list[item]-1][sequence_list[item+1]-1]

    return total_cost

def calculate_cost(path_list):
    min_value=1000
    min_path=[]

    for sequence in path_list:

        if calculate_cost_helper(sequence) < min_value:
            min_path = sequence
            min_value = calculate_cost_helper(sequence)


    return min_value,min_path

       






result = generatePermutations(graph_matrix)
print(result)

min_path,min_cost=calculate_cost(result)

print(min_path)
print(min_cost)