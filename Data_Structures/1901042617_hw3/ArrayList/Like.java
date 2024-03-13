
import java.util.*;

public class Like extends Interaction{

    
    //constructure
    public Like(int interaction,Account account,int post){
        
        super(interaction,post,account);
        
    }
    @Override
    public  int get_interaction(){
        return interaction_id;
    }
    @Override
    public  int get_post(){
        return post_id;
    }
    @Override
    public  Account get_account(){
        return account_id;
    }
}