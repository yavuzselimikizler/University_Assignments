import java.util.Stack;

public class Password2{


    private int mypassword;
    public Password2(int mypassword){
        this.mypassword=mypassword;
    }

    public boolean check_correct(){

        if(!(mypassword>=10 && mypassword <= 10000)) { //if the integer password 2 not in between 10 and 10000 return false and print message.
            System.out.println("The password2 is invalid. It should be between 10 and 10,000");
            return false;}
        return true;
    }
    public int get_password(){
        return mypassword;
    }
}