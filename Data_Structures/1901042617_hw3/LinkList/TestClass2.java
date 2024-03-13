
import java.util.*;




public class TestClass2{


    public static void main(String [] args){

        LinkedList<Account>  account_list= new LinkedList<Account>();
        System.out.println("         ... Creating accounts...      ");
        Account user1= new Account(12745,"gizemsüngü","Istanbul","21.03.1993");
        Account user2= new Account(12395,"sibelgülmez","izmir","10.03.1995");
        Account user3= new Account(12348,"gökhankaya","Ankara","01.01.1985");
        
        account_list.add(user1);
        account_list.add(user2);
        account_list.add(user3);
        int account_size=3;
        System.out.println("");

        System.out.println("         ... Logging into an account (username: sibelgulmez)… ");
        user2.login();
        System.out.println("");

        System.out.println("         ... Sharing two posts…");
        Post post1=new Post(1,"I like Java.");
        Post post2=new Post(2,"Java the coffee...");
        user2.addPost(post1);
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

        System.out.println("\n\n\n\n..................Part2...................\n\n");
        System.out.println("          ... Logging out from account 'gizemsüngü'…");
        user1.logout();
        Post post3= new Post(3,"I am sharing a post");

        System.out.println("\n         ... Trying to share a new post without logging in …\n");
        user1.addPost(post3);

        System.out.println("         ... Logging into an account (username: gizemsüngü)… \n");
        user1.login();

        System.out.println("\n         ... Sharing a post with id (3)   …\n");
        user1.addPost(post3);

        System.out.println("\n         ... when trying to share a new post with same id (3)  \n");
        Post post4= new Post(3,"I am sharing another post");
        user1.addPost(post4);

        System.out.println("\n         ... Sharing a post with id(4)   …\n");
        Post post5 = new Post(4,"I am sharing another post");
        user1.addPost(post5);


        System.out.println("          ... Logging out from account 'gizemsüngü'…\n");
        user1.logout();


        
        System.out.println("         ... Logging into an account (username: sibelgülmez)… \n");
        user2.login();

        System.out.println("         ... Viewing gizemsüngü's profile...\n");
        user2.view_profile(user1);

        System.out.println("\n         ... Trying to add like with wrong post id...\n");
        Like like4= new Like(12, user1, 6);
        post5.addLike(like4);

        System.out.println("\n         ... Liking gizemsüngü's posts...\n");
        Like like5= new Like(13, user1, 4);
        post5.addLike(like5);

        System.out.println("\n          ... Logging out from account 'sibelgülmez'…\n");
        user2.logout();

        System.out.println("         ... Logging into an account (username: gökhankaya)… \n");
        user3.login();

        System.out.println("         ... Viewing gizemsüngü's profile...\n");
        user3.view_profile(user1);

        System.out.println("\n         ... Trying to add comment with wrong post id...\n");
        Comment comment2 = new Comment(8, 3, user1, "nice");
        post5.addComment(comment2);

        System.out.println("\n         ... Adding a comment on a post of gizemsüngü...\n");
        Comment comment3= new Comment(9, 4, user1, "nice");
        post5.addComment(comment3);

        System.out.println("\n       ...Trying to add message with wrong sender id.....");
        Message newmessage2= new Message(11,123,12745,"Hello");
        user3.addMessage(newmessage2, account_list);

        System.out.println("\n       ...Trying to add message with wrong reciever id.....");
        Message newmessage3= new Message(13,12348,127,"Hello");
        user3.addMessage(newmessage3, account_list);

        System.out.println("\n         ... Sending a message to gizemsungu...\n");
        Message newmessage5= new Message(13,12348,12745,"Hello");
        user3.addMessage(newmessage5, account_list);

        System.out.println("         ... Logging into an account (username: gizemsüngü)… \n");
        user1.login();

        System.out.println("         ... Viewing gizemsüngü's profile...\n");
        user1.view_profile(user1);

        System.out.println("         ... Reading the message from “gokhankaya”....\n");
        user1.ViewInbox(account_list);
    }
}
