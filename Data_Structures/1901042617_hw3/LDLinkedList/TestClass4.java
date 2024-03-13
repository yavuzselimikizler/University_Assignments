
import java.util.*;




public class TestClass4{


    public static void main(String [] args){

        LDLinkedList<Account>  account_list= new LDLinkedList<Account>();
        System.out.println("         ... Creating accounts...      ");
        Account user1= new Account(12745,"gizemsüngü","Istanbul","21.03.1993");
        Account user2= new Account(12395,"sibelgülmez","izmir","31.05.1992");
        Account user3= new Account(12348,"gökhankaya","Ankara","01.01.1985");
        Account user4=new Account(16257,"user4","place1","31.03.2023");
        Account user5=new Account(13526,"user5","place2","01.04.2023");
        Account user6=new Account(19907,"user6","place3","02.04.2023");
        Account user7=new Account(35271,"user7","place4","03.04.2023");
        Account user8=new Account(13728,"user8","place5","04.04.2023");
        Account user9=new Account(18463,"user9","place6","05.04.2023");
        Account user10=new Account(17381,"user10","place7","06.04.2023");
        account_list.add(user1);
        account_list.add(user2);
        account_list.add(user3);
        account_list.add(user4);
        account_list.add(user5);
        account_list.add(user6);
        account_list.add(user7);
        account_list.add(user8);
        account_list.add(user9);
        account_list.add(user10);

        
        int account_size=3;
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

        System.out.println("\n\n\n         ..................add post follow tests............\n\n\n");
        System.out.println("\n         ... user4 logging in...\n");
        user4.login();

        System.out.println("\n         ... user4 sharing 3 post...\n");

        Post post3 = new Post(3,"user4 sharing a post");
        Post post4 = new Post(4,"user4 sharing a second post");
        Post post5 = new Post(5,"user4 sharing a third post");

        user4.addPost(post3);
        user4.addPost(post4);
        user4.addPost(post5);

        System.out.println("\n         ... user4 following gizemsüngü sibelgülmez gökhankaya user5 user6...\n");
        user4.follow(user1);
        user4.follow(user2);
        user4.follow(user3);
        user4.follow(user5);
        user4.follow(user6);

        System.out.println("\n         ... user4 logout...\n");
        user4.logout();

        System.out.println("\n         ... user5 logging in...\n");
        user5.login();

        System.out.println("\n         ... user5 sharing 2 post...\n");

        Post post6 = new Post(6,"user5 sharing a post");
        Post post7 = new Post(7,"user5 sharing a second post");
     

        user5.addPost(post6);
        user5.addPost(post7);
        

        System.out.println("\n         ... user5 following gizemsüngü sibelgülmez gökhankaya user7 user8...\n");
        user5.follow(user1);
        user5.follow(user2);
        user5.follow(user3);
        user5.follow(user7);
        user5.follow(user8);

        System.out.println("\n         ... user5 logout...\n");
        user5.logout();

        System.out.println("\n         ... user6 logging in...\n");
        user6.login();

        System.out.println("\n         ... user6 sharing 2 post...\n");

        Post post8 = new Post(8,"user5 sharing a post");
        Post post9 = new Post(9,"user5 sharing a second post");
     

        user6.addPost(post8);
        user6.addPost(post9);
        

        System.out.println("\n         ... user6 following gizemsüngü sibelgülmez gökhankaya user9 user10...\n");
        user6.follow(user1);
        user6.follow(user2);
        user6.follow(user3);
        user6.follow(user9);
        user6.follow(user10);

        System.out.println("\n         ... user6 logout...\n");
        user6.logout();


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

        System.out.println("         ... trying to like the same post of sibelgulmez again...\n");
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

        System.out.println("\n         ... gökhankaya try to view user4 posts without viewing his/her profile...\n");
        user3.view_posts(user4);
        
        System.out.println("\n         ... Logging out from account 'gokhankaya'..\n");
        user3.logout();

        System.out.println("\n         ... Logging in user7 ..\n");
        user7.login();

        System.out.println("\n\n\n         ..................message tests.................\n\n\n");

        Message newmessage2= new Message(8,35271,12745,"second homework is too easy!");
        Message newmessag3= new Message(9,35273,12745,"second homework is too easy!");
        Message newmessage4= new Message(10,35271,10545,"second homework is too easy!");

        System.out.println("\n         ... try to send message with wrong sender id ..\n");
        user7.addMessage(newmessag3, account_list);
        System.out.println("\n         ... try to send message with wrong sender id ..\n");
        user7.addMessage(newmessage4, account_list);

        System.out.println("\n         ... follow gizemsüngü..\n");
        user7.follow(user1);

        System.out.println("         ... try to send message to gizemsüngü..\n");
        user7.addMessage(newmessage2, account_list);
        

        System.out.println("         ...user7  Viewing sibelgulmez's profile...");
        user7.view_profile(user2);
        System.out.println("");

        System.out.println("         ...user7  Viewing sibelgulmez'posts...");
        user7.view_posts(user2);
        System.out.println("");

        Like like4=new Like(10,user7,1);
        Comment comment3= new Comment(11,1,user7,"me too"); 
        
        System.out.println("         ... user7 liking sibelgülmezs first post...\n");
        post1.addLike(like4);
        
        System.out.println("         ... user7 Adding a comment on the first post of sibelgulmez...\n");
        post1.addComment(comment3);
        Like like6=new Like(10,user7,2);
        System.out.println("         ... user7 liking sibelgülmezs second post...\n");
        post2.addLike(like6);
        //user3.comment_post(comment1);

        System.out.println("         ... user7 logging out...\n");
        user7.logout();

        System.out.println("         ... user8 logging in...\n");
        user8.login();

        System.out.println("\n         ... follow gizemsüngü..\n");
        user8.follow(user1);

        Message newmessage5= new Message(10,13728,12745,"second homework is too easy!");
        System.out.println("         ... try to send message to gizemsüngü..\n");
        user8.addMessage(newmessage5, account_list);
        

        System.out.println("\n         ...user8  Viewing sibelgulmez's profile...");
        user8.view_profile(user2);
        System.out.println("");

        System.out.println("\n         ...user8  Viewing sibelgulmez'posts...");
        user8.view_posts(user2);
        System.out.println("");

        Like like5=new Like(10,user8,1);
        Comment comment4= new Comment(11,1,user8,"me too"); 
        
        System.out.println("\n         ... user8 liking sibelgülmezs first post...\n");
        post1.addLike(like5);
        
        System.out.println("\n         ... user8 Adding a comment on the first post of sibelgulmez...\n");
        post1.addComment(comment4);

        System.out.println("\n         ... user8 logging out...\n");
        user8.logout();

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

        System.out.println("\n         ...logging out gizemsüngü...\n");
        user1.logout();

        System.out.println("\n         ...logging in sibelgülmez...\n");
        user2.login();

        System.out.println("\n         ...view profile of gökhankaya...\n");
        user2.view_profile(user3);

        System.out.println("\n         ...unfollow gökhankaya...\n");
        user2.unfollow(user3);

        System.out.println("\n         ...try to unfollow gökhankaya again...\n");
        user2.unfollow(user3);

        System.out.println("\n         ...view profile of gökhankaya again...\n");
        user2.view_profile(user3);

        System.out.println("\n         ...logging out sibelgülmez...\n");
        user2.logout();

        System.out.println("\n         ...logging in gökhankaya...\n");
        user3.login();

        System.out.println("\n         ...view profile of sibelgülmez...\n");
        user3.view_profile(user2);

        System.out.println("\n         ...show actions of gökhankaya...\n");
        user3.show_actions();

        System.out.println("\n         ...view post interactions of sibelgülmez...\n");
        user3.view_post_interactions(user2);

        System.out.println("\n\n\n         .......................unlike uncomment test.................\n\n\n");

        System.out.println("\n         ...unlike the post of sibelgülmez...\n");
        
        post1.unlike(like1);

        System.out.println("\n         ...try to unlike the post of sibelgülmez again...\n");
        post1.unlike(like1);

        System.out.println("\n         ...uncomment the post of sibelgülmez...\n");
        post1.unComment(comment1);

        System.out.println("\n         ...try to uncomment the post of sibelgülmez again...\n");
        post1.unComment(comment1);

        System.out.println("\n         ...view post interactions of sibelgülmez again...\n");
        user3.view_post_interactions(user2);

        

        System.out.println("\n         ...show actions of gökhankaya...\n");
        user3.show_actions();

        

        System.out.println("\n         ...user4 logging in...\n");

        System.out.println("\n\n\n         ....................unfollow test..............\n\n\n");
        user3.view_profile(user4);
        System.out.println("\n         ...logout from gökhankaya...\n");
        user3.logout();
        user4.login();
        System.out.println("\n         ...user4 unfollow gizemsüngü,sibelgülmez,gökhankaya,user5...\n");
        user4.unfollow(user1);
        user4.unfollow(user2);
        user4.unfollow(user3);
        user4.unfollow(user5);
        
        System.out.println("\n         ...user4 logging out...\n");
        user4.logout();
        
        System.out.println("\n         ...logging in gizemsüngü...\n");
        user1.login();

        System.out.println("\n         ...viewing profile of user4...\n");
        user1.view_profile(user4);

        System.out.println("\n         ...blocking  sibel gülmez...\n");
        user1.blockAccount(user2);

        System.out.println("\n         ...show actions gizemsüngü...\n");
        user1.show_actions();

        System.out.println("\n         ...logout gizemsüngü...\n");
        user1.logout();

        System.out.println("\n         ...loging sibelgülmez...\n");
        user2.login();

        System.out.println("\n         ...viewprofile gizemsüngü...\n");
        user2.view_profile(user1);

        System.out.println("\n         ...logout siblegülmez...\n");
        user2.logout();

        System.out.println("\n         ...login gizemsüngü...\n");
        user1.login();

        System.out.println("\n             ...unblocking sibel gülmez...\n");
        user1.unblock(user2);

        System.out.println("\n             ...show actions of gizem süngü...\n");
        user1.show_actions();

        System.out.println("\n             ...gizemsüngü logging out...\n");
        user1.logout();

        System.out.println("\n             ...sibel gülmez logging in...\n");
        user2.login();
        System.out.println("\n             ...view gizemsüngüs profile...\n");
        user2.view_profile(user1);
        System.out.println("\n             ...logging out...\n");
        user2.logout();
        System.out.println("\n\n\n             ...............unlike test again .....................\n\n\n");

        System.out.println("\n             ...user8 logging in...\n");
        user8.login();

        System.out.println("\n             ...user8 view profile of sibel gülmez...\n");
        user8.view_profile(user2);

        System.out.println("\n             ...view post interactions of sibelgülmez...\n");
        user8.view_post_interactions(user2);

        System.out.println("\n             ...unlike the first post of sibelgülmez...\n");
        post1.unlike(like5);

        System.out.println("\n             ...view post interactions of sibelgülmez...\n");
        user8.view_post_interactions(user2);

        System.out.println("\n             ...logging out...\n");
        user8.logout();

        System.out.println("\n             ...try to unlike without logging in...\n");
        post1.unlike(like2);

        System.out.println("\n             ...gizemsüngü logging in...\n");
        user1.login();
        System.out.println("\n             ...unlike the first post of sibelgülmez...\n");
        post1.unlike(like2);

        System.out.println("\n             ...try to view sibelgülmez...\n");
        user1.view_profile(user2);

        System.out.println("\n             ...try to view sibelgülmzs post interactions...\n");
        user1.view_post_interactions(user2);

        System.out.println("\n             ...sibelgülez follows gizemsüngü gökhankaya and user6...\n");
        user1.follow(user2);

        user1.follow(user3);

        user1.follow(user6);

        System.out.println("\n             ...logging out...\n");
        user1.logout();

        System.out.println("\n             ...user7 logging in...\n");
        user7.login();

        System.out.println("\n             ...unlike sibelgülmezs first post...\n");
        post1.unlike(like4);

        System.out.println("\n             ...try to view sibelgülmezs profile...\n");
        user7.view_profile(user2);

        System.out.println("\n             ...try to view sibelgülmezs post interactions...\n");
        user7.view_post_interactions(user2);

        System.out.println("\n             ...add like to first post...\n");
        post1.addLike(like4);

        System.out.println("\n             ...try to view post interactions...\n");
        user7.view_post_interactions(user2);

        System.out.println("\n             ...user7 logging out...\n");
        user7.view_profile(user1);

        System.out.println("\n             ...user7 logging out...\n");
        user7.logout();

       
        System.out.println("\n\n\n         ....................block unblock test test..............\n\n\n");

        System.out.println("\n             ...gizemsüngü logging in ...\n");
        user1.login();

        System.out.println("\n             ...gizemsüngü blocks every account ...\n");
        user1.blockAccount(user9);
       
        user1.blockAccount(user10);
       
        user1.blockAccount(user6);

       
        user1.blockAccount(user2);
        
        user1.blockAccount(user3);
        
        user1.blockAccount(user4);


        user1.blockAccount(user5);

        user1.blockAccount(user7);

        user1.blockAccount(user8);

        System.out.println("\n             ...user9 user10 user6 try to vire gizemsüngüs profile when they are blocked ...\n");
        user1.logout();

        user9.login();

        user9.view_profile(user1);

        user9.logout();

        user10.login();

        user10.view_profile(user1);

        user10.logout();

        user6.login();

        user6.view_profile(user1);

        user6.logout();

        user1.login();

        user1.unblock(user9);

        user1.unblock(user10);

        user1.unblock(user6);

        user1.logout();

        user6.login();

        System.out.println("\n             ...user9 user10 user6 try to view gizemsüngü profile after unblocking ...\n");
        user6.view_profile(user1);

        user6.logout();

        user10.login();

        user10.view_profile(user1);

        user10.logout();

        user9.login();

        user9.view_profile(user1);

        user9.logout();

        System.out.println("\n\n\n         ....................show actions test..............\n\n\n");

        System.out.println("\n         gizemsüngü       \n");
        user1.login();

        user1.show_actions();

        user1.logout();

        System.out.println("\n         sibelgülmez       \n");
        user1.login();

        user1.show_actions();

        user1.logout();

        System.out.println("\n         gökhankaya       \n");
        user1.login();

        user1.show_actions();

        user1.logout();

        System.out.println("\n         user7       \n");
        user7.login();

        user7.show_actions();

        user7.logout();

        System.out.println("\n         user8       \n");
        user8.login();

        user8.show_actions();

        user8.logout();


        



        






        

    








        


        



    }
}
