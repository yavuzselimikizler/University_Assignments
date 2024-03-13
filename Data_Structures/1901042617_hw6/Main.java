import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.regex.*;
public class Main{

public static String preprocess(String str){

    String new_str=str.toLowerCase();

    
    // Remove non-letter characters (except spaces) using regex
    Pattern pattern = Pattern.compile("[^a-z\\s]");
    Matcher matcher = pattern.matcher(new_str);
    StringBuffer sb = new StringBuffer();
    while (matcher.find()) {
        matcher.appendReplacement(sb, "");
    }
    matcher.appendTail(sb);
    new_str = sb.toString();

    return new_str;
}
    public static void main(String [] args){

        String str1="Buzzing bees buzz.";
        String str2="'Hush, hush!' whispered the rushing wind.";
        String str3="The playful breeze gently whispered secrets in the golden meadow.";

        
       
       

        
       
        
        System.out.println("\n\n\n.......................string 1....................\n\n\n");

        System.out.println(str1);
        str1=preprocess(str1);
        System.out.println(str1);
        myMap map1= new myMap(str1);
        mergeSort merge1= new mergeSort(map1);
        merge1.print_maps();

        System.out.println("\n\n\n.......................string 2....................\n\n\n");
        
        System.out.println(str2);
        str2=preprocess(str2);
        System.out.println(str2);
        myMap map2= new myMap(str2);
        mergeSort merge2= new mergeSort(map2);
        merge2.print_maps();
        System.out.println("\n\n\n.......................string 3....................\n\n\n");

        System.out.println(str3);
        str3=preprocess(str3);
        System.out.println(str3);
       
        myMap map3= new myMap(str3);

       // map1.to_String();
        
       
        mergeSort merge3= new mergeSort(map3);
        merge3.print_maps();
        
    }
}
