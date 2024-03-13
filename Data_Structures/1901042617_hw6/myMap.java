import java.util.List;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.regex.*;
public class myMap{


    private LinkedHashMap <String, info> map;
    private int mapSize;
    private String str;

    public myMap(String str){ // constructure.

        String[] divide_words = str.split("\\s+"); // split by whitespace
        ArrayList<String> wordsList = new ArrayList<String>();
        map = new LinkedHashMap<>();
        for (int i = 0; i < divide_words.length; i++) { // add the words to the word_list one by one
            wordsList.add(divide_words[i]);
        }
        ArrayList<Character> char_list=new ArrayList<Character>();

        for (int i = 0; i < wordsList.size(); i++) {
            String word = wordsList.get(i);
            
            for(int j=0;j<word.length();j++){ // get the letters of each words.
                
               if( !contains_letter(char_list,word.charAt(j))){// ind if the letter added before. if it has not added set a key value and a value  for map and put them.
                info add_info= new info();
                add_info.push(word);
                map.put(String.valueOf(word.charAt(j)),add_info);
                char_list.add(word.charAt(j));
               }
               else{ // otherwise find the corresponding letter index and update the info object.
                for (Map.Entry<String, info> entry : map.entrySet()) {
                    String key = entry.getKey();
                    info value = entry.getValue();
                    if (key.equals(String.valueOf(word.charAt(j)))) {
                        value.push(word);
                    }
                }
               }
                
            }
        }
        mapSize=char_list.size(); // assing the size and string values at the end.
        this.str=str;
    }
    public myMap(){
        map=new LinkedHashMap<>();
        mapSize=0;
    }
    public myMap(LinkedHashMap <String, info> map){
        this.map=map;
    }
    public LinkedHashMap <String, info> get(){
        return map;
    }

    public boolean contains_letter(ArrayList<Character> list1,Character c){ // if the char in list return true otherwise return false.

        for(int i=0;i<list1.size();i++){

            if(list1.get(i)==c){
                return true;
            }
        }


        return false;

    }
    public void put(String key_value,info new_info){// takes the key and value variables and puts it to map variable.

        map.put(key_value,new_info);

    }
    public void to_String(){// prints the map in desiredformat.

        for (Map.Entry<String, info> entry : map.entrySet()) {
            String key = entry.getKey();
            info value = entry.getValue();
            System.out.println(key + " Count:"+ value.get_count()+"-"+"Words:"+value.get_words());
        }

    }



















}