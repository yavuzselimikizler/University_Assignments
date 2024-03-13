import java.io.*;
import java.util.*;
import java.lang.System;
import java.io.IOException;
import java.io.File;

public class Main{



    public static void main(String[] args) {
          DayofYearSet a1,a2,a3,a4,a5 ,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,b1,b2,b3,b4,b5,b6,b7,b8,c1,c2,c3,c4,c5,d1,d2,d3,d4,d5;
    
          a1=new DayofYearSet();
          a2=new DayofYearSet();
          a14=new DayofYearSet();
          a15=new DayofYearSet(); //set new DayofYearSet objects
          a16=new DayofYearSet();
          a14.add(13, 2);
          a14.add(15, 1);
          a14.add(2, 5);
          a14.add(26, 9);
          a14.add(16, 5); //call add functions to fill set 4
          a14.add(27, 9);
    
          a15.add(13, 2);
          a15.add(15, 1);
          a15.add(2, 5);
          a15.add(25, 7);
          a15.add(13, 5);
          a15.add(20, 10);
    
          a16.add(10, 1);
          a16.add(12, 7);
          a16.add(4, 8);
          a16.add(21, 6);
          a16.add(13, 5);
          a16.add(20, 10);
         // DayofYearSet.DayofYear a2=a1.new DayofYear();
         System.out.println("........add method.........");
         System.out.println("set1:");
         
         a1.add(17, 3);
          a1.add(15, 4);
          a1.add(16, 5);
          a1.add(27, 9);
          System.out.println("size: "+a1.get_numberofset());
          System.out.println(a1.toString(a1.get_numberofset()-1));
          System.out.println("set2:");
          
          a2.add(17, 6);
          a2.add(15, 4);
          a2.add(31, 4);
          a2.add(20, 12);
          a2.add(30,11);
          System.out.println("size : "+a2.get_numberofset());
          System.out.println(a2.toString(a2.get_numberofset()-1));
          ArrayList<DayofYearSet.DayofYear> employees = new ArrayList<>();
          System.out.println("........ArrayList constructure.........");
         employees.add(new DayofYearSet.DayofYear(12,3));
         employees.add(new DayofYearSet.DayofYear(31,5));
          employees.add(new DayofYearSet.DayofYear(17,3));
          a7= new DayofYearSet(employees);
          System.out.println("set3:");
          System.out.println(a7.toString(a7.get_numberofset()-1));
          //a1.remove(15, 4);
         // a1.ToString();
         
         System.out.println("........remove method.........");
    
         System.out.println("for set1:");
         a1.remove(27, 9);
         System.out.println(a1.toString(a1.get_numberofset()-1));
    
         System.out.println("for set2:");
         a2.remove(17, 6);
         System.out.println(a2.toString(a2.get_numberofset()-1));
           
         System.out.println("........union method.........");
         System.out.println("set1 + set2");
          a3=a1.union(a2);
          System.out.println(a3.toString(a3.get_numberofset()-1));
          a4=a1.union(a7);
          System.out.println("set1 + set3");
          System.out.println(a4.toString(a4.get_numberofset()-1));
          
          System.out.println("........intersection method.........");
         
          a5=a1.intersection(a2);
          System.out.println("set1 ^ set2");
          System.out.println(a5.toString(a5.get_numberofset()-1));
          a6=a1.intersection(a7);
          System.out.println("set1 ^ set3");
          System.out.println(a6.toString(a6.get_numberofset()-1));
          
          System.out.println("........difference method.........");
          System.out.println("set1 - set2");
          a8=a1.difference(a2);
          
          System.out.println(a8.toString(a8.get_numberofset()-1));
          System.out.println("set1 - set3");
          a9=a1.difference(a7);
          System.out.println(a9.toString(a9.get_numberofset()-1));
         // a1.ToString();
         System.out.println(a1.get_numberofset());
    
         System.out.println("........complement method........."); //complement method can not seen in teminal therefore ı wrote it to comlement file.
         
         System.out.println("complement method can not seen in teminal therefore I wrote it to complement  for set1 and set2  file.\n");
         a10=a1.complement();
         a11=a2.complement();
         try {
          File newf = new File("complement.txt");
          if (newf.createNewFile()) {
            System.out.println("File created: " + newf.getName());
          } else {
            System.out.println("File already exists.");
          }
        } catch (IOException a) {
          System.out.println("An error occurred.");
          a.printStackTrace();
        }
      
         try {
          FileWriter mywriter = new FileWriter("complement.txt");
          mywriter.write("!set1: \n"+a10.toString(a10.get_numberofset()-1)+"\n !set2 \n"+a11.toString(a11.get_numberofset()-1));
          mywriter.close();
          System.out.println("Successfully wrote to the file.");
        } catch (IOException b) {
          System.out.println("An error occurred.");
          b.printStackTrace();
        }
        System.out.println(" ");
        System.out.println("........de morgan rule.........");
        System.out.println("for set1 and set2");
        a12=a3.complement();
        a13=a10.intersection(a11);
        if(a12.equals(a13)){
          System.out.println("de morgan rule confirmed\n");
        }
        else{
          System.out.println("de morgan rule not confirmed\n");
        }
        b1=a14.union(a15);
        b2=b1.complement();
        b3=a14.complement();
        b4=a15.complement();
        b5=b3.intersection(b4);
        System.out.println("for set4 and set5");
    
        if(b2.equals(b5)){
          System.out.println("de morgan rule confirmed\n");
        }
        else{
          System.out.println("de morgan rule not confirmed\n");
        }
        
        System.out.println("for set1 and set3");
        b6=a4.complement();
        b7=a7.complement();
        b8=a10.intersection(b7);
    
        if(b6.equals(b8)){
          System.out.println("de morgan rule confirmed\n");
        }
        else{
          System.out.println("de morgan rule not confirmed\n");
        }
        
        System.out.println("for set2 and set3");
        c1=a2.union(a7);
        c2=c1.complement();
        c3=a2.complement();
        c4=a7.complement();
        c5=c3.intersection(c4);
    
        if(c2.equals(c5)){
          System.out.println("de morgan rule confirmed\n");
        }
        else{
          System.out.println("de morgan rule not confirmed\n");
        }
        System.out.println("for set5 and set6");
        d1=a15.union(a16);
        d2=d1.complement();
        d3=a15.complement();
        d4=a16.complement();
        d5=d3.intersection(d4);
    
        if(d2.equals(d5)){
          System.out.println("de morgan rule confirmed\n");
        }
        else{
          System.out.println("de morgan rule not confirmed\n");
        }
    
         try {
          File myObj = new File("filename.txt");
          if (myObj.createNewFile()) {
            System.out.println("File created: " + myObj.getName());
          } else {
            System.out.println("File already exists.");
          }
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
        }
      
         try {
          FileWriter myWriter = new FileWriter("filename.txt");
          myWriter.write("set1 : \n"+a1.toString(a1.get_numberofset()-1)+" set2: \n"+a1.toString(a1.get_numberofset()-1)+"set3 \n"+a7.toString(a7.get_numberofset()-1)+"set4 \n"+a14.toString(a14.get_numberofset()-1)+"set5 \n"+a15.toString(a15.get_numberofset()-1)+"set6 \n"+a16.toString(a16.get_numberofset()-1)+"\n union set1 set2\n"+a3.toString(a3.get_numberofset()-1)+"\n intersection set1 set2 \n"+a5.toString(a5.get_numberofset()-1)+"\n difference set1 set2 \n"+a8.toString(a8.get_numberofset()-1));
          myWriter.write("\n !(set1+set2)\n"+a12.toString(a12.get_numberofset()-1));
          myWriter.write("\n !set1 ^ !set2 \n"+a13.toString(a13.get_numberofset()-1));
          if(a12.equals(a13)){
            myWriter.write("de morgan rule confirmed\n");
          }
          else{
            myWriter.write("de morgan rule not confirmed\n");
          }
          myWriter.close();
          System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
        }
      
    
    
    
    
    }
    }