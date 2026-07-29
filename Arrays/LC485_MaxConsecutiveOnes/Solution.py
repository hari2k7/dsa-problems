def max_consecutive_ones(arr):
    current_count = 0
    max_count = 0

    for num in arr:
        if num == 1:
            current_count += 1
            if max_count < current_count:
                max_count = current_count
        else:
            current_count = 0

    return max_count


arr = [1, 1, 0, 1, 1, 1, 0, 1, 1]
print(max_consecutive_ones(arr))