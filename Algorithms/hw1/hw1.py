



class Node:
    
    def __init__(self,value):
        self.data=value
        self.right=None
        self.left=None


class BinarySearchTree:

    def __init__(self):
        self.root=None
        self.nth=0
        self.result=0

    def insert_value(self,value):
        new_node=Node(value)

        if self.root==None:
            
            self.root=new_node

        else:
            self.insert_recursively(self.root,new_node)
    
    def insert_recursively(self,current_node,new_node):

        if current_node.data>new_node.data :
            if current_node.left==None:
                current_node.left=new_node
            else:
                self.insert_recursively(current_node.left,new_node)
        elif current_node.data < new_node.data:
            if current_node.right==None:
                current_node.right=new_node
            else:
                self.insert_recursively(current_node.right,new_node)
        else:
            current_node=new_node

    def inorderRangeSearch(self, low, high):
        result = []
        self.inorderRangeSearchHelper(self.root, low, high, result) # visiting all the nodes takes O(n) time.
        return result

    def inorderRangeSearchHelper(self,node, low, high, result):
        if not node:
            return
    
    
        self.inorderRangeSearchHelper(node.left, low, high, result) 
    
    
        if low <= node.data <= high: #compare the item if its between the range takes O(1) time 
            result.append(node.data)
    
    
        self.inorderRangeSearchHelper(node.right, low, high, result)


    def inordersmallestSearch(self, nth): # nth represents nth smallest item.
        self.nth=nth
        self.inordersmallersearchHelper(self.root,  )
        return self.result

    def inordersmallersearchHelper(self,node): #inorder search to search from smallest to biggest.
        if not node:
            return
    
    
        self.inordersmallersearchHelper(node.left)
       
        self.nth=self.nth-1 #for every check decrease the nth variable by 1.
        
        if self.nth==0: #when it comes to nth value in binary search tree assign the value to result. takes O(1) time.
            self.result=node.data
           
                                    #visits all the nodes so the time complexity is O(n) time.
    
        self.inordersmallersearchHelper(node.right)


    def print_node_preorder(self):

        self.pre_order_helper(self.root)

    def pre_order_helper(self,node):
        if not node:
            return
    
        print(node.data)
        self.pre_order_helper(node.left)
       
        self.pre_order_helper(node.right)

    def search_value(self,value):
        returned=False
        if self.root==None:
            print('the tree is empty')
        else:
          returned=  self.inorder_search(self.root,value)
        return returned
    
    def inorder_search(self,current_node,value):

        returned=False
        if current_node.left != None:
           returned= returned | self.inorder_search(current_node.left,value)
        
        print(current_node.data)
        if current_node.data==value:
           
            return True
        
        if current_node.right != None:
            returned=returned | self.inorder_search(current_node.right,value)



        return returned
    
def mergeTrees(root1, root2):
    def inOrderTraversal(node, result): #inorder travesle of bt 
        if not node:
            return
        inOrderTraversal(node.left, result) #left node.
        result.append(node.data) #add the items to the list.
        inOrderTraversal(node.right, result) #right node.

    # Step 1: Perform in-order traversal of both BSTs
    list1, list2 = [], []
    inOrderTraversal(root1.root, list1) # add the two bt items to the list O(n)
    inOrderTraversal(root2.root, list2) 

    # Step 2: Merge sorted lists
    merged_list = []
    i, j = 0, 0
    while i < len(list1) and j < len(list2): # loop through list take O(n) time.
        if list1[i] < list2[j]:
            merged_list.append(list1[i])
            i += 1
        else:
            merged_list.append(list2[j])
            j += 1
    merged_list.extend(list1[i:])
    merged_list.extend(list2[j:])

    # Step 3 and 4: Construct new BST from merged sorted list
    def sortedListToBST(left, right):
        if left > right:
            return None
        mid = (left + right) // 2
        node = Node(merged_list[mid])  # Create n node so it takes O(n) time.
        node.left = sortedListToBST(left, mid - 1)
        node.right = sortedListToBST(mid + 1, right)
        return node

    return sortedListToBST(0, len(merged_list) - 1)
   

# Example usage:
bst = BinarySearchTree()
bst.insert_value(5)
bst.insert_value(3)
bst.insert_value(7)
bst.insert_value(2)
bst.insert_value(4)

bst2 = BinarySearchTree()

bst2.insert_value(6)
bst2.insert_value(9)
bst2.insert_value(8)
bst2.insert_value(1)
bst2.insert_value(10)

# Search for a value in the BST
search_result = bst.search_value(4)
if search_result:
    print(f"Value found: ")
else:
    print("Value not found")

item_list=bst.inorderRangeSearch(2,5)
print(item_list)

smallest=bst.inordersmallestSearch(2)
print(smallest)

merget_tree= BinarySearchTree()
merget_tree.root=mergeTrees(bst,bst2)

merget_tree.print_node_preorder()


