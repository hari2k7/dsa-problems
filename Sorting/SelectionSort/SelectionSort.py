def selectionsort(arr):
    for i in range(len(arr)-1):
        min = i
        for j in range(i+1 ,len(arr)):
            if(arr[j]<arr[min]):
                min = j
        temp = arr[min]
        arr[min] = arr[i]
        arr[i] = temp
    return arr

print(selectionsort([9,3,5,7]))