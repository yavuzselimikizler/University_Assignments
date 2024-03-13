import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;
import java.util.LinkedHashMap;


public class info{

    private int count;
    private String [] words;

    public info(){// default constructures
        count=0;
       words=new String[0];
    }

    public info(String [] word_list){ //with parametre string array
        count=word_list.length;
        words= new String[count];

        for(int i=0;i<word_list.length;i++){ // copy the string values one by one.
            words[i]=word_list[i];
        }
    }

   public void push(String new_str){
    // create a new array with size 1 greater than the original array
    String[] newWords = new String[++count];

// copy all the elements from the original array to the new array
    for (int i = 0; i < count-1; i++) {
        newWords[i] = words[i];
    }

// add the new_str string as the last element of the new array
    newWords[count - 1] = new_str;

// assign the new array to the words variable
    words = newWords; 
    

   }

   public int get_count(){ // getter count.

    return count;

   }

   public String get_words(){ // converts the words in words array to string by getting every value using for loop.

    String print_str="";

    for(int i=0;i<count;i++){

        print_str=print_str+","+words[i];
    }


        return print_str;

   }

   public String [] get_words2(){ // getter words array.

    return words;
   }





}
