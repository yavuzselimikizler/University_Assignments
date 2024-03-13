#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>
#include "iterable.h"
using namespace std;
#ifndef SET_H
#define SET_H
namespace my_namespace{



template<class T>
class GTUSet: public Iterable<T> {


public:
GTUSet();
GTUSet(T *,int);
GTUSet(GTUSet && an );
 GTUSet<T> intersect(GTUSet<T> & second);
 bool empty();

 void erase(GTUIterator<T> );

 int size();

 GTUIteratorConst<T> cend() const;
 void  union_s(GTUSet<T> &second);
 void clear();

 void insert(T value);

 GTUIterator<T> begin();

 GTUIterator<T> end();
 
 GTUIterator<T> find(T);
 int get_length(){
     return length;
 }
 T get_set(T index){
  return set1.get()[index];
 }

private:
    
    shared_ptr<T> set1;
    
    int length;


};


template<class T>
GTUSet<T>::GTUSet(GTUSet && ana)
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    set1=ana.set1;
    ana.set1=nullptr;

    cout<<"moved"<<endl;
}
template<typename T>
GTUSet<T>::GTUSet(T* temp_arr,int size):Iterable<T>(size){
    shared_ptr<T> tempset(new T[size], std::default_delete<T[]>());
    length=size;

    for(int i=0;i<size;i++){
        tempset.get()[i]=temp_arr[i];
    }
    set1=tempset;
}
template<typename T>
GTUSet<T>::GTUSet()
                                   :Iterable<T>(0) {

    
    shared_ptr<T> tempset(new T[0], std::default_delete<T[]>());
    set1 = tempset;
    length=0;
}

template<class T>
 void GTUSet<T>::clear(){
    set1=nullptr;
    shared_ptr<T> tempset1(new T[0], std::default_delete<T[]>());
    set1 = tempset1;
    length=0;
 }

 template<class T>
bool GTUSet<T>::empty(){ //all the algoritms same array and vector for virtual functions except add function
    if(length>0)
    return false;
    else
    return true;
}

template<class T>
 GTUIterator<T> GTUSet<T>::begin(){
    return GTUIterator<T>(set1.get());
 }
 
template<class T>
 GTUIterator<T> GTUSet<T>::end(){
    return GTUIterator<T>(set1.get()+length);
 }

 template<class T>
 int GTUSet<T>::size(){
    return length;
 }

 template<class T>
 void GTUSet<T>::erase(GTUIterator<T> iter){
  int index=0;
   shared_ptr<T> temp(new T[length-1], std::default_delete<T[]>());
  
  

  for(auto it=this->begin();it!=this->end();it++){
     
      if(it.getpit()==iter.getpit()){
        
          for (int i=index;i<length;i++)
            {
                
                set1.get()[i]=set1.get()[i+1];
            }
      }
   index++;
  }
  length--;
for(int i=0;i<length;i++){
    temp.get()[i]=set1.get()[i];
    
}
set1=nullptr;
set1=temp;
 }


template<class T>
 void GTUSet<T>::insert(T value){
  
  T min;
  T temp_value;

shared_ptr<T> temp(new T[length+1], std::default_delete<T[]>());

for(int i=0;i<length;i++){ //check if the value included if its exit from function.
    if(value==set1.get()[i]){
        return;
    }
}


for(auto i=0;i<length;i++){
    temp.get()[i]=set1.get()[i];
}

set1=nullptr;
length++;

set1=temp;

set1.get()[length-1]=value;

for(int i=0;i<length-1;i++){ //sort the values.
  
  for(int j=0;j<length-1-i;j++){
   if(set1.get()[j]>set1.get()[j+1]){
   temp_value=set1.get()[j+1];
   set1.get()[j+1]=set1.get()[j];
   set1.get()[j]=temp_value;
   }
  }

  }
    




 }

 template<class T>
 GTUIteratorConst<T> GTUSet<T>::cend() const{
    return GTUIteratorConst<T>(set1.get() + length);
 }

template<class T>
GTUIterator<T> GTUSet<T>::find(T value) { //finds given values pointer return iterator.
    
    for(int i=0;i<length;i++){
        
        if(set1.get()[i]==value){
            return GTUIterator<T>(set1.get() + i);
            
        }
    }
    
    return GTUIterator<T>(set1.get() +length);
 }

 template<class T>
  void  GTUSet<T>::union_s(GTUSet<T> &second){ //sends ol the values of second set to insert func.
     
    for(int i=0;i<second.size();i++){
        this->insert(second.get_set(i));
    }

 }  

 template<class T>
GTUSet<T> GTUSet<T>::intersect(GTUSet<T> & second){

    T *temp_arr;
    int element_counter=0,index_number=0;

    for(int i=0;i<this->get_length();i++){

        for(int j=0;j<second.get_length();j++){

            if(this->get_set(i)==second.get_set(j)){ //finds intersect values of two objects .
                element_counter++;
            
            }
        }
    }
    
    temp_arr=new T[element_counter];
     
     for(int i=0;i<this->get_length();i++){ //assign them to temp arr.

        for(int j=0;j<second.get_length();j++){

            if(this->get_set(i)==second.get_set(j)){
                temp_arr[index_number]=this->get_set(i);
                index_number++;
            
            }
        }
    }
 return GTUSet<T>(temp_arr,index_number); //returns constructure 

}
}
#endif 