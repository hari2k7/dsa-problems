def SortedAndRotated(nums):
    count = 0

    for i in range(len(nums) - 1):
        if nums[i] > nums[i + 1]:
            count += 1

    if nums[-1] > nums[0]:
        count += 1

    return count <= 1


nums = [3, 4, 5, 1, 2]
print(SortedAndRotated(nums))
