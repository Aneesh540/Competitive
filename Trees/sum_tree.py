
class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


def inorder(node):
    if node:
        print(node.data)
        inorder(node.left)
        inorder(node.right)


def sum_tree(root):

    if root:
        a = root.left
        b = root.right

        if a == None:
            a = 0
        else: 
            a = a.data

        if b == None:
            b  = 0
        else:
            b = b.data

        root.data = a + b + sum_tree(root.left) + sum_tree(root.right)
        return root.data
    
    else:
        return 0



if __name__ == "__main__":
    root = Node(3)
    root.right = Node(5)
    root.left = Node(2)

    root.right.left = Node(1)
    root.right.right = Node(4)
    root.left.left = Node(3)
    root.left.left.left = Node(9)

    sum_tree(root)

    inorder(root)

    #         3
    #       /   \
    #      2     5
    #    /     /   \
    #   3     1     4
    #  /
    # 9
    #
