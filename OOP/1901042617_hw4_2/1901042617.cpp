


#include <iostream>
#include <vector>
#include <fstream>
#include "1901042617.h"
using namespace setnamespace;
using namespace std;


int DayofYearSet::numberset=0;

namespace setnamespace{
DayofYearSet::DayofYearSet(){ //the default constructure.
  number_of_elements=0;
  dates=nullptr; 
  numberset++; //increase static variable by 1 .
}                         

//Operators.
 


 /*DayofYearSet::DayofYear  & operator [](const int index){
   
   if(index> this->get_numberofelements()){
     cout<<"invalid eelement index "<<endl;
     exit(1);
   }
   return this->dates[index];
 }*/

 DayofYearSet operator !(const DayofYearSet & set1){
 
 DayofYearSet temp;
 bool exist;

  for(int i=1;i<13;i++){ //outer loop for months .

    if(i==2){ //days depends on the month value someof them 30 some 31 etch.

      for(int j=1;j<29;j++){
         exist=true;
        for(int l=0;l<set1.get_numberofelements();l++){ //check all the day of year if they are in set1 if they not add them to temp variable
       
       
       if(set1.dates[l].get_the_day()==j && set1.dates[l].get_the_month()==i ){
         exist=false;
       }
      
   
   }
   if(exist==true){
        temp.add_elements(j,i);
     }

      }
    }
    else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
      for(int j=1;j<32;j++){
         exist=true;
        for(int l=0;l<set1.get_numberofelements();l++){
       
       
       if(set1.dates[l].get_the_day()==j && set1.dates[l].get_the_month()==i ){
         exist=false;
       }
      
   
   }
   if(exist==true){
        temp.add_elements(j,i);
     }

 
      }
    }
    else if(i==4 || i==6 || i==9 || i==11){

      for(int j=1;j<31;j++){
         exist=true;
        for(int l=0;l<set1.get_numberofelements();l++){
       
       
       if(set1.dates[l].get_the_day()==j && set1.dates[l].get_the_month()==i ){
         exist=false;
       }
      
   
   }
    if(exist==true){
        temp.add_elements(j,i);
     }
      }
    
    
    }
  
  }
  set1.numberset--;
 return temp;
}

DayofYearSet operator^(const DayofYearSet & set1,const DayofYearSet & set2){
   DayofYearSet temp;
   
   bool exist;
   

   for(int i=0;i<set1.get_numberofelements();i++){//check via nested loop set1 and set2 if there is matching dates assign exist as true if exist true add set1  variables to temp object then returns it.
       exist=false;
      for(int j=0;j<set2.get_numberofelements();j++){
        if(set1.dates[i].get_the_day()==set2.dates[j].get_the_day() && set1.dates[i].get_the_month()==set2.dates[j].get_the_month())
        exist=true;
      }
      if(exist==true){
        temp.add_elements(set1.dates[i].get_the_day(),set1.dates[i].get_the_month());
     }
   
   }
   
   
   set1.numberset--;
   return temp;
 }

 DayofYearSet operator-(DayofYearSet & set1,DayofYearSet & set2){
   DayofYearSet temp;
   
   bool exist;
   

   for(int i=0;i<set1.get_numberofelements();i++){
       exist=true;
      for(int j=0;j<set2.get_numberofelements();j++){ //check via nested loop set1 and set2 if there is matching dates assign exist as false if exist true  set1  variables to temp object then returns it
        if(set1.dates[i].get_the_day()==set2.dates[j].get_the_day() && set1.dates[i].get_the_month()==set2.dates[j].get_the_month())
        exist=false;
      }
      if(exist==true){
        temp.add_elements(set1.dates[i].get_the_day(),set1.dates[i].get_the_month());
     }
   
   }
   
   set1.numberset--; //because of temp object decrease numberset static int by 1.
   
   return temp;
 }

   DayofYearSet operator+(const DayofYearSet & set1,const  DayofYearSet & set2){
   DayofYearSet temp;
   vector <int> u_days;
   vector <int> u_months;
   bool exist;
   

   for(int i=0;i<set1.get_numberofelements();i++){ //compare set1 variables againts set2 if there are any matching dates if the date which in set1 is also exist in set2 dont add variables to temp.
       exist=true;
      for(int j=0;j<set2.get_numberofelements();j++){
        if(set1.dates[i].get_the_day()==set2.dates[j].get_the_day() && set1.dates[i].get_the_month()==set2.dates[j].get_the_month())
        exist=false;
      }
      if(exist==true){
        temp.add_elements(set1.dates[i].get_the_day(),set1.dates[i].get_the_month());
     }
   
   }
   for(int i=0;i<set2.get_numberofelements();i++){// since previous part common dates has not adde all the variables in set2 can be addded to temp object then return it.
      
     
     
        temp.add_elements(set2.dates[i].get_the_day(),set2.dates[i].get_the_month());
        
     
   
   }
   
   set1.numberset--;
   return temp;
 }


 bool operator != (DayofYearSet & set1,DayofYearSet & set2){
  
  int equal_counter=0;

  for(int i=0;i<set1.get_numberofelements();i++){

     for(int j=0;j<set2.get_numberofelements();j++){
       if(set2.dates[j].get_the_day()==set1.dates[i].get_the_day() && set2.dates[j].get_the_month()==set1.dates[i].get_the_month()) equal_counter++;
     }
  }
   if(equal_counter==set1.get_numberofelements() && set1.get_numberofelements()==set2.get_numberofelements()){return false;}
   
   return true;
 }

 bool operator == (const DayofYearSet & set1,const DayofYearSet & set2){
  
  int equal_counter=0;

  for(int i=0;i<set1.get_numberofelements();i++){

     for(int j=0;j<set2.get_numberofelements();j++){
       if(set2.dates[j].get_the_day()==set1.dates[i].get_the_day() && set2.dates[j].get_the_month()==set1.dates[i].get_the_month()) equal_counter++;
     }
  }
   if(equal_counter==set1.get_numberofelements() && set1.get_numberofelements()==set2.get_numberofelements()){return true;}
   
   return false;
 }

std::ostream & operator << (std::ostream & out,DayofYearSet & prnt){

 for(int i=0;i<prnt.get_numberofelements();i++){
   out<<"day: "<<prnt.dates[i].get_the_day()<<" month: "<<prnt.dates[i].get_the_month()<<" "<<endl;
 }
 out<<prnt.get_numberofelements()<<" element in set "<<endl;
  
  return out;
}
void DayofYearSet::DayofYear::set_the_day(int new_day){Day=new_day;} //set day and month for dayofyear class.

void DayofYearSet::DayofYear::set_the_month(int new_month){Month=new_month;}

int DayofYearSet::get_numberofelements()const{ //getters functions to get day and month values.

  return number_of_elements;
}

int DayofYearSet::DayofYear::get_the_day()const{ 
 return Day;
}
int DayofYearSet::DayofYear::get_the_month()const{
 return Month;
}
int DayofYearSet::get_setnumber()const{
  return numberset;
}


bool DayofYearSet::add_elements(int the_day,int the_month){
typedef DayofYear* dayfyear;

dayfyear temp=dates; // assign pointer to temp day of year pointer.

for(int i=0;i<number_of_elements;i++){ // sets musnt have equal dates so check if input variables already exist in object.
 if(dates[i].get_the_day()==the_day && dates[i].get_the_month()==the_month){
   cout<<"the date added already"<<endl;
   return false;
 }
}

if(!(the_month>0 && the_month<13)){ //first check if entered date valid or not regarding the input write error message.
  cout<<"invalid month"<<endl;
  return false;
}
else if(the_month==2 && !(the_day>0 && the_day<29)){
      cout<<"invalid date"<<endl;
      return false;
    }
    else if((the_month==1 || the_month==3 || the_month==5 || the_month==7 || the_month==8 || the_month==10 || the_month==12) && !(the_day>0 && the_day<32)){
      cout<<"invalid date"<<endl;
      
      return false;
    }
    else if((the_month==4 || the_month==6 || the_month==9 || the_month==11) && !(the_day>0 && the_day < 31)){
      cout<<"invalid date"<<endl;
      return false;
    
    
    }

//delete [] dates;


dates=new DayofYear [number_of_elements+1]; //dynamically allocate first.
for(int i=0;i<number_of_elements;i++){
  dates[i].set_the_day(temp[i].get_the_day());
  dates[i].set_the_month(temp[i].get_the_month()); // add temp variables to dates 
}
dates[number_of_elements].set_the_day(the_day);
dates[number_of_elements].set_the_month(the_month); // then add input variables.
delete[] temp; //free the temp pointer.
number_of_elements++;
 return true;
}

bool DayofYearSet::remove_elements(int the_day,int the_month){
  
  int removal_index;
  bool exist_index=false;
  DayofYear* temp=dates;
  for(auto i=0;i<get_numberofelements();i++){

    if(temp[i].get_the_day()==the_day && temp[i].get_the_month()==the_month){ //dedect the index that matching with recieved day and month values 
      removal_index=i;
      exist_index=true;
    }

  }
  
  if(exist_index==true){
  
   for(decltype(removal_index) j=removal_index;j<get_numberofelements();j++){ //slide temp array variables to left from the index .
     temp[j].set_the_day(temp[j+1].get_the_day());
     temp[j].set_the_month(temp[j+1].get_the_month());

   }
   number_of_elements--;
   dates=new DayofYear[number_of_elements]; //allocate memory for dates .
   for(auto i=0;i<number_of_elements;i++){
     dates[i].set_the_day(temp[i].get_the_day());
     dates[i].set_the_month(temp[i].get_the_month());
     
   }
   delete[] temp; //free the date pointer.
    return true;
    
  }
  else{
    cout<<"invalid date"<<endl;
  }
 
  return false;
}

void DayofYearSet::print(){
    cout<<dates[0].get_the_day()<<" "<<number_of_elements;
}
}
int main(){

  DayofYearSet s1,s2,s4,s5,s6,s7,s8,s9,s10; //s3 is not included.
  
  bool sth,menu=true;
  int command;
  ofstream file("sets.txt");
  s1.add_elements(0,7);
  s7.add_elements(7,8);
  s7.add_elements(7,8);
  s7.add_elements(1,5);
  s7.add_elements(2,3);
  s7.add_elements(3,4);

  s8.add_elements(21,32);
  s8.add_elements(1,5);
  s8.add_elements(2,3);
  s8.add_elements(3,4);

  s1.add_elements(1,12);
  s1.add_elements(2,3);
  s1.add_elements(5,6);
  cout<<s1;
  s1.add_elements(4,4);
  s2.add_elements(2,12);
  
 // cout<<s1;
  cout<<"\n\n added s1 "<<endl;
  cout<<s1;
  
  s1.remove_elements(4,4);//test remove.
  cout<<"\n\nremoved"<<endl;
  cout<<s1;
  cout<<"\n\n";
  cout<<s2;

  s2.add_elements(3,6);
  s2.add_elements(2,3);
  s2.add_elements(5,6);
  cout<<"\n\nadded s2";
  cout<<s2;
  
   

  s4=s1+s2;
  cout<<"\n\n +"<<endl;
  cout<<s4;
  
  s5=s1-s2;
  cout<<"\n\n -"<<endl;
  cout<<s5;

  cout<<"\n \n ^"<<endl;

  s6=s1 ^ s2;
  cout<<s6;
  
  s9=s7+s8;
  s10=s7 ^ s8;
  
   if(!(s1 + s2)==(!s1 ^ !s2)){ // tests de morgan rules for 5 different pair sets
     cout<<"\n\nde morgan true"<<endl;
   }
   else{
     cout<<"false"<<endl;
   }
   if(!(s1 + s4)==(!s1 ^ !s4)){
     cout<<"\n\nde morgan true"<<endl;
   }
   else{
     cout<<"false"<<endl;
   }
   if(!(s7 + s8)==(!s7 ^ !s8)){
     cout<<"\n\nde morgan true"<<endl;
   }
   else{
     cout<<"false"<<endl;
   }
   if(!(s9 + s4)==(!s9 ^ !s4)){
     cout<<"\n\nde morgan true"<<endl;
   }
   else{
     cout<<"false"<<endl;
   }
   
   if(!(s9 + s5)==(!s9 ^ !s5)){
     cout<<"\n\nde morgan true"<<endl;
   }
   else{
     cout<<"false"<<endl;
   }
   
  
   if(!file.is_open()){ //writes sets to file.

     cout<<"file could not open";
   }
   else{
     file<<"set1:"<<endl;
     file<<s1;
     file<<"set2"<<endl;
     file<<s2;
     file<<"set4:"<<endl;
     file<<s4;
     file<<"set5"<<endl;
     file<<s5;
     file<<"set6:"<<endl;
     file<<s6;
     file<<"set7"<<endl;
     file<<s7;
      file<<"set8"<<endl;
     file<<s8;
     file<<"set9:"<<endl;
     file<<s9;
     file<<"set10"<<endl;
     file<<s10;

   }
   
   
   cout<<"there are "<<s1.get_setnumber()<<" set"<<endl;
   file.close();
    return 0;
}
