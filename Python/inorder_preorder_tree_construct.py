class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def __str__(self):
        return str(self.data)


def constructTree(inorder, preorder, startIndex, endIndex, current, max_len):

    if (current > max_len):
        return None
    
    print("** ", preorder[current-1], " (", startIndex, endIndex,max_len," )",current)
    if startIndex > endIndex:   # because that side it will have no node
        return None

    element = preorder[current]
    tNode = Node(element)
    current +=  1

    if startIndex is endIndex:  # it means iske left aur right side me kuch nahi hai
        return tNode

    else:
        index = search(inorder, element)
        tNode.left = constructTree(inorder, preorder, startIndex, index - 1, current,max_len)
        print("             ", tNode.data,"LEFT ", tNode.left)
        tNode.right = constructTree(inorder, preorder, index + 1, endIndex, current, max_len)
        print("             ", tNode.data,"RIGHT ", tNode.right)

        return tNode


def search(inorder, element):
    i = 0
    for x in inorder:
        if x is element:
            return i

        else:
            i += 1

    return None


if __name__ == "__main__":
    # ino = [5, 4, 11, 6, 2, 7, 1, 9, 10, 12, 8, 3, 13]
    # preo = [1,2,4,5,6,11,7,3,8,9,10,12,13]
    # ino = [4,2,5,1,3,6]
    # preo = [1,2,4,5,3,6]
    ino = [4,5,2,1,8,3,10,9]
    preo = [1,2,4,5,3,8,9,10]

    root = constructTree(ino, preo, 0, len(ino) -1, 0, len(ino) - 1)
    print(root.data)
    print(root.left.data)
    print(root.right.data)
