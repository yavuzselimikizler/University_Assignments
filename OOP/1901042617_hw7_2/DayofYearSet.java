import java.io.*;
import java.util.*;
import java.lang.System;
import java.io.IOException;
import java.io.File;

class DayofYearSet{
   
    private static int totalnumberofset=0;
 private DayofYear [] dates;
 private int numberofset;
    public DayofYearSet(ArrayList<DayofYear> list){ // take dayofyear object list as a parametre.
     
      for(var i=0;i<list.size();i++){
        this.add(list.get(i).get_theday(),list.get(i).get_themonth()); //call add function to fill objects takes lists elements variables as parametre .
      }
      totalnumberofset++; // increment total numberofset since new set generateed.
    }
    public DayofYearSet(){
      dates=new DayofYear[0];
      
      numberofset=0;
      
      totalnumberofset++;
    }
  public int get_numberofset(){ //returns size of one set.
      return numberofset;
  }
  public int get_totalnumberodset(){ //returns set number.

    return totalnumberofset;
  }
  public DayofYearSet complement(){
    
 DayofYearSet temp=new DayofYearSet();
 boolean exist;

  for(int i=1;i<13;i++){ //nested loop month{day} compare all the day of year with operated object and if there is matching date dont return it.

    if(i==2){

      for(int j=1;j<29;j++){ //check all the days of year if they are added into  the set already if they not adds them to temp object via nested loops. 
         exist=true;
        for(int l=0;l<this.get_numberofset();l++){
       
       
       if(this.dates[l].get_theday()==j && this.dates[l].get_themonth()==i ){
         exist=false;
       }
      
   
   }
   if(exist==true){
        temp.add(j,i);
     }

      }
    }
    else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
      for(int j=1;j<32;j++){
         exist=true;
        for(int l=0;l<this.get_numberofset();l++){
       
       
       if(this.dates[l].get_theday()==j && this.dates[l].get_themonth()==i ){
         exist=false;
       }
      
   
   }
   if(exist==true){
        temp.add(j,i);
     }

 
      }
    }
    else if(i==4 || i==6 || i==9 || i==11){

      for(int j=1;j<31;j++){
         exist=true;
        for(int l=0;l<this.get_numberofset();l++){
       
       
       if(this.dates[l].get_theday()==j && this.dates[l].get_themonth()==i ){
         exist=false;
       }
      
   
   }
    if(exist==true){
        temp.add(j,i);
     }
      }
    
    
    }
  
  }
  
 return temp; //returns temp object 
  }
  public DayofYearSet intersection(DayofYearSet set2){

    DayofYearSet temp=new DayofYearSet();;
   
   boolean exist;
   

   for(int i=0;i<this.get_numberofset();i++){//compare dates of two object if the elements equal ads them to temp object then returns it.
       exist=false;
      for(int j=0;j<set2.get_numberofset();j++){
        if(this.dates[i].get_theday()==set2.dates[j].get_theday() && this.dates[i].get_themonth()==set2.dates[j].get_themonth())
        exist=true;
      }
      if(exist==true){
        temp.add(this.dates[i].get_theday(),this.dates[i].get_themonth());
     }
   
   }
   
   
   
   return temp;
  }
  public DayofYearSet difference(DayofYearSet set2){
    DayofYearSet temp= new DayofYearSet();
    
    boolean exist;
    
 
    for(int i=0;i<this.get_numberofset();i++){
        exist=true;
       for(int j=0;j<set2.get_numberofset();j++){ //compares this dates agaiints set2 dates if the date not in set2 adds it into temp object.
         if(this.dates[i].get_theday()==set2.dates[j].get_theday() && this.dates[i].get_themonth()==set2.dates[j].get_themonth())
         exist=false;
       }
       if(exist==true){
         temp.add(this.dates[i].get_theday(),this.dates[i].get_themonth());
      }
    
    }
   
    
    
    return temp;
  }

  public DayofYearSet union(DayofYearSet set2){
    DayofYearSet temp=new DayofYearSet();
   
   boolean exist;
   

   for(int i=0;i<this.get_numberofset();i++){
       exist=true;
      for(int j=0;j<set2.get_numberofset();j++){//compare this objects dates againts set2 objects dates if the dates in this also in set2 dont add it otherwise add.
        if(this.dates[i].get_theday()==set2.dates[j].get_theday() && this.dates[i].get_themonth()==set2.dates[j].get_themonth())
        exist=false;
      }
      if(exist==true){
        temp.add(this.dates[i].get_theday(),this.dates[i].get_themonth());
     }
   
   }
   for(int i=0;i<set2.get_numberofset();i++){ //then add set2 objects dates to temp.
      
     
     
        temp.add(set2.dates[i].get_theday(),set2.dates[i].get_themonth());
        
     
   
   }
   
   
   return temp;
  }
  public boolean remove(int the_day,int the_month){
    int removal_index=0;
  boolean exist_index=false;
  DayofYear[] temp=new DayofYear[numberofset];
  for(var i=0;i<numberofset;i++){
    temp[i]=new DayofYear();
  }
  for(var j=0;j<get_numberofset();j++){
    temp[j].set_theday(dates[j].get_theday());
    temp[j].set_themonth(dates[j].get_themonth());

  }
  for(var i=0;i<get_numberofset();i++){

    if(dates[i].get_theday()==the_day && dates[i].get_themonth()==the_month){ //check if the entered date is in the set.
      removal_index=i;
      exist_index=true;
    }

  }
  
  if(exist_index==true){ //then erase it by swipping .
  
   for(var j=removal_index;j<get_numberofset()-1;j++){
     temp[j].set_theday(temp[j+1].get_theday());
     temp[j].set_themonth(temp[j+1].get_themonth());

   }
   numberofset--; //decrease element number.
   dates=new DayofYear[numberofset];
   for(var i=0;i<numberofset;i++){
     dates[i]=new DayofYear();
   }
   for(var i=0;i<numberofset;i++){
     dates[i].set_theday(temp[i].get_theday());
     dates[i].set_themonth(temp[i].get_themonth());
     
   }
   
    return true;
    
  }
  else{
    System.out.println("entered date is not in the set"); //if the entered date not in the set print warning message.
  }
 
  return false;
  }
  public boolean equals(DayofYearSet o){
    int equal_counter=0;

  for(int i=0;i<this.get_numberofset();i++){ //compares all the variables of two set and if find any matchin increment the counter .

     for(int j=0;j<o.get_numberofset();j++){
       if(o.dates[j].get_theday()==this.dates[i].get_theday() && o.dates[j].get_themonth()==this.dates[i].get_themonth()) equal_counter++;
     }
  }
   if(equal_counter==this.get_numberofset() && this.get_numberofset()==o.get_numberofset()){return true;} //if counter equal to set number of both set returns true.
   
   return false;
  }
  public String toString(int i){ //calls toString function recursivly by decreasing i parametres that holds index value from end to begin of set.
    
        
           if(i==0){
             return "the day "+dates[i].get_theday()+" the month "+dates[i].get_themonth()+"\n";
           }
           else{
             return "the day "+dates[i].get_theday()+" the month "+dates[i].get_themonth()+"\n"+toString(i-1);
           }
        
    
    
  }
  public void add(int add_day,int add_month){

    DayofYear []temp =new DayofYear[numberofset+1];

    for(int i=0;i<numberofset;i++){
      if(dates[i].get_theday()==add_day && dates[i].get_themonth()==add_month){
        System.out.println("the date added already");
        return;
      }
     }
     
     if(!(add_month>0 && add_month<13)){ //first checks entered dates validity .
       System.out.println("invalid month");
       return;
     }
     else if(add_month==2 && !(add_day>0 && add_day<29)){
           System.out.println("invalid date");
           return;
         }
         else if((add_month==1 || add_month==3 || add_month==5 || add_month==7 || add_month==8 || add_month==10 || add_month==12) && !(add_day>0 && add_day<32)){
           System.out.println("invalid date");
           
           return;
         }
         else if((add_month==4 || add_month==6 || add_month==9 || add_month==11) && !(add_day>0 && add_day < 31)){
           System.out.println("invalid date");
           return;
         
         
         }

    for(int i=0;i<numberofset;i++){
        temp[i]=new DayofYear();
    }
    for(int i=0;i<numberofset;i++){
        temp[i].set_theday(dates[i].get_theday());
        temp[i].set_themonth(dates[i].get_themonth());
    }
    
    
    numberofset++;
    
     
    dates=new DayofYear[numberofset];
    for(int i=0;i<numberofset;i++){
        dates[i]=new DayofYear();
       } 
    for(int i=0;i<numberofset-1;i++){
        dates[i].set_theday(temp[i].get_theday());
        dates[i].set_themonth(temp[i].get_themonth());
    }
   
   
    
        dates[numberofset-1].set_theday(add_day);
        dates[numberofset-1].set_themonth(add_month);
    
    
    
    
  }
 static class DayofYear{
  
  DayofYear(int day,int month){

    the_day=day;
    the_month=month;
  }
  DayofYear(){

  }

  public int get_theday(){
     return the_day;
  }
 public int get_themonth(){
    return the_month;
 }
 
 public void set_theday(int day){
   the_day=day;
 }
 public void set_themonth(int month){
  the_month=month;
 } 
 
  
  private int the_day;
  private int the_month;
}
 


}