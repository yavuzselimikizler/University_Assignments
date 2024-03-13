combinations = []
change_value=100
#It generates various combinations of unique coins with different denominations in the permutation

 #function until a threshold value is reached. The generated combinations are stored in the

# "combinations" list, and it aims to find the combination with the least coin value.
def remove_items(item1, input_list):
    return [element for element in input_list if element != item1 ]

def generatePermutations(processes):
   # permutations = []
    for item in processes:
        generatePermutationsHelper(processes,item,item, [item])
    return combinations

def generatePermutationsHelper(process,current_value,current_item, currentAssignment):
    if current_value ==change_value: #until reaching the change_value.
        combinations.append(currentAssignment)
        print(current_value)
        return
    if not process or (len(process)== 1 and process[0]== current_item):
        
        return
   
    for process1 in process:
        
        if process1 != current_item:
            generatePermutationsHelper(
                remove_items(current_item, process.copy()),  # Make a copy of the process list
                current_value + process1,
                process1,
                currentAssignment + [process1],
                    
            )

def calculate_cost_helper(sequence,process):

    total_cost = 0

    for item in sequence:
        # Ensure both items in the pair are in the process list
        if item[0] in process and item[1] in process:
            index_0 = process.index(item[0])
            index_1 = process.index(item[1])
            total_cost += cost_matrix[index_0][index_1]

    return total_cost

            


def calculate_cost(process,permutations):

    min_sequence=permutations[0]
    min_cost=calculate_cost_helper(min_sequence,process)

    for item in permutations:
        current_sequence_cost = calculate_cost_helper(item,process)
        if min_cost > current_sequence_cost:
            min_cost=current_sequence_cost
            min_sequence=item

    return min_cost, min_sequence 

coin_values=[15, 4, 22, 17, 28, 10, 2, 12]

generatePermutations(coin_values)

print(combinations)
print(len(combinations))
