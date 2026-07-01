def binarysearch(arr, key):
    low = 0
    high = len(arr)-1
    while(low<=high):
        mid = (low + high)//2
        if(arr[mid]==key):
            return mid
        elif(arr[mid] < key):
            low = mid + 1
        else:
            high = mid - 1

print(binarysearch([2,4,6,8,9],9))
