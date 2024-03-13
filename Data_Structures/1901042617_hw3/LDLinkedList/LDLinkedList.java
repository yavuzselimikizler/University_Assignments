import java.util.*;

// A node class that stores an element and a reference to the next node
class Node<E> {
  E element;
  Node<E> next;
  boolean mark; // holds marked value.
  // Constructor
  public Node(E element) {
    this.element = element;
    this.next = null;
    mark=false;
  }
}

// A linked list class that implements the List interface and extends the AbstractList
public class LDLinkedList<E> extends AbstractList<E> implements List<E> {
  // Instance variables
  private Node<E> head; // The first node of the list
  private Node<E> tail; // The last node of the list
  private int size; // The number of elements in the list
  private int del_count;
  // Constructor
  public LDLinkedList() {
    head = null;
    tail = null;
    size = 0;
    del_count=0; //if its 1 the index and marked node will be delete pysically if its 0 index will be marked.
  }

  // Returns the number of elements in the list
  @Override
  public int size() {
    return size;
  }

  // Returns true if the list is empty, false otherwise
  @Override
  public boolean isEmpty() {
    return size == 0;
  }

  // Returns the element at the specified position in the list
  @Override
  public E get(int index) {
    // Check if the index is valid
    if (index < 0 || index >= size) {
      throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
    }
    // Traverse the list to find the node at the index
    Node<E> current = head;
    
    for (int i = 0; i < index; i++) {
      if(current.mark==true){
        current=current.next;
      }
      current = current.next;
      if(current.mark==true){
        current=current.next;
      }
      
      
    }
    if(index==0 && head.mark==true){
      current=current.next;
    }
    /* 
    if(current.mark==true){
        return -1;
    }
    */
    // Return the element of the node
    return current.element;
  }

  // Replaces the element at the specified position in the list with the specified element
  @Override
  public E set(int index, E element) {
    // Check if the index is valid
    if (index < 0 || index >= size) {
      throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
    }
    // Traverse the list to find the node at the index
    Node<E> current = head;
    for (int i = 0; i < index; i++) {
      if(current.mark==true){
        current=current.next;
      }
      current = current.next;
      if(current.mark==true){
        current=current.next;
      }
      
      
    }
    if(index==0 && head.mark==true){
      current=current.next;
    }
    // Store the old element of the node
    E oldElement = current.element;
    // Replace the element of the node with the new element
    current.element = element;
    // Return the old element
    return oldElement;
  }

  // Inserts the specified element at the specified position in the list
  @Override
  public void add(int index, E element) {
    // Check if the index is valid
    if (index < 0 || index > size) {
      throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
    }
    // Create a new node with the element
    Node<E> newNode = new Node<>(element);
    // If the list is empty, make the new node as the head and tail of the list
    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    }
    // If the index is zero, insert the new node at the beginning of the list
    else if (index == 0) {
      newNode.next = head;
      head = newNode;
    }
    // If the index is equal to the size, insert the new node at the end of the list
    else if (index == size) {
      tail.next = newNode;
      tail = newNode;
    }
    // Otherwise, insert the new node in between two existing nodes
    else {
      // Traverse the list to find the node before the index
      Node<E> previous = head;
      for (int i = 0; i < index - 1; i++) {
        previous = previous.next;
      }
      // Link the new node with its next and previous nodes
      newNode.next = previous.next;
      previous.next = newNode;
    }
    // Increment the size of the list
    size++;

    }
    @Override
    public boolean add(E element){ // add the end of the list

        Node<E> newNode = new Node<>(element);
        if (isEmpty()) { //if its empty assign to head.
            
            head = newNode;
            tail = newNode;

          }
        else{ // else to tail.

            tail.next = newNode;
            tail = newNode;

        }
        size++;

        return true;
          
        
    } 

    @Override
    public E remove(int index){
        E returned=head.element;
        //error checking.
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
          }
        
        else if (isEmpty()) {
            
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
            
        }
        else if(del_count==0){ //only mark
            if(index==0){ //if the index on head node.

                head.mark=true;
                del_count=1; //change del_count to mod 1.
                
                returned=head.element;
               // head=head.next;
                size--; //decrease size.
            }
            else if(index==size){ // if the index on tail node.

                tail.mark=true;
                del_count=1;
                Node<E> prev=head;
                    for(int i=0;i<index-1;i++){
                        prev=prev.next;

                        
                    }
                returned=tail.element;
               // tail=prev;
                size--;
            }
            else{//somewhere else.

              Node<E> current = head;
                for(int i=0;i<index;i++){
                    current=current.next;
                }
                current.mark=true;
                returned=current.element;
                del_count=1;
                size--;
            }
            
        }
        else{
          //if the del_count mod 1 remove index node first the marked node.
                boolean get_marked=false;

                
                if(index==0 && head.mark!=true){//head 
                    head=head.next;
                    returned=head.element;
                    size--;
                }
                else if(index==size){//tail

                  Node<E> prev=head;
                    for(int i=0;i<index-1;i++){
                        prev=prev.next;

                        if(prev.mark==true){
                          
                          prev=prev.next;

                        }
                    }

                    prev.next=tail.next;
                    tail=prev;
                    size--;
                    
                }
                else{

                    Node<E> prev=head;
                    for(int i=0;i<index-1;i++){
                      
                        if(prev.mark==true){
                          prev=prev.next;
                        }
                        prev=prev.next;
                    }
                    if(index==1 && prev.next.mark==true){
                      prev=prev.next;
                    }
                    
                    Node<E> current=prev.next;
                    
                    prev.next=current.next;
                    returned=current.element;
                    current=null;
                    size--;
                }
                
                
                //find and remove marked node.
                
                    
                    //current2=current2.next;
                    Node<E> current2=head;
                      Node<E> prev2=head;
                    if(head.mark==true){

                      head=head.next;
                      current2=null;
                    }
                    else if(tail.mark==true){

                      for(int i=0;i<size;i++){
                        prev2=prev2.next;
                      }
                      prev2.next=tail.next;
                      tail=prev2;
                    }
                    else {

                      

                      while(!get_marked && current2.next!=null){
    
                        current2=current2.next;
                        if(current2.mark==true){
                            prev2.next=current2.next;
                            get_marked=true;
                            current2=null;
                        }
                        prev2=prev2.next;
    
                    }
                    }
                    
               
                
               
                    //set del_count mod again 0.
                del_count=0;
           

            
            

        }

        return returned;
    }
}