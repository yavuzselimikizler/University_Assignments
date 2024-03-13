tasks = [1, 2, 3, 4, 5, 6]
resource_amount = [12, 11, 13, 5, 6, 7]

def get_max_min(arr, task_list):
    sorted_resources, sorted_tasks = merge_sort(arr, task_list)

    return sorted_resources[0], sorted_resources[-1], sorted_tasks[0], sorted_tasks[-1]

def merge_sort(arr, task_list): # merge sort algorithm to sort the resource values and with the source values.
    if len(arr) <= 1:
        return arr, task_list

    mid = len(arr) // 2
    left_half, left_task = merge_sort(arr[:mid], task_list[:mid]) #divide the tasks and resources by mid value.
    right_half, right_task = merge_sort(arr[mid:], task_list[mid:])

    return merge(left_half, left_task, right_half, right_task)

def merge(left, left_task, right, right_task): #merge each task and resouce sub sets .
    result = []
    task_indexes = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            task_indexes.append(left_task[i])
            i += 1
        else:
            result.append(right[j])
            task_indexes.append(right_task[j])
            j += 1

    result.extend(left[i:])
    task_indexes.extend(left_task[i:])
    result.extend(right[j:])
    task_indexes.extend(right_task[j:])

    return result, task_indexes

# Example usage:
min_resource, max_resource, min_task_index, max_task_index = get_max_min(resource_amount, tasks)
print("min_task:", min_task_index, "max_task", max_task_index, "min resource:", min_resource, "max resource:", max_resource)