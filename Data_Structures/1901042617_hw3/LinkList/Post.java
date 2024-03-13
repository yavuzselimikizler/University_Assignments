
import java.util.*;

public class Post{

//Post datas
//private int likes;
private LinkedList<Like> likes; 

private int post_id;
private String content;

//private String [] sender_names; // holds comment sender names.
private LinkedList<Comment> comments; // holds comments.
//private int comment_size;

private Account account_id;

//Constructure
public Post(int post_id,String content){

    this.likes=new LinkedList<Like>();
    this.post_id=post_id;
    this.content=content;
    this.comments= new LinkedList<Comment>();
   // this.like_accounts=new String[1000];
   // this.sender_names=new String[1000];

   // this.comment_size=0;

}

public void addLike(Like post_toLike){
        
    //if you are not currently viewing the account print an error message.
    if(post_toLike.account_id.get_isOnline()!=true){

        System.out.println("you did not logged in");
    }
    else{

        if(post_toLike.get_post()!= this.post_id){
        
            System.out.println("incorrect post id");
            return; 
    
        }
        else{
        
            for(int i=0;i<likes.size();i++){
                
                if(likes.get(i).account_id.get_id()==post_toLike.account_id.get_id()){
                    System.out.println("you can not like the post twice!");
                    return;
                }
            }
                    this.likes.add(post_toLike); // add the accounts  that liked the post name to like accounts array.
                   // this.increment_like(); // increment like number.
                   post_toLike.account_id.actions.add("you liked "+ account_id.get_username()+"'s post: "+post_id);
                      
            }
    }
    
    

    
}
public void unlike(Like unlike_post){

    boolean is_exist=false;
    int index_variable=0;

    if(unlike_post.account_id.get_isOnline()!=true){

        System.out.println("you did not logged in");
    }
    else{

        if(unlike_post.get_post()!= this.post_id){
        
            System.out.println("incorrect post id");
            return; 
    
        }
        else{
    
            for(int i=0;i<likes.size();i++){
    
                if(likes.get(i).get_interaction()==unlike_post.get_interaction()){ // search likes list to find matching interaction id with unlike post variable.
    
                    is_exist=true;
                    index_variable=i;
                    //likes.remove(i);
                }
    
            }
            if(is_exist==true){
                unlike_post.account_id.actions.add("you unliked "+ account_id.get_username()+"'s post: "+post_id);
                likes.remove(index_variable);
            }
            else{
                System.out.println("you have not like the post before");
            }
    
        }
    }
    

}
public void addComment(Comment newcomment){

    //if you are not currently viewing the account print an error message.
    if(newcomment.account_id.get_isOnline()!=true){

        System.out.println("you did not logged in");
    }
    else{
        if(newcomment.get_post()!= this.post_id){
        
            System.out.println("incorrect post id");
            return; 
    
        }
        else{
        
                    //sender_names[comment_size]=newcomment.account_id.get_username();
                    comments.add(newcomment);
                    newcomment.account_id.actions.add("you comment "+ account_id.get_username()+"'s post: "+post_id);
                  //  comment_size++;
                           
        }
    }
    

}

public void unComment(Comment uncomment_post){
   
    boolean is_exist=false;
    int index_variable=0;
    if(uncomment_post.account_id.get_isOnline()!=true){

        System.out.println("you did not logged in");
    }
    else{

        if(uncomment_post.get_post()!= this.post_id){
        
            System.out.println("incorrect post id");
            return; 
    
        }
        else{
    
            for(int i=0;i<comments.size();i++){
    
                if(comments.get(i).get_interaction()==uncomment_post.get_interaction()){ // search likes list to find matching interaction id with unlike post variable.
    
                    is_exist=true;
                    index_variable=i;
                   // comments.remove(i);
                }
    
                
            }
    
            if(is_exist==true){
    
                uncomment_post.account_id.actions.add("you uncomment "+ account_id.get_username()+"'s post: "+post_id);
                comments.remove(index_variable);
    
            }
            else{
                System.out.println("you have not comment the post before");
            }
    
        }
    }
    

}


//likes getter.
public int get_likes(){
    return likes.size();
}

public String get_content(){
    return content;
}

public int get_pos_id(){
    return post_id;
}
public int get_content_num(){
    return comments.size();
}

public void print_likers(){

    for(int i=0;i<likes.size();i++){
        System.out.print(likes.get(i).get_account().get_username()+", ");
    }
}

public void print_senders(){ // prints senders.
    for(int i=0;i<comments.size();i++){
        System.out.println("comment"+(i+1)+" :"+ comments.get(i).get_account().get_username()+" said " + comments.get(i).get_content());
    }
}

public void set_userid(Account post_account){
account_id=post_account;
}

public int get_userid(){
    return account_id.get_id();
}
/* 
public void increment_like(){
    likes++;
}
*/
/* 
public void add_comment(String new_comment){

    comments.add(new_comment);
   //comment_size++;
}
*/

}