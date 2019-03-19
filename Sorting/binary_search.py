arr = [2,3,6,7,8,9,10,11,13,14,16]

def binary_search(left,right,value):

    middle_index = (left+right)//2
    middle_value = arr[middle_index]

    if middle_value is value:
        return middle_index
    
    elif middle_value < value:
        left = middle_index
        binary_search(left,right,value)
    
    else: # middle is more 
        right = middle_index
        binary_search(left,right,value)
    