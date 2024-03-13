
import java.util.Stack;
//import java.io.PrintStream;



public class Main{


    public static void main(String [] args){

        Username user1= new Username("yavuz");
        Password1 password1 = new Password1("{ab[bac]aaba}");
        Password2 password2 = new Password2(21);

        Username user2= new Username("sibelgulmez");
        Password1 password21 = new Password1("[rac()ecar]");
        Password2 password22 = new Password2(74);
        int []denominations={4,17,29};
        int [] denominations2={13,5,19,21};
        
        Username user3= new Username("");
        Password1 password31 = new Password1("[rac()ecar]");
        Password2 password32 = new Password2(74);

        Username user4= new Username("sibel1");
        Password1 password41 = new Password1("[rac()ecar]");
        Password2 password42 = new Password2(74);

        Username user5= new Username("sibel");
        Password1 password51 = new Password1("pass[]");
        Password2 password52 = new Password2(74);

        Username user6= new Username("sibel");
        Password1 password61 = new Password1("abcdabcd");
        Password2 password62 = new Password2(74);

        Username user7= new Username("sibel");
        Password1 password71 = new Password1("[[[[]]]]");
        Password2 password72 = new Password2(74);

        Username user8= new Username("sibel");
        Password1 password81 = new Password1("[no](no)");
        Password2 password82 = new Password2(74);

        Username user9= new Username("sibel");
        Password1 password91 = new Password1("[rac()ecar]]");
        Password2 password92 = new Password2(74);

        Username user10= new Username("sibel");
        Password1 password101 = new Password1("[rac()ecars]");
        Password2 password102 = new Password2(74);

        Username user11= new Username("sibel");
        Password1 password111 = new Password1("[rac()ecar]");
        Password2 password112 = new Password2(5);

        Username user12= new Username("sibel");
        Password1 password121 = new Password1("[rac()ecar]");
        Password2 password122 = new Password2(35);

        Username user13= new Username("yavuz&()");
        Password1 password131 = new Password1("[");
        Password2 password132 = new Password2(30);

        Username user14= new Username("yavuzselim");
        Password1 password141 = new Password1("[rac()ecar]");
        Password2 password142 = new Password2(16);
        Password2 password143 = new Password2(48);
        System.out.println("\n...............user1...............\n");
        System1 system1 = new System1(user1,password1,password2,denominations,3);
        system1.login();
        System.out.println("\n...............user2...............\n");
        system1= new System1(user2,password21,password22,denominations,3);
        system1.login();
        System.out.println("\n...............user3...............\n");
        system1= new System1(user3,password31,password32,denominations,3);
        system1.login();
        System.out.println("\n...............user4...............\n");
        system1= new System1(user4,password41,password42,denominations,3);
        system1.login();
        System.out.println("\n...............user5...............\n");
        system1= new System1(user5,password51,password52,denominations,3);
        system1.login();
        System.out.println("\n...............user6...............\n");
        system1= new System1(user6,password61,password62,denominations,3);
        system1.login();
        System.out.println("\n...............user7...............\n");
        system1= new System1(user7,password71,password72,denominations,3);
        system1.login();
        System.out.println("\n...............user8...............\n");
        system1= new System1(user8,password81,password82,denominations,3);
        system1.login();

        System.out.println("\n...............user9...............\n");
        system1= new System1(user9,password91,password92,denominations,3);
        system1.login();
        System.out.println("\n...............user10...............\n");
        system1= new System1(user10,password101,password102,denominations,3);
        system1.login();
        System.out.println("\n...............user11...............\n");
        system1= new System1(user11,password111,password112,denominations,3);
        system1.login();
        System.out.println("\n...............user12...............\n");
        system1= new System1(user12,password121,password122,denominations,3);
        system1.login();
        System.out.println("\n...............user13...............\n");
        system1=new System1(user13,password131,password132,denominations,3);
        system1.login();
        System.out.println("\n...............user14...............\n");
        system1= new System1(user14,password141,password142,denominations2,4);
        system1.login();
        System.out.println("\n...............user14 with new password2...............\n");
        system1= new System1(user14,password141,password143,denominations2,4);
        system1.login();



        /* 
        password1.check_correct();
        password2.check_correct();
        system1.checkIfValidUsername(user1.get_username());
        system1.containsUserNameSpirit(user1.get_username(), password1.get_password());
        system1.isBalancedPassword(password1.get_password());
        if(system1.isExactDivision(password2.get_password(),denominations , 3)==false){
            System.out.println("The password2 is invalid. It is not compatible with the denominations");
        }
      //  system1.isPalindromePossible(password1.get_password());
       */
    }
}
