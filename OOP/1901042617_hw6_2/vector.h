#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>
#include "iterable.h"
using namespace std;
#ifndef VEC_H
#define VEC_H
namespace my_namespace{



template<class T>
class GTUVector: public Iterable<T> {


public:

 GTUVector();
 GTUVector(GTUVector&&);
 //GTUVector(int );
 bool empty();

 void erase(GTUIterator<T> );
/*
*/ const T & operator[](const int  index) ;
 
 void add(T value);

 int size();

 GTUIteratorConst<T> cend() const;

 void clear();

 GTUIterator<T> begin();

 GTUIterator<T> end();
 
 /*~GTUVector(){

     delete [] vec;
 }*/
private:
    
    
    shared_ptr<T> vec;
    int length;



};


template<class T>
GTUVector<T>::GTUVector(GTUVector && ana)
                         :Iterable<T>(ana.length) //all the algorithm same as array.
                                    {
    length=ana.length;
    vec=ana.vec;
    ana.vec=nullptr;
    cout<<"moved"<<endl;
}


template<typename T>
GTUVector<T>::GTUVector()
                                   :Iterable<T>(0) {

    
    shared_ptr<T> tempvec(new T[0], std::default_delete<T[]>());
    vec = tempvec;
    length=0;
}

template<class T>
const T & GTUVector<T>::operator[](const int  index) {//if the index valid returns the value pointed by shared pointer.

    if(index>=length || index<0){

        cout<<"invalid index"<<endl;
        exit(1) ;
    }
   cout<<index<<"th index value: ";
   return vec.get()[index];

}

template<class T>
void GTUVector<T>::add(T value){
int j=0;
shared_ptr<T> temp(new T[length+1], std::default_delete<T[]>());

for(auto i=0;i<length;i++){
    temp.get()[i]=vec.get()[i];
}

vec=nullptr;
length++;

vec=temp;
/*for(auto i=0;i<length;i++){
    vec[i]=temp[i];
}*/
vec.get()[length-1]=value;

/*delete temp;
temp=nullptr;*/
}


template<class T>
bool GTUVector<T>::empty(){
    if(length>0)
    return false;
    else
    return true;
}
template<class T>
 int GTUVector<T>::size(){
    return length;
 }
template<class T>
 GTUIteratorConst<T> GTUVector<T>::cend() const{
    return GTUIteratorConst<T>(vec.get() + length);
 }
template<class T>
 void GTUVector<T>::clear(){
    vec=nullptr;
    shared_ptr<T> tempvec(new T[0], std::default_delete<T[]>());
    vec = tempvec;
    length=0;
    cout<<endl<<"the vector cleared"<<endl;
 }

template<class T>
 void GTUVector<T>::erase(GTUIterator<T> iter){
  int index=0;
   shared_ptr<T> temp(new T[length-1], std::default_delete<T[]>());
  
  

  for(auto it=this->begin();it!=this->end();it++){
     
      if(it.getpit()==iter.getpit()){
        
          for (int i=index;i<length;i++)
            {
                
                vec.get()[i]=vec.get()[i+1];
            }
      }
   index++;
  }
  length--;
for(int i=0;i<length;i++){
    temp.get()[i]=vec.get()[i];
    
}
vec=nullptr;
vec=temp;



 
/*for(auto j=position;j<length;j++){
		vec[j]=vec[j+1];
	}
	if(position<length){
	vec[length].~T();
	length--;
 }
 }
template<class T>
 int GTUVector<T>::size(){
    return length;
 }
template<class T>
 GTUIteratorConst<T> GTUVector<T>::cend() const{
    return GTUIteratorConst<T>(vec + length);
 }
template<class T>
 void GTUVector<T>::clear(){
    for(int i=0;i<length;i++){
        vec[i].~T();
    }
    length=0;
 }*/
 }
template<class T>
 GTUIterator<T> GTUVector<T>::begin(){
    return GTUIterator<T>(vec.get());
 }
 
template<class T>
 GTUIterator<T> GTUVector<T>::end(){
    return GTUIterator<T>(vec.get()+length);
 }
}
#endif 