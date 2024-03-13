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




public class Main{


    public static void main(String [] args){

      // Create a new MyJtree object with file "a.txt" and visualize it
MyJtree tree1 = new MyJtree("a.txt");
tree1.visualize();

// Create a scanner to read user input
Scanner scanner = new Scanner(System.in);

// Loop indefinitely until user chooses to exit
while (true) {
    // Display options to the user
    System.out.println("Please select an option:");
    System.out.println("1. Option 1 BFS");
    System.out.println("2. Option 2 DFS");
    System.out.println("3. Option 3 DFS Traversal");
    System.out.println("4. Move Node");
    System.out.println("5. Exit");
    System.out.print("Enter your choice: ");
    
    // Read user's choice
    int choice = scanner.nextInt();
    
    // Based on the user's choice, perform the appropriate action
    switch (choice) {
        case 1:
            // If user selects option 1, perform BFS search on the tree
            System.out.print("Enter a node: ");
            String input1 = scanner.next();
            tree1.BFS_search(input1);
            break;
        case 2:
            // If user selects option 2, perform DFS search on the tree
            System.out.print("Enter a node: ");
            String input2 = scanner.next();
            tree1.DFS_search(input2);
            break;
        case 3:
            // If user selects option 3,  perform DFS traversal search on the tree
            System.out.print("Enter a node: ");
            String input3 = scanner.next();
            tree1.DFS_traversal_search(input3);
            break;
        case 4:
            // If user selects option 4,ask the user the node and destination year.
            System.out.print("Enter a node to remove EX: (2023,CSE321,LECTURE1): "); 
            String input4 = scanner.next();
            System.out.print("Enter a destination year: ");
            String input5=scanner.next();
            tree1.move_node(input4,input5);
            break;
        case 5:
            // If user selects option 5, exit the program
            System.out.println("Exiting...");
            System.exit(0);
        default:
            // If user selects an invalid option, display an error message and loop again
            System.out.println("Invalid choice. Please try again.");
    }
}
    }
}
