permutations = []
#It generates all possible sequencing combinations considering that each processor has different 

#cost values for different users and processes. It calculates the cost values based on a 3D matrix, 

#and then identifies the sequence that contains the minimum cost value, marking it as the optimal one.
cost_matrix = [
    [
        [2, 8, 5, 3, 7],
        [1, 6, 4, 9, 10],
        [5, 3, 7, 2, 8],
        [9, 4, 6, 1, 10],
        [7, 2, 8, 10, 3]
    ],
    [
        [3, 1, 6, 4, 9],
        [8, 7, 2, 5, 10],
        [4, 9, 10, 3, 1],
        [6, 5, 8, 2, 7],
        [10, 3, 1, 7, 4]
    ],
    [
        [5, 2, 8, 10, 4],
        [3, 1, 7, 9, 6],
        [8, 10, 4, 6, 2],
        [7, 9, 3, 1, 5],
        [6, 4, 2, 5, 8]
    ],
    [
        [1, 3, 10, 4, 6],
        [2, 8, 5, 7, 9],
        [4, 6, 1, 8, 3],
        [5, 7, 9, 10, 2],
        [8, 10, 3, 2, 1]
    ],
    [
        [9, 5, 2, 6, 8],
        [7, 4, 1, 3, 10],
        [10, 6, 8, 5, 9],
        [3, 2, 7, 1, 4],
        [1, 9, 10, 4, 5]
    ]
]

def remove_items(item1, input_list):
    return [element for element in input_list if element != item1 ]

def generatePermutations(processes,users):
   # permutations = []
    
    generatePermutationsHelper(processes,users, [])
    return permutations

def generatePermutationsHelper(users,process, currentAssignment):
    if not process or not users:
        
        permutations.append(currentAssignment)
        return
    for user in users:
        for process1 in process:
        
            
                generatePermutationsHelper(
                    remove_items(user,users.copy()),
                    remove_items(process1, process.copy()),  # Make a copy of the process list
                    
                   
                    currentAssignment + [(user,process1 )],
                    
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

            
def calculate_cost_helper(min_sequence,process,user):
    cost=0
    index=0
    for item in min_sequence: #finds the cost value with corresponding indexes.
        index_0 = user.index(item[1])
        index_1 = process.index(item[0])
        cost += cost_matrix[index][index_1][index_0]
        index+=1
    return cost
def calculate_cost(process,permutations,user):

    min_sequence=permutations[0]
    min_cost=calculate_cost_helper(min_sequence,process,user)

    for item in permutations:
        current_sequence_cost = calculate_cost_helper(item,process,user)
        if min_cost > current_sequence_cost:
            min_cost=current_sequence_cost
            min_sequence=item

    return min_cost, min_sequence





users=["user1","user2","user3","user4","user5"]
process = ["process1", "process2", "process3", "process4", "process5"]
generatePermutations(process,users)
for item in permutations:
    print(item)

print(len(permutations))

min_cost, min_sequence=calculate_cost(process,permutations,users)

print("Minimum Cost:", min_cost)
print("Corresponding Sequence:", min_sequence)
