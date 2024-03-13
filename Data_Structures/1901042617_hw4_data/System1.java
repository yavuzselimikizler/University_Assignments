
import java.util.Stack;

//import java.lang.System;
public class System1{

    private Username check_username; //username and password objects to be checked.
    private Password1 check_Password1;
    private Password2 check_Password2;
    private int [] denominations;
    private int size;
    public System1(Username username,Password1 password1,Password2 password2,int [] denominations,int size){ // constructure.

        this.check_username=username;
        this.check_Password1=password1;
        this.check_Password2=password2;
        this.denominations=denominations;
        this.size=size;
    }
 private boolean checkIfValidUsername(String username){

    if(username.length()==0){
        System.out.println("The username is invalid. It should have at least 1 character.");
        return false;
    }
    if(username.length()==1){
        if(username.charAt(0)>=65 && username.charAt(0) <=90 || username.charAt(0)>=97 && username.charAt(0) <=122){ //if one character remained and its ascii number between letters interval return true 
            return true;
        }
        else{
            System.out.println("The username is invalid. It should have letters only.");
            return false;
        }
    }

    else{
        if(!(username.charAt(0)>=65 && username.charAt(0) <=90 || username.charAt(0)>=97 && username.charAt(0) <=122)){ // return false otherwise.
            System.out.println("The username is invalid. It should have letters only.");
            return false;
        }
        else{
            String new_str = username.substring(1); // divide the string by removing first character and call it recursively
            return checkIfValidUsername(new_str);
        }
    }

 }
 private boolean containsUserNameSpirit(String username, String password1){

    Stack <Character> newstack = new Stack<Character>();

    for(int i=0;i<username.length(); i++){ //put the username characters to stack.
        newstack.push(username.charAt(i));
    }

    while(newstack.size()!=0){ //search the stack one by one.

        Character element=newstack.pop(); // remove characters from stack and assign it to element variable one by one
        for(int i=0;i<password1.length();i++){

            if(element==password1.charAt(i)){ // compare the variable with the character at the strings index 
                return true;
            }
        }
        
    }
    System.out.println("The password1 is invalid. It should have at least 1 character from the username.");
    return false;
    
 }

 private boolean isBalancedPassword(String password1){

    Stack <Character> newstack = new Stack<Character>();

    
    for(int i=0;i<password1.length(); i++){
        if(password1.charAt(i)=='(' || password1.charAt(i)=='{' || password1.charAt(i)=='['){ // if the string has brackets at that index push it to newstack

            newstack.push(password1.charAt(i));
        }

        if(password1.charAt(i)==')' || password1.charAt(i)=='}' || password1.charAt(i)==']'){
            if(!newstack.isEmpty()){

                if(is_match(newstack.peek(), password1.charAt(i))){ // if the brackets are matching remove the opened bracket from stack.
                    newstack.pop();
                }
                else{//if open brackets and close brackets is not matching return false.
                    System.out.println("The password1 is invalid. It should be balanced.");
                    return false;
                }
            }
            else{ // if close bracet cathced before opene bracet return false.
                System.out.println("The password1 is invalid. It should be balanced.");
                return false;
            }
            
        }
    }

   
    if(newstack.isEmpty()){//if there are no unpaired brackets return true.
        return true;
    }
    System.out.println("The password1 is invalid. It should be balanced.");
     return false;
 }

 private boolean is_match(char a ,char b){ // check closed and opened brackets if they are matching.
    if(a=='(' && b== ')'){
        return true;
    }
    if(a=='{' && b== '}'){
        return true;
    }
    if(a=='[' && b == ']'){
        return true;

      
    }
    return false;  
 }

 private boolean isPalindromePossible(String password1, int index) {

    String new_str = remove_brackets(password1); // remove the brackets of the string.

    if (index == new_str.length() - 1) {
        // Base case: we've reached the end of the array, so check if the current permutation is a palindrome
        return ispalindrome(new_str);
    } else {
        // Recursive case: generate permutations by swapping each character with all the characters that come after it
        for (int i = index; i < new_str.length(); i++) {
            new_str = swap(new_str, index, i);
            if (isPalindromePossible(new_str, index + 1)) {
                return true;
            }
            new_str = swap(new_str, index, i); //give back the swapped values.
        }
    }
    return false;
}

 private String swap(String swapped, int i, int j) {
    char temp = swapped.charAt(i);
    swapped = swapped.substring(0, i) + swapped.charAt(j) + swapped.substring(i + 1);
    swapped = swapped.substring(0, j) + temp + swapped.substring(j + 1);

    return swapped;
}

//to remove brackets from the string.
 private String remove_brackets(String str){

    String new_str="";

    for(int i=0;i<str.length();i++){ // search the string if the characters in that index is not brackets add it to new_str.

        if(!(str.charAt(i) =='{' || str.charAt(i) =='}' ||  str.charAt(i) =='(' || str.charAt(i) ==')' || str.charAt(i) =='[' || str.charAt(i) ==']')){
            new_str+=str.charAt(i);
        }
    }
    return new_str; //return new_str.
 }

 private boolean ispalindrome(String str){
   

    // Check if the string is empty or has only one character
    if (str.length() <= 1) {
        return true;
    }

    // Check if the first and last characters of the string match, and if so, check the rest of the string recursively
    if (str.charAt(0) == str.charAt(str.length() - 1)) {
        String remaining = str.substring(1, str.length() - 1);
        return ispalindrome(remaining);
    } else {
        return false;
    }
 }

// to call the functions.
//call each functions one by one and assign the return value to correct variable.
public void login(){

    boolean correct;
    
    correct = check_Password1.check_correct() && true ;
    correct = check_Password2.check_correct() && correct;
    
    correct = checkIfValidUsername(this.check_username.get_username()) && correct;
    correct = containsUserNameSpirit(this.check_username.get_username(), this.check_Password1.get_password()) && correct;
    correct = isBalancedPassword(this.check_Password1.get_password()) && correct;
        if(!isExactDivision(this.check_Password2.get_password(), denominations, size)){
            System.out.println("The password2 is invalid. It is not compatible with the denominations");
            
            correct=false;
        }
        

        if(!isPalindromePossible(this.check_Password1.get_password(), 0)){
            System.out.println("palindrome is not possible");
            correct=false;
        }

        if(correct){// if all the returns are true print the message.
            System.out.println("The username and passwords are valid. The door is opening, please wait..");
        }

    

}
 boolean isExactDivision(int password2, int [] denominations,int size){

    boolean returned=false;
    if(password2==0){ //base case if 0 is reached that means exact division return true.
        return true;
    }
    if(password2<0){ // base case if 0 value is not reached.
        return false;
    }
    // Recursive case: Subtract each denomination from password2 and check if the remaining amount can be exactly divided.
    for (int i=0;i<size;i++){ 
        // Use the bitwise OR operator to combine the results of each recursive call
       returned = returned | isExactDivision(password2-denominations[i], denominations, size);
    }
    

    return returned;
 }


}
