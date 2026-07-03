def insertionsort(arr):
    for i in range(len(arr)):
        temp = arr[i]
        j = i - 1
        while(j >= 0 and arr[j] > temp):
            arr[j + 1] = arr[j]
            j-=1
        arr[j + 1] = temp
    
    return arr

print(insertionsort([8,6,4,7,5,1,3]))