def merge(arr, low, mid, high):
    size = (high - low)
    temp = [0]*size

    ptr1, ptr2 = low, mid
    print(arr[ptr1],arr[ptr2])

    for i in range(size):

        if ptr1 is mid: # at the end of first list
            temp[i] = arr[ptr2]
            ptr2 +=1
        
        elif ptr2 is high:
            temp[i] = arr[ptr1]
            ptr1 +=1


        elif arr[ptr1] <= arr[ptr2]:
            temp[i] = arr[ptr1]
            ptr1 += 1
        
        else:
            temp[i] = arr[ptr2]
            ptr2 += 1

        j = 0
        for i in range(low,high):
            arr[i] = temp[j]
            j += 1 
    print(arr)
    print("-----> ", temp)

def mergeSort(arr,low,high):

    if low < high:
        mid = (low + high)//2
        mergeSort(arr,low,mid)
        mergeSort(arr,mid+1,high)
        merge(arr,low,mid,high)

if __name__ == "__main__":
    arr = [11,7,12,2,3,19]
    merge(arr,0,2,5)
    mergeSort(arr,0,len(arr)-1)
    print(arr)
        
