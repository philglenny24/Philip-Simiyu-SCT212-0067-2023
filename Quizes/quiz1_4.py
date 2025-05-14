def find_single_number(numbers):
    running_xor=0
    for current_number in numbers:
        running_xor=running_xor^current_number
    return running_xor

test_Array=[4,1,2,1,2]
result=find_single_number(test_Array)
print(f"single number found: {result}")

