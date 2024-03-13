



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

    


    


    def print_node_preorder(self):

        self.pre_order_helper(self.root)

    def pre_order_helper(self,node):
        if not node:
            return
    
        print(node.data)
        self.pre_order_helper(node.left)
       
        self.pre_order_helper(node.right)

    
    


def is_balanced(root):
    balanced = [True]  # Using a list to hold the reference

    def is_balanced_helper(node, height):
        if node is None:
            return height

        height1 = is_balanced_helper(node.right, height + 1) #search right and left
        height2 = is_balanced_helper(node.left, height + 1)

        if abs(height1 - height2) > 1 and balanced[0]: #find any inbalancing issues.
            print("unbalanced")
            balanced[0] = False #saves it in balanced array.

        return max(height1, height2)

    get_height = is_balanced_helper(root.root, 0)
    print("Tree is balanced." if balanced[0] else "Tree is unbalanced")

def height_of_tree(root):

    if root.root == None:
        return

    get_height = height_of_tree_helper(root.root,0)

    print(get_height)
    
def height_of_tree_helper(root,height):

    if(root == None):
        return height
    height+=1
    height1=height_of_tree_helper(root.right,height) #search the trees left and right sides.
    height2=height_of_tree_helper(root.left,height)

    if height1 > height2: # returns the bigger one as height.
        return height1

    return height2
     



    

    





# Example usage:
bst = BinarySearchTree()
bst.insert_value(5)
bst.insert_value(3)
bst.insert_value(7)
bst.insert_value(2)
bst.insert_value(4)
bst.insert_value(9)
bst.insert_value(11)
bst.insert_value(13)
bst.insert_value(15)


print("\n")
bst.print_node_preorder()
print("...............Tree Height Test............\n")
height_of_tree(bst)
print("...............Is Balanced Test.................\n")
is_balanced(bst)

