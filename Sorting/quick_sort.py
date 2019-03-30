def partition(arr,low,high):
    """Take the last element and find its correct position in array
    i.e. element to left of it should be less than it, and to the right 
    of it should be greater than it. where "it" refers to last element / pivot element.
    
    low : starting of array
    high : index of last element of array len(arr) - 1"""

    I = low - 1
    pivot = arr[high] # pivot is the last element of the array (corman book convention)

    for x in range(low,high):

        if arr[x] < pivot:
            I +=1
            arr[I], arr[x] = arr[x], arr[I]
    
    # after forloop, all element upto index I is less than pivot
    # so pivot correct position should be I+1
    # hence exchange I+1 with pivot
    
    I += 1
    arr[I],arr[high] = arr[high], arr[I]

    return I # i.e this is in correct position, change it's sidelings arrays


def quick_sort_recursive(arr,low,high):

    if low < high:

        pivot = partition(arr,low,high)
        quick_sort_recursive(arr,pivot+1,high)
        quick_sort_recursive(arr,0,pivot-1)




if __name__ == "__main__":
    arr = [8,2,3,7,9,1,5]
    arr = [7,5,6,9,3,1,2,3,6,4,9,0,-1,-7,5,4]
    partition(arr,0,len(arr)-1)
    quick_sort_recursive(arr,0,len(arr)-1)
    print(arr)

