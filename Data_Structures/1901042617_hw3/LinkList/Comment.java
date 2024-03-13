
import java.util.*;




public class Comment  extends Interaction{
        
    
    protected String content;
    
//constructure assigns content rest will send to super class .
    public Comment(int interaction,int post,Account account,String comment){
   
      super(interaction,post,account);
    
        this.content=comment;

    }
//content getter method.
    public String get_content(){
        return content;
    }
     public String get_comment(){
        return content;
    }  
    
    public  int get_interaction(){
        return interaction_id;
    }
   
    public  int get_post(){
        return post_id;
    }
    
    public  Account get_account(){
        return account_id;
    }


}

