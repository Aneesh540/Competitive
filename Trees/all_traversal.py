class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def __init__(self, rootNode):
        self.rootNode = rootNode
        self.traversal = []
    


if __name__ == "__main__":
    root = Node(3)
    root.left = Node(4)
    root.right = Node(5)
    root.left.left = Node(6)
    root.left.left.right = Node(7)
    
    root.right = Node(12)
    root.right.left = Node(13)
    root.right.right = Node(15)
