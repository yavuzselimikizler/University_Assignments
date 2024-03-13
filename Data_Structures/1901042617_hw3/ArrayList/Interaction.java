

import java.util.*;


 abstract public  class Interaction {
    
    protected int interaction_id;
    protected Account account_id;
    protected int post_id;
    
    Interaction(int interaction,int post,Account account){
        this.interaction_id=interaction;
        this.account_id=account;
        this.post_id=post;
    }
    
    
    
    //getter methods.
    public abstract int get_interaction();
    public abstract int get_post();
    public  abstract Account get_account();
    
    
}






 





