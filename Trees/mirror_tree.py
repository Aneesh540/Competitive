
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


def mirror_image(root):
    if root: 
        mirror_image(root.left)
        mirror_image(root.right)

        root.left, root.right = root.right, root.left


if __name__ == "__main__":
    root = Node(3)
    root.right = Node(5)
    root.left = Node(12)

    root.right.left = Node(11)
    root.right.right = Node(45)
    root.left.left = Node(31)
    root.left.left.left = Node(99)


    inorder(root)
    mirror_image(root)
    print("************")
    inorder(root)


    #         3
    #       /   \
    #     12     5
    #    /     /   \
    #  31     11   45 
    #  /
    # 99
    #
