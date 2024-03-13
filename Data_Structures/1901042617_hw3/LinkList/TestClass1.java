
import java.util.*;




public class TestClass1{


    public static void main(String [] args){

        LinkedList<Account>  account_list= new LinkedList<Account>();
        System.out.println("         ... Creating accounts...      ");
        Account user1= new Account(12745,"gizemsüngü","Istanbul","21.03.1993");
        Account user2= new Account(12395,"sibelgülmez","izmir","31.05.1992");
        Account user3= new Account(12348,"gökhankaya","Ankara","01.01.1985");
        
        account_list.add(user1);
        account_list.add(user2);
        account_list.add(user3);
        
       // int account_size=3;
        System.out.println("");

        System.out.println("         ... Logging into an account (username: sibelgulmez)… ");
        user2.login();
        System.out.println("");

        System.out.println("         ... Sharing two posts…");
        Post post1=new Post(1,"I like Java.");
        user2.addPost(post1);
        Post post2=new Post(2,"Java the coffee...");
        user2.addPost(post2);
        System.out.println("");
        
        System.out.println("         ... Following gizemsungu and gokhankaya...");
        user2.follow(user1);
        user2.follow(user3);
        System.out.println("");

        System.out.println("         ... Logging out from account 'sibelgulmez'…");
        user2.logout();
        System.out.println("");

        System.out.println("         ... Logging into another account (username: gokhankaya)…");
        user3.login();
        System.out.println("");
        
        System.out.println("         ... Viewing sibelgulmez's profile...");
        user3.view_profile(user2);
        System.out.println("");

        System.out.println("         ... Viewing sibelgulmez'posts...");
        user3.view_posts(user2);
        System.out.println("");

        Like like1=new Like(9,user3,1);
        Comment comment1= new Comment(9,1,user3,"me too"); 
         
        System.out.println("         ... Liking a post of sibelgulmez...\n");
        post1.addLike(like1);
        
        System.out.println("         ... Adding a comment on a post of sibelgulmez...\n");
        post1.addComment(comment1);
        //user3.comment_post(comment1);
        
        System.out.println("         ... Following sibelgulmez and gizemsungu...\n");
        user3.follow(user1);
        user3.follow(user2);

        System.out.println("\n         ... Sending a message to gizemsungu...\n");
        Message newmessage= new Message(7,12348,12745,"This homework is too easy!");
        user3.addMessage(newmessage, account_list);
        
        System.out.println("         ... Logging out from account 'gokhankaya'..\n");
        user3.logout();

        System.out.println("         ... Logging into another account (username: gizemsungu)…\n");
        user1.login();
        
        System.out.println("         ... Checking inbox...\n");
        user1.checkInbox();

        System.out.println("         ... Checking outbox...\n");
        user1.checkOutbox();
         
        System.out.println("\n         ... Viewing inbox...");
        user1.ViewInbox(account_list);
        
        System.out.println("         ... Viewing sibelgulmez's profile...\n");
        user1.view_profile(user2);

        System.out.println("\n         ... Viewing sibelgulmez's posts...\n");
        user1.view_posts(user2);

        System.out.println("\n        ... Viewing sibelgulmez's posts' interactions...\n");
        user1.view_post_interactions(user2);

        System.out.println("\n         ... Liking sibelgulmez's posts...\n");
        Like like2=new Like(10,user1,1);
        post1.addLike(like2);

        
        Like like3=new Like(11,user1,2);
        post2.addLike(like3);

        System.out.println("\n         ...Viewing sibelgulmez's posts' interactions...\n");
        user1.view_post_interactions(user2);
        


    }
}
