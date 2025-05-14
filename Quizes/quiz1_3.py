def has_duplicate(numbers_list):
    numbers_list.sort()

    for i in range(len(numbers_list) - 1):
        curr=numbers_list[i]
        next=numbers_list[i+1]

        if curr == next:
            return True
    return False

print(has_duplicate([1,2,4,8,2,7,3]))
print(has_duplicate([11,12,10,6,15]))
