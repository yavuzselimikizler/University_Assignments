


cable = [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0] #1 represent curren flow and 0 0 represents uncharged.

def find_flawed(sub_cable, start, end):
    mid_point = (start + end) // 2

    if sub_cable[mid_point] == 1 and sub_cable[mid_point + 1] == 0: #try to find the interval that 1 and 0.
        return mid_point + 1
    elif sub_cable[mid_point] == 0 and sub_cable[mid_point - 1] == 1:
        return mid_point - 1
    elif sub_cable[mid_point] == 1:
        return find_flawed(sub_cable, mid_point + 1, end) #otherwise if the mid point recurse twords right.
    else:
        return find_flawed(sub_cable, start, mid_point - 1) #else call by searching left.

flawed_cable_index = find_flawed(cable, 0, len(cable) - 1)
print(flawed_cable_index)
