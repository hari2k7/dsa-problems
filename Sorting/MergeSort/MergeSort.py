def mergesort(arr):
    length = len(arr)
    if(length <= 1):
        return

    mid = length // 2

    leftarray = []
    rightarray = []

    j = 0

    for i in range(length):
        if(i<mid):
            leftarray.append(arr[i])
        else:
            rightarray.append(arr[i])
            j+=1
    
    mergesort(leftarray)
    mergesort(rightarray)
    merge(leftarray, rightarray, arr)

def merge(leftarray, rightarray, arr):
    l = 0
    r = 0
    i = 0
    while(l<len(leftarray) and r<len(rightarray)):
        if(leftarray[l] < rightarray[r]):
            arr[i] = leftarray[l]
            l += 1
            i += 1
        else:
            arr[i] = rightarray[r]
            r += 1
            i += 1
    
    while(l<len(leftarray)):
        arr[i] = leftarray[l]
        l += 1
        i += 1
    while (r<len(rightarray)):
        arr[i] = rightarray[r]
        r += 1
        i += 1

arr = [9,3,4,8,1]
mergesort(arr)
print(arr)
