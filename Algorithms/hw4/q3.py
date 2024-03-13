coordinate_values = [2, 1, 2, -2, 1, -1, 1]

def find_combinations(sub_divider):
    sub_arr = coordinate_values[:sub_divider]
    combinations = []
    for i in range(0, sub_divider): #create all the sub clusters from 1 to current index ex: for 3 (1) (2) (1,2) (1,2,3)
        combinations.append(sub_arr[-i:])

    return combinations

def find_max_area(coordinates):
    all_combinations = [] # holds all the cluster sequences
    for i in range(len(coordinates)):
        new_combinations = find_combinations(i) #O(n)
        
        for item in new_combinations: # O(n) 
            all_combinations.append(item)
            key = sum(item)
            current_index = len(all_combinations) - 2
            
            while current_index >= 0 and (key < sum(all_combinations[current_index])): #O(n) and w(1) #ı used insertion sort model to put the sub sequence clusters into increasing order.
                all_combinations[current_index + 1] = all_combinations[current_index]
                current_index -= 1
            if len(all_combinations)>1:
                all_combinations[current_index +1] = item
   # print(all_combinations)
    return all_combinations[len(all_combinations) - 1]

return_value = find_max_area(coordinate_values)
print(return_value)