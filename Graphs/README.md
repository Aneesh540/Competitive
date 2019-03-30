# Graphs Algorithm Summary

## Disjoint Set Union Naive Approach `O(n)`
> 
```python
 def Union_Naive(node1, node2):
        find node1 parent (p1), and node2 parent(p2)
        i.e. value present at arr[node1] & arr[node2]
        
        >> if any element in array has (p2) replace it by (p1)
   
```

## Disjoint Set Union Improved `[O(logn):average, O(n): Worst]`
```python
>> parent node is that whose : arr[node] = node
>> Union(node1, node2) : find parent(root) of node1 & node2, and make node2 root as child of node1

def root(node):
        if arr[node] == node: 
		return (node)
        else: 
		return root(arr[node])

def Union(node1, node2):
	root_node1, root_node2 = root(node1), root(node2)
	arr[root_node2] = arr[root_node1]
```
## Union By rank and Path compression `O(logn)` worst
```python
arr = [-1,-3,2,1,-1] >> -ve defines that it is parent node, +ve defines that his parent is that +ve number

def root(node1):
	pass(same)

def Union(node1, node2):
	if size(node1) > size(node2):
		## node 1 will be parent ##
		
		arr[root_node1] = -(element_node1 + elemet_node2)
		arr[root_node2] = root_node1

```
