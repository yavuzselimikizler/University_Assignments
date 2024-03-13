permutations = []

#An algorithm creates the sequence of movements required for the robot to perform its task and 

#subsequently calculates the cost of these sequences. While generating the sequences, it generates 

#all combinations as permutations using a permutation generation function and adds them to the list 

called "permutations."
cost_matrix = [ # the cost matrix corresponds energy costs one move to the another.
    [0, 8, 4, 5, 7],
    [3, 0, 1, 9, 10],
    [7, 2, 0, 4, 8],
    [5, 1, 3, 0, 2],
    [9, 4, 8, 6, 0]
]

def remove_items(item1, input_list): #removes the item from a list
    return [element for element in input_list if element != item1 ]

def generatePermutations(processes):
   # permutations = []
    for item in process: #iterate all the starting movement one by one.
        generatePermutationsHelper(processes,item, [])
    return permutations

def generatePermutationsHelper(process,current_item, currentAssignment):
    if not process or (len(process)== 1 and process[0]== current_item):
        print("here")
        permutations.append(currentAssignment)
        return
    
    for process1 in process: 
        
        if process1 != current_item:
            generatePermutationsHelper(
                remove_items(current_item, process.copy()),  # Make a copy of the process list
                process1,
                currentAssignment + [(current_item,process1 )], #add the sequence.
                    
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






process = ["p1", "p2", "p3", "p4", "p5"]
generatePermutations(process)
for item in permutations:
    print(item)

print(len(permutations))

min_cost, min_sequence=calculate_cost(process,permutations)

print("Minimum Cost:", min_cost)
print("Corresponding Sequence:", min_sequence)