import java.util.Stack;

public class Password1{

    private String mypassword; // holds string mypassword.
    public  Password1(String mypassword){
        this.mypassword=mypassword;
    }

    public boolean check_correct(){

        int bracket_counter=0; //counts brackest.
        int letter_counter=0; // counts letters.
        if(mypassword.length()<8){ // if the length lesser than 8 return false and print message.

            System.out.println("The password1 is invalid. It should have at least 8 characters");
            return false;
        }
        for(int i=0;i<mypassword.length();i++){ // search all the element of the string and counts bracket and letter numbers.

            if(!((mypassword.charAt(i)>=65 && mypassword.charAt(i) <=90) || 
            (mypassword.charAt(i)>=97 && mypassword.charAt(i) <=122) || 
            mypassword.charAt(i)=='(' || mypassword.charAt(i)=='{' || 
            mypassword.charAt(i)=='[' || 
            mypassword.charAt(i)==')' || 
            mypassword.charAt(i)=='}' || 
            mypassword.charAt(i)==']')){

                System.out.println("the password is invalid. It should have only letters or brackets");

                return false;

            }

            if(mypassword.charAt(i)=='(' || mypassword.charAt(i)=='{' || 
            mypassword.charAt(i)=='[' || 
            mypassword.charAt(i)==')' || 
            mypassword.charAt(i)=='}' || 
            mypassword.charAt(i)==']'){
                bracket_counter= bracket_counter+1;
            }
            else{
                letter_counter= letter_counter+1;
            }
        }
        if(letter_counter<1){ // if letters less than 1. return false

            System.out.println("the password is invalid. It should have at least 1 letter");
            return false;
        }
        if(bracket_counter<2){//if the brackets less than 2. return false.

            System.out.println("the password is invalid. It should have at least 2 brackets");
            return false;
        }

        return true; //otherwise return true.
    }
    public String get_password(){
        return mypassword;
    }

}