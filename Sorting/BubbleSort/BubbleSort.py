def bubblesort(arr):
    for i in range(len(arr),0,-1):
        for j in range(i-1):
            if arr[j]>arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr

print(bubblesort([6,8,1,3,5]))