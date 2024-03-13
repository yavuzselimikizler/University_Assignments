import java.util.*;


public class Message{

    private int message_id;
    private int sender_id;
    private int reciever_id;
    private String content;

    Message(int message,int sender,int reciever,String content){
        
        this.content=content;
        this.message_id=message;
        this.reciever_id=reciever;
        this.sender_id=sender;
        
    }

    public String get_content(){
        return content;
    }

    public int get_sender(){
        return sender_id;
    }

    public int get_reciever(){
        return reciever_id;
    }

    public int get_messageID(){
        return message_id;
    }

    


}