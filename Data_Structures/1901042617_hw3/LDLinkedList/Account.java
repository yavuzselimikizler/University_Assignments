
import java.util.*;



public class Account{


    //logged or not
    private boolean isOnline;

    //user_informations  
    private int user_id;
    private String user_name;
    private String location;
    private String birth_date;

    //posts array and current_post (represents size of the array)
    protected LDLinkedList<Post>  myPosts ;
    

    protected LDLinkedList<String> actions;

    //the arrays holds following accounts and following number represent the arrays size.
    private LDLinkedList<Account>  following;
    

    private LDLinkedList<Account> followers;
    

    protected LDLinkedList<Account> blocked_accounts;
//holds currently viewing accounts id .
    private Account current_viewing_id;

    //holds inbox messages.
    private LDLinkedList<Message> inbox;
   

    // holds outbox messages.
    private LDLinkedList<Message> outbox;
    

//Account class constructure
    public Account( int user_id, String user_name, String location, String birth_date){


        this.isOnline=false;
        this.user_id=user_id;
        this.birth_date=birth_date;
        this.location=location;
        this.user_name=user_name;

        
    
        Account current_viewing_id=null; // set as default number the users can not have id(0).

        myPosts=new LDLinkedList<Post>();
        following=new LDLinkedList<Account>();
        followers=new LDLinkedList<Account>();
        actions = new LDLinkedList<String>();
        inbox=new LDLinkedList<Message>();
        outbox=new LDLinkedList<Message>();
        blocked_accounts= new LDLinkedList<Account>();
        //created account notification.
        System.out.println("An account with username " +user_name +" has been created.");
    
    }

// login  account
    public void login(){
   
        isOnline=true;
        

    }

//logout  account
    public void logout(){

        current_viewing_id=null;
        isOnline=false;
        
    }
    
    void show_actions(){

        for(int i=0;i<actions.size();i++){ //serach all the members of actions list print them one by one.
            System.out.println(actions.get(i));
        }

    }

    public void addPost(Post newPost){

        if(isOnline!=true){ // if the user is not logged in the account. print the error message then exit .
       
            System.out.println("You are not logged in .");
            return ;

        }
        else{
            for (int i=0;i<myPosts.size();i++){ // error checking if the the new posts id already exist.
          
                if(newPost.get_pos_id()==myPosts.get(i).get_pos_id()){
                    System.out.println("The post already exist");
                    return ; // exit from the function if dedect an error.
                }

        }

        //add the new post object to posts list variable .If there are not any error.
        newPost.set_userid(this); //set post the user .
        myPosts.add(newPost);
        actions.add("you added a post: " +newPost);
        //current_post++;
        
        }
   
    }
    
    public void blockAccount(Account blocked){

        if(isOnline!=true){
            System.out.println("you are not logged in"); //logging check.
            return;
        }
        else{
            for(int i=0;i<blocked_accounts.size();i++){

                if(blocked.get_id()==blocked_accounts.get(i).get_id() && blocked.get_username()==blocked_accounts.get(i).get_username()){ // find if the matching accoun in blocked list to prevent double blocking.
    
                    System.out.println("you blocked the account anyway before.");
                    return;
                }
            }
    
            blocked_accounts.add(blocked);
    
            for(int i=0;i<following.size();i++){
    
                if(following.get(i).get_id()==blocked.get_id() && following.get(i).get_username()==blocked.get_username()){
    
                    following.remove(i);
                    blocked.unfollowed(this); // remove the account if you are following and remove from its followers..
                }
            }
    
            for(int i=0;i<followers.size();i++){
    
                if(followers.get(i).get_id()==blocked.get_id() && followers.get(i).get_username()==blocked.get_username()){
    
                    unfollowed(blocked);
                    blocked.unfollowing(this); //remove your followers and the blocked account following list.
                }
            }
    
            actions.add("you blocked the account: "+ blocked.get_username()); //add action to action list.
        }
        

    }

    public void unblock(Account blocked){

        boolean is_exist=false;
        int remove_value=0;

        if(isOnline!=true){ // logging check.
            System.out.println("you are not logged in");
            return;
        }
        else{

            for(int i=0;i<blocked_accounts.size();i++){

                if(blocked_accounts.get(i).get_id()== blocked.get_id() && blocked_accounts.get(i).get_username()== blocked.get_username()){//find matching index.
                    remove_value=i;
                    
                    is_exist=true;
                    actions.add("you unblock the account: "+ blocked_accounts.get(i).get_username()); //add the action to actions list.
                }
            }
            if(is_exist==false){
    
                System.out.println("you can not unblock the account not blocked");
                return;
            }
            
                blocked_accounts.remove(remove_value);
        }


        
    
    }

    public void unfollowing(Account unfollow){

        boolean is_exist=false;
        int index_variable=0;
        for(int i=0;i<following.size();i++){

            if(unfollow.get_id()==following.get(i).get_id() && unfollow.get_username()==following.get(i).get_username()){ // find the matching index

                is_exist=true;
                index_variable=i;
                //following.remove(i);
            }
        }
        if(is_exist==true){ //if it found call remove function with index.

            following.remove(index_variable);
        }

    }
    public void addMessage(Message message,LDLinkedList<Account>  account_list){
       
        boolean is_exist=false;
        boolean is_exist2=false;

        if(isOnline!=true){ // if the user is not logged in the account. print the error message then exit .
            
            System.out.println("You are not logged in .");
            return ;

        }
        else{
           
            if(message.get_sender()!=this.user_id){ //check the id if matching with sender id.
                
                System.out.println("incorret sender");
                return;

            }

            for (int i=0;i<following.size();i++){
           
                if(message.get_reciever()==account_list.get(i).get_id()){
                is_exist2=true;

            }
            }

            for(int i=0;i<account_list.size();i++){ // look all the accounts via loop if the account found call addInbox function to add the message to inbox array of the account. Then assign is exist variable as true .
            
                if(account_list.get(i).get_id()==message.get_reciever()){
                
                    is_exist=true;
                    account_list.get(i).addInbox(message); 
                    

                }
            }

            if(is_exist==false){ //if is_exist is not true the account have not found in accounts list. Print an error message.

                System.out.println("the user is not exist with id: "+ message.get_reciever());

            }
            
            else if(is_exist2==false){

            System.out.println("you are not following the account ");
            
            }

            else{

                this.addOutbox(message);
                actions.add("you added a message: "+ message.get_content());
            }

        }
    }

    public void checkInbox(){

        if(isOnline!=true){ //logging checking.

            System.out.println("You are not logged in .");
            return ;
        }
        else{

            System.out.println("There is/are " +inbox.size()+ " message(s) in the inbox."); //to print inbox info.

        }
        
    }

    public void checkOutbox(){

        if(isOnline!=true){

            System.out.println("You are not logged in ."); //logging checking 
            return ;
        }
        else{

            System.out.println("There is/are " +outbox.size()+ " message(s) in the outbox."); // to print outbox info

        }
        
    }

    public void addInbox(Message mymessage){ // adds the message to inbox array.

        inbox.add(mymessage);
       // inbox_size++;

    }

    //to view inbox messages with sender informations.
    //variable users holds all the created accounts.
    //users_size variable for users arrays size.
    public void ViewInbox(LDLinkedList<Account>  users){

        if(isOnline!=true){

            System.out.println("You are not logged in .");
            return ;
        }
        else{
            //search both  inbox array and accounts array by nested loop 
            for (int i=0;i<users.size();i++){
           
                for(int j=0;j<inbox.size();j++){
                    
                    if(inbox.get(j).get_sender()==users.get(i).get_id()){ // if finds mathcing id with inbox array and account list .Prints the message and the accounts infromations

                        System.out.println("Message ID: "+ inbox.get(j).get_messageID()+"\n"+ "From: "+users.get(i).get_username()+ " To: "+this.get_username()+"\n"+"Message: " +inbox.get(j).get_content()+"\n");

                    }
                }
            
            }
        }
    }

    private void addOutbox(Message myMessage){ // adds the message to outbox array.
        
        outbox.add(myMessage);
       // outbox_size++;

    }
    
     
    
    // follow_this variable holds the account for following.
    //add new member to following array then call followed method.
    
    
    public void follow(Account follow_this){
    
        if(isOnline!=true){ // if the user is not logged in the account. print the error message then exit .
       
            System.out.println("You have not logged in .");
            return ;

        }
        else{

        //adds the account to following array and increment the size.
        this.following.add(follow_this);
        //following_number++;
        actions.add("you followed "+follow_this.get_username());

        //call followed method to increment following accounts follower number.
        follow_this.followed(this);
        }
    }

    public void unfollow(Account unfollow_this){

        boolean is_exist=false; //to check unfollow account in following list.
        int index_variable=0;
        if(isOnline!=true){ // if the user is not logged in the account. print the error message then exit .
       
            System.out.println("You have not logged in .");
            return ;

        }
        else{
            
            for(int i=0;i<following.size();i++){
                
                if(following.get(i).get_id()==unfollow_this.get_id() && following.get(i).get_username()==unfollow_this.get_username()){ //search the following list if any mathcing account with id and name information.
                    
                    //following.remove(i); //remove the account.
                    is_exist=true; // set is exist true.
                    
                    actions.add("you unfollowed "+ unfollow_this.get_username());
                }
                if(is_exist!=true){
                    index_variable++;
                }
            }
            if(is_exist==true){ //
                following.remove(index_variable);
                unfollow_this.unfollowed(this); //call unfollowed function to remove also from followers list of the account that will be unfollowed.
                //System.out.println("\n number"+index_variable);
               // following.remove(index_variable);
            }
            else{
                System.out.println("there is no following account with id :"+unfollow_this.get_id());
            }
        }
    }

//The function prints the account informations.
    public void view_profile(Account viewed){

        if(isOnline!=true){

            System.out.println("You have not logged in .");
            return ;

        }
        else{

            for(int i=0;i<viewed.blocked_accounts.size();i++){
                
                if(viewed.blocked_accounts.get(i).get_id()==this.get_id() && viewed.blocked_accounts.get(i).get_username()==this.get_username()){

                    System.out.println("the account: "+ viewed.get_username()+ " blocked you. you can not view his/her profile.");
                    return;
                }
            }
            current_viewing_id=viewed;

            
            System.out.println(
            "User ID :" + viewed.get_id()
            +"\n"+ "Username: " + viewed.get_username()     
            + "\n"+ "Location: " + viewed.get_location() 
            + "\n"+ "Birth Date: " + viewed.get_date()  //     following number                                       followers number
            + "\n"+ viewed.get_username() + " is following " + viewed.get_following() +" account(s) " + " and has " + viewed.get_followers() +" follower(s). ");
           
            if(viewed.get_following()==0){
                System.out.println("There are no following account");
            }
            else{
                System.out.print( viewed.get_username() +" is following: ") ;
                //prints following members name.
                viewed.list_following();
            }
            //                                                   gets post number.
            viewed.list_followers();
            System.out.println(viewed.get_username()+ " has "+ viewed.get_post_number() + " posts. ");

        }
        
    }
                                //takes the account to view.
    public void view_posts(Account posts){

        if(isOnline!=true){

            System.out.println("You have not logged in .");
            return ;

        }
        else{
                                    //holds currently viewing profile id.
            if(posts.get_id()!=current_viewing_id.get_id()){ // checks if posts id and currently viewing account is is matching.
       
                System.out.println("You can not access the accounts posts without viewing his/her profile");
                return;
            }
            else{
    
                
                // print all the post by using for loop
                                    //get post number of the account
                for(int i=0;i<posts.get_post_number();i++){ //get post id with index                    get post content with index
                    
                
                        System.out.println("(PostID:" + posts.myPosts.get(i).get_pos_id()+ ") "+ posts.get_username()+posts.myPosts.get(i).get_content());
                    
               
                }
            }

        }
        

    }
    
                                        // the account for viewing post interactions.
    public void view_post_interactions(Account post_interaction ){

        if(isOnline!=true){ // logging checking.

            System.out.println("You have not logged in .");
            return ;

        }
        else{
                 // checks if post interaction id and currently viewing account is is matching.
            if(post_interaction.get_id()!=current_viewing_id.get_id()){ 
       
                System.out.println("You can not access the accounts posts without viewing his/her profile");
                return;
            }
            else{
    
                for(int i=0;i<post_interaction.myPosts.size();i++){
                    System.out.println("(PostID:" + post_interaction.myPosts.get(i).get_pos_id()+ ") "+ post_interaction.myPosts.get(i).get_content());
                    if (post_interaction.myPosts.get(i).get_likes()==0){
                        System.out.println("The post has no likes.");
                    }
                    else{
                       System.out.print("The post was liked by the following account(s): ") ;
                       post_interaction.myPosts.get(i).print_likers(); // if the post has comments.print the accounts liked the post.
                       System.out.println("");
                    }
    
                    if(post_interaction.myPosts.get(i).get_content_num()==0){ //if the post has no comment.print the message.
                        System.out.println("The post has no comments.");
                    
                    }
                    else{
                        post_interaction.myPosts.get(i).print_senders();
                        System.out.println("");
                    }
                    }
    
            }
        }
        
    }

    


    //prints following accounts one by one.
    public void list_following(){
    
        for (int i=0;i<following.size();i++){

            System.out.print(" "+following.get(i).get_username());

        }
        System.out.println("");
    }

    public void list_followers(){ //print followes one by one.
    
        for (int i=0;i<followers.size();i++){

            System.out.print(" "+followers.get(i).get_username());

        }
        System.out.println("");
    }


    public void followed(Account follower){
    
        this.followers.add(follower);
        //followers_number++;
    }  
    public void unfollowed(Account follower){
    
        int index_variable=0;
        boolean is_exist=false;
        for(int i=0;i<followers.size();i++){

            if(followers.get(i).get_id()==follower.get_id() && followers.get(i).get_username()==follower.get_username()){
                
                index_variable=i;
                is_exist=true;
                
            }

        }
        if(is_exist){

            followers.remove(index_variable);
        }
    }  


    public String get_username(){
        return user_name;
    }

    //getter functions of private variables.
   
    public String get_location(){
        return location;
    }

    //getter birhdate
    
    public String get_date(){
        return birth_date;
    }

   public boolean get_isOnline(){

    return isOnline;
   }
 
    ///getter following
    public int get_following(){
        return following.size();
    }

    //getter followers number
    public int get_followers(){
        return followers.size();
    }

    //getter user id
    public int get_id(){
        return user_id;
    }

    //getter post number
    public int get_post_number(){
        return myPosts.size();
    }
    

}