#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>
#include "iterable.h"
using namespace std;
#ifndef ARR_H
#define ARR_H


namespace my_namespace{



template<class T,int SIZE>
class GTUArray: public Iterable<T> {


public:

 GTUArray( );
 GTUArray(GTUArray && an );
 bool empty();

 void erase(GTUIterator<T> );

 int size();

 GTUIteratorConst<T> cend() const;

 void clear();

 GTUIterator<T> begin();

 GTUIterator<T> end();
 
 void add(T value);

private:
    
    shared_ptr<T> array;
    int length;
};



template<class T,int SIZE>
GTUArray<T,SIZE>::GTUArray(GTUArray && ana) //move constructure
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    array=ana.array;
    ana.array=nullptr;
    cout<<"moved"<<endl;
}

template<typename T,int SIZE>
GTUArray<T,SIZE>::GTUArray() //default constructure.
                                   :Iterable<T>(0) {

    
    shared_ptr<T> temparray(new T[SIZE], std::default_delete<T[]>());
    array = temparray;
    length=SIZE;
}
template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::begin(){ //returns the beggining iterator of erray.
    return GTUIterator<T>(array.get());
 }
 
template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::end(){ //return pointer + length. to give end of the array.
    return GTUIterator<T>(array.get()+length);
 }

 template<class T,int SIZE>
void GTUArray<T,SIZE>::add(T value){
int j=0;
shared_ptr<T> temp(new T[length+1], std::default_delete<T[]>()); //create shared temp pointer .

for(auto i=0;i<length;i++){ //assign array variables to temp 
    temp.get()[i]=array.get()[i];
}

array=nullptr; //free array pointer .
length++; //incement length variable.

array=temp; //assign temp pointer points the same adress.
/*for(auto i=0;i<length;i++){
    vec[i]=temp[i];
}*/
array.get()[length-1]=value; //add the value to last block of array.

/*delete temp;
temp=nullptr;*/
}

template<class T,int SIZE>
bool GTUArray<T,SIZE>::empty(){ //returns true if the length equal to zero.
    if(length>0)
    return false;
    else
    return true;
}
template<class T,int SIZE>
 int GTUArray<T,SIZE>::size(){
    return length;
 }
template<class T,int SIZE>
 GTUIteratorConst<T> GTUArray<T,SIZE>::cend() const{
    return GTUIteratorConst<T>(array.get() + length);
 }
template<class T,int SIZE>
 void GTUArray<T,SIZE>::clear(){ //create a shared pointer with same type of array pointer as default .assign it to array and reset length.
    array=nullptr;
    shared_ptr<T> temparray(new T[0], std::default_delete<T[]>());
    array = temparray;
    length=0;
    cout<<endl<<"the array cleared"<<endl;
 }

 template<class T,int SIZE>
 void GTUArray<T,SIZE>::erase(GTUIterator<T> iter){ //takes an iterator as parametre
  int index=0;
   shared_ptr<T> temp(new T[length-1], std::default_delete<T[]>()); //create temp shared pointer.
  
  

  for(auto it=this->begin();it!=this->end();it++){
     
      if(it.getpit()==iter.getpit()){
        
          for (int i=index;i<length;i++) //find the index to be erased and assign all the values by next pointer of it until the end
            {
                
                array.get()[i]=array.get()[i+1];
            }
      }
   index++;
  }
  length--;
for(int i=0;i<length;i++){ //assign all the values from array to temp
    temp.get()[i]=array.get()[i];
    
}
array=nullptr; //free array and assign temp.
array=temp;

 }
}
#endif 