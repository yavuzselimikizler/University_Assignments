#The given code defines a recursive function find_highest_discount that aims to find the combination of stores that results in the highest discount.

def find_highest_discount(remaining_stores, current_set_of_stores, current_discount):
    if not remaining_stores:
        # Base case: no more stores to consider
        return current_set_of_stores, current_discount

    # Explore two possibilities: include the current store or skip it
    include_store = find_highest_discount(
        remaining_stores[1:],
        current_set_of_stores + [remaining_stores[0]],
        current_discount + calc_discount(current_set_of_stores + [remaining_stores[0]])
    )
    
    exclude_store = find_highest_discount(
        remaining_stores[1:],
        current_set_of_stores,
        current_discount
    )

    # Return the set of stores resulting in the highest discount
    if include_store[1] > exclude_store[1]:
        return include_store
    else:
        return exclude_store

result = find_highest_discount(stores, [], 0)

print("Stores for Highest Discount:", result[0])
print("Highest Discount:", result[1])
