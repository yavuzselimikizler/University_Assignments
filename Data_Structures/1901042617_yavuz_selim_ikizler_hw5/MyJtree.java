import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Stack;



public class MyJtree{

private DefaultMutableTreeNode root;
private int step;
private JFrame frame;
    public MyJtree(String file_name){
        step=0;
        root = new DefaultMutableTreeNode("Root");
        String[][] data = new String[0][];
        int numRows = 0;
        // Try to read file and populate 2D dynamic array
        try {
            File file = new File(file_name);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] splitLine = line.split(";");
                data = Arrays.copyOf(data, numRows + 1);
                data[numRows] = splitLine;
                numRows++;
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        // Print the 2D dynamic array
        for (int i = 0; i < data.length; i++) {
            for(int j=0;j<data[i].length;j++){

                System.out.print(data[i][j]+ " ");
            }
            System.out.println("");
        }

        boolean add_node;
        // Loop through each row in the 2D array and add nodes to the tree
        for(int i=0;i<data.length;i++){

            DefaultMutableTreeNode parent=root;

            for(int j=0;j<data[i].length;j++){
              add_node=true;
              // Check if the parent already has a child with the current value
                for(int k=0;k<parent.getChildCount();k++){

                    if(parent.getChildAt(k).toString().equals(data[i][j].toString())){
                        // If a child with the current value already exists, set it as the new parent
                        parent = (DefaultMutableTreeNode)parent.getChildAt(k);
                        add_node=false;
                        break;
                    }

                }
                // If a child with the current value does not exist, create a new child node and add it to the parent
                if(add_node){
                    DefaultMutableTreeNode child= new DefaultMutableTreeNode(data[i][j].toString());
                    parent.add(child);
                    parent=child;
                }
                
            }



        }


    }



    public void visualize(){
        // Create a new JTree using the root node of the tree
        JTree tree = new JTree(root);
        // Create a scroll pane to hold the JTree
        JScrollPane scrollPane = new JScrollPane(tree);
        
        // Create a new JFrame to display the tree viewer
        frame = new JFrame("Tree Viewer");
        // Set the default close operation to exit the program when the frame is closed
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Add the scroll pane containing the JTree to the frame
        frame.add(scrollPane);
        // Pack the frame to fit the size of its contents
        frame.pack();
        // Set the frame to be visible
        frame.setVisible(true);
    }

    public void BFS_search(String search_element){
        // Set the step number to 1 and create a new queue for the breadth-first search
        int step_num=1;
        Queue <DefaultMutableTreeNode> search_queue = new LinkedList<>();
        
        // Set the parent node to be the root node and add it to the search queue
        DefaultMutableTreeNode parent = root;
        search_queue.add(parent);
        boolean found = false;
        // While the search queue is not empty and the target element has not been found
        while(!search_queue.isEmpty() && found != true){
            // Get the head of the search queue and compare it to the target element
            DefaultMutableTreeNode head_queue = search_queue.poll();
            if(head_queue.toString().equals(search_element)){
                found = true;
                // If the target element is found, print the step number and the element with "Found"
                System.out.println("Step " + step_num + " -> " + head_queue.toString() + " (Found)");
            }else{
                // If the target element is not found, print the step number and the element
                System.out.println("Step " + step_num + " -> " + head_queue.toString());
            }
            // Increment the step number and add all the children of the current node to the search queue
            step_num++;
            for(int i=0; i < head_queue.getChildCount(); i++){
                search_queue.add((DefaultMutableTreeNode)head_queue.getChildAt(i));
            }
        }
        // If the target element is not found, print "Not found"
        if(!found){
            System.out.println("Not found");
        }
    }


    public void DFS_search(String search_element){

        // Initialize step counter and print initial root node
        step=1;
        System.out.println("Step "+step+"-> "+root.toString());
    
        // Check if the search element is found in the tree
        if( DFS_supporter(root,search_element)){
            System.out.println("found");
        }
        else{
            System.out.println("not found");
        }
    
    }
    
    // Helper method for DFS search
    private boolean DFS_supporter(DefaultMutableTreeNode parent, String search_element){
    
        // Base case: parent has no children, return false
        if(parent.getChildCount()==0){
            return false;
        }
    
        // Iterate through children from right to left
        for(int i=parent.getChildCount()-1;i>=0;i--){
    
            // Increment step counter and check if current child matches search element
            step++;
            if(parent.getChildAt(i).toString().equals(search_element)){
                System.out.println("Step "+step+"-> "+parent.getChildAt(i).toString());
                return true;
            }
            else {
                // Print current child and recursively call DFS_supporter on it
                System.out.println("Step "+step+"-> "+parent.getChildAt(i).toString());
                if(DFS_supporter((DefaultMutableTreeNode)parent.getChildAt(i), search_element)){
                    return true;
                }
            }
        }
    
        // Search element not found in this subtree, return false
        return false;
    }

       // Depth First Search traversal and search function
public void DFS_traversal_search(String search_element){

    // Initialize step counter
    step=0;

    // Call DFS_traversal_search_supporter function with root node and search element
    if( DFS_traversal_search_supporter(root,search_element)){
        System.out.println("found");
    }
    else{
        System.out.println("not found");
    }
}

// Helper function for DFS traversal and search
private boolean DFS_traversal_search_supporter(DefaultMutableTreeNode parent, String search_element){

    // If node has no children, check if it matches search element
    if(parent.getChildCount()==0){
        // Increment step counter and print current node
        step++;
        System.out.println("Step "+step+"-> "+parent.toString());

        // Check if node matches search element and return true if it does
        if(parent.toString().equals(search_element)){
            return true;
        }
        
        // Return false if node has no children and does not match search element
        return false;
    }

    // If node has children, recurse on each child
    for(int i=0;i<parent.getChildCount();i++){
        if(DFS_traversal_search_supporter((DefaultMutableTreeNode)parent.getChildAt(i), search_element)){
            return true;
        }
        /* 
            if(parent.getChildAt(i).toString().equals(search_element)){
                System.out.println("Step "+step+"-> "+parent.getChildAt(i).toString());
                return true;
            }
        */
    }

    // Increment step counter and print current node if it is not the root node
    step++;
    if(!parent.toString().equals("Root")){
        System.out.println("Step "+step+"-> "+parent.toString());
    }
   
    // Check if node matches search element and return true if it does
    if(parent.toString().equals(search_element)){
        return true;
    }

    // Return false if node has children but none of them match search element
    return false;
} 
    // This method converts a comma-separated string into a queue of strings.
// Each string element is trimmed before being added to the queue.
        private  Queue<String> stringToQueue(String s) {
            Queue<String> q = new LinkedList<>();
           // q.add("Root");
            for (String element : s.split(",")) {
                q.offer(element.trim());
            }
            return q;
        }
        // This method checks if the provided input string is a valid integer.
        private boolean isInteger(String input) {
            if (input == null || input.isEmpty()) {
                return false;
            }
            int i = 0;
            if (input.charAt(0) == '-') {
                if (input.length() == 1) {
                    return false;
                }
                i = 1;
            }
            for (; i < input.length(); i++) {
                char c = input.charAt(i);
                if (c < '0' || c > '9') {
                    return false;
                }
            }
            return true;
        }
        public void move_node(String node_string,String destination){
            // Check if the destination is a valid year
            if(!isInteger(destination)){
                System.out.println("The destination folder must be a a year Ex: (2021,2023,2025)");
                return;
            }else{
                // Convert the node string to a queue
                Queue<String> node_queu = stringToQueue(node_string);
            DefaultMutableTreeNode search_node=root;
            DefaultMutableTreeNode temp=new DefaultMutableTreeNode("Empty");
            DefaultMutableTreeNode remove_node=new DefaultMutableTreeNode("Empty");
            DefaultMutableTreeNode destination_node=new DefaultMutableTreeNode("Empty");
            Queue<String> destQueue = new LinkedList<>();
            Queue<String> print_queu=new LinkedList<>();
            boolean node_exist=true;
            boolean node_exist2=false;
            boolean is_override=false;
            String tail_element;
            // Copy the elements from the source queue to the destination queue
            destQueue.addAll(node_queu);
            print_queu.addAll(node_queu);
            // Check if the node to be moved has at least two layers
            if(node_queu.size()<2){
                System.out.println("The node to be moved should have at least two layers.EX(2023,CSE321)");
            }else{
                // Search for the destination node and create it if it doesn't exist
                for(int i=0;i<search_node.getChildCount();i++){
                    if(search_node.getChildAt(i).toString().equals(destination)){

                        node_exist2=true;
                        destination_node= (DefaultMutableTreeNode)search_node.getChildAt(i);
                    }
                }
                if(!node_exist2){
                    
                     
                     destination_node=new DefaultMutableTreeNode(destination);
                     search_node.add(destination_node);
                 }
                destQueue.poll();
                
                boolean exit_flag=true;
                int child_index=0;
               
                while(destQueue.size()>1 ){
                    String overried_str=destQueue.poll();
                    exit_flag=false;
                    
                    for(int i=0;i<destination_node.getChildCount();i++){

                        if(destination_node.getChildAt(i).toString().equals(overried_str)){
                            exit_flag=true;
                            child_index=i;
                        }
                    }
                    if(exit_flag){
                        destination_node= (DefaultMutableTreeNode)destination_node.getChildAt(child_index);
                        
                    }
                    else{
                        
                        DefaultMutableTreeNode new_node=new DefaultMutableTreeNode(overried_str);
                        destination_node.add(new_node);
                        destination_node=new_node;
                        
                    }
                }
                 // Check if the node to be moved exists in the tree
                for(int k=0;k<destination_node.getChildCount();k++){
                    if(destination_node.getChildAt(k).toString().equals(destQueue.peek())){
                        is_override=true;
                    }
                }
                // Traverse the node path and remove the node if it exists
                while(!node_queu.isEmpty() && node_exist!=false){
                    
                    node_exist=false;
                    int numberofmove=0;
                    String head_node=node_queu.poll();
                    DefaultMutableTreeNode parent=root;
                  //  System.out.println(search_node.toString());
                    for(int i=0;i<search_node.getChildCount();i++){
                        
                        if(search_node.getChildAt(i).toString().equals(head_node)){
                            
                            node_exist=true;
                            if(node_queu.size()==0){
                               
                                remove_node= (DefaultMutableTreeNode)search_node.getChildAt(i);
                                search_node.remove(remove_node);
                            }
                            else{
                                temp= (DefaultMutableTreeNode)search_node.getChildAt(i);
                            }
                            
                            
                        }
                    }
                    if(node_exist==true){
                        
                        search_node=temp;
                        numberofmove++;
                        
                    }
                   
                }
                 // If the node queue is not empty or it is empty but the last searched node does not exist in the tree
                if(!(node_queu.size()==0) || (node_queu.size()==0 &&  node_exist==false)){
                   // Print the original node path that was not found in the tree
                    if(!print_queu.isEmpty()){
                        System.out.print(print_queu.poll());
                        while(!print_queu.isEmpty()){

                            System.out.print("->");
                            System.out.print(print_queu.poll());
                        }
                        System.out.println(" it does not exist in the tree");
                    }
                    
                }
                else if (is_override){
                    // If the last node of the node queue already exists in the destination folder, print a message that it has been overwritten
                    if(!print_queu.isEmpty()){
                        System.out.print(print_queu.poll());
                        while(!print_queu.isEmpty()){

                            System.out.print("->");
                            System.out.print(print_queu.poll());
                        }
                        System.out.println(" has been overwritten");
                    }
                }
                else if(node_queu.isEmpty()){
                    // If all nodes in the node queue have been found and removed from the original folder, add the removed node to the destination folder and update the visualization
                   
                    destination_node.add(remove_node);
                    frame.dispose();
                    visualize();
                }
                

                
            }
            }
        
            
            


        }
        



}









