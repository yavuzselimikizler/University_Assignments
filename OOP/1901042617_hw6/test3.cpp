#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>





using namespace std;


template <class T>
class GTUIterator
{
public:
    GTUIterator(T *ptr) : ptr_(ptr) {}
    GTUIterator operator++()
    {
        GTUIterator i = *this;
        ptr_++;
        return i;
    }
    GTUIterator operator++(int junk)
    {
        ptr_++;
        return *this;
    }
    GTUIterator operator--()
    {
        GTUIterator i = *this;
        ptr_--;
        return i;
    }
    GTUIterator operator--(int junk)
    {
        ptr_--;
        return *this;
    }
    T &operator*() { return *ptr_; }
    T *operator->() { return ptr_; }
    bool operator==(const GTUIterator &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const GTUIterator &rhs) { return ptr_ != rhs.ptr_; }
    T *getPtr_() const noexcept
    {
        return ptr_;
    }

protected:
    T *ptr_;
};

template <class T>
class GTUIteratorConst
{
public:
    GTUIteratorConst(T *ptr) : ptr_(ptr) {}
    GTUIteratorConst operator++()
    {
        GTUIteratorConst i = *this;
        ptr_++;
        return i;
    }
    GTUIteratorConst operator++(int junk)
    {
        ptr_++;
        return *this;
    }
    GTUIteratorConst operator--()
    {
        GTUIteratorConst i = *this;
        ptr_--;
        return i;
    }
    GTUIteratorConst operator--(int junk)
    {
        ptr_--;
        return *this;
    }
    const T &operator*() { return *ptr_; }
    const T *operator->() { return ptr_; }
    bool operator==(const GTUIteratorConst &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const GTUIteratorConst &rhs) { return ptr_ != rhs.ptr_; }
    const T *getPtr_() const noexcept
    {
        return ptr_;
    }

private:
    T *ptr_;
};



template<class T>
class Iterable{
 
 
 
 public:
 
 Iterable(int );
 


 






 virtual bool empty()=0;

 virtual void erase(GTUIterator<T> )=0;

 virtual int size()=0;

 virtual GTUIteratorConst<T> cend() const=0;

 virtual void clear()=0;

 virtual GTUIterator<T> begin()=0;

 virtual GTUIterator<T> end()=0;








 protected:

 T capacity;
 

};


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
GTUArray<T,SIZE>::GTUArray(GTUArray && ana)
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    array=ana.array;
    ana.array=nullptr;
}

template<typename T,int SIZE>
GTUArray<T,SIZE>::GTUArray()
                                   :Iterable<T>(0) {

    
    shared_ptr<T> temparray(new T[SIZE], std::default_delete<T[]>());
    array = temparray;
    length=SIZE;
}

template<class T>
GTUVector<T>::GTUVector(GTUVector && ana)
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    vec=ana.vec;
    ana.vec=nullptr;
}

template<class T>
GTUSet<T>::GTUSet(GTUSet && ana)
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    set1=ana.set1;
    ana.set1=nullptr;
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

template<typename T>
Iterable<T>::Iterable(int siz ){
 capacity=siz;
}

template<typename T>
GTUVector<T>::GTUVector()
                                   :Iterable<T>(0) {

    
    shared_ptr<T> tempvec(new T[0], std::default_delete<T[]>());
    vec = tempvec;
    length=0;
}



 //......................................VECTOR..........................................

template<class T>
const T & GTUVector<T>::operator[](const int  index) {

    if(index>=length || index<0){

        cout<<"invalid index"<<endl;
        exit(1) ;
    }
   
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
 }

template<class T>
 void GTUVector<T>::erase(GTUIterator<T> iter){
  int index=0;
   shared_ptr<T> temp(new T[length-1], std::default_delete<T[]>());
  
  

  for(auto it=this->begin();it!=this->end();it++){
     
      if(it.getPtr_()==iter.getPtr_()){
        
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

//....................................................ARRAY.........................................
 template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::begin(){
    return GTUIterator<T>(array.get());
 }
 
template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::end(){
    return GTUIterator<T>(array.get()+length);
 }

 template<class T,int SIZE>
void GTUArray<T,SIZE>::add(T value){
int j=0;
shared_ptr<T> temp(new T[length+1], std::default_delete<T[]>());

for(auto i=0;i<length;i++){
    temp.get()[i]=array.get()[i];
}

array=nullptr;
length++;

array=temp;
/*for(auto i=0;i<length;i++){
    vec[i]=temp[i];
}*/
array.get()[length-1]=value;

/*delete temp;
temp=nullptr;*/
}

template<class T,int SIZE>
bool GTUArray<T,SIZE>::empty(){
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
 void GTUArray<T,SIZE>::clear(){
    array=nullptr;
    shared_ptr<T> temparray(new T[0], std::default_delete<T[]>());
    array = temparray;
    length=0;
 }

 template<class T,int SIZE>
 void GTUArray<T,SIZE>::erase(GTUIterator<T> iter){
  int index=0;
   shared_ptr<T> temp(new T[length-1], std::default_delete<T[]>());
  
  

  for(auto it=this->begin();it!=this->end();it++){
     
      if(it.getPtr_()==iter.getPtr_()){
        
          for (int i=index;i<length;i++)
            {
                
                array.get()[i]=array.get()[i+1];
            }
      }
   index++;
  }
  length--;
for(int i=0;i<length;i++){
    temp.get()[i]=array.get()[i];
    
}
array=nullptr;
array=temp;

 }
 //........................................SET...............................
 

 template<class T>
 void GTUSet<T>::clear(){
    set1=nullptr;
    shared_ptr<T> tempset1(new T[0], std::default_delete<T[]>());
    set1 = tempset1;
    length=0;
 }

 template<class T>
bool GTUSet<T>::empty(){
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
     
      if(it.getPtr_()==iter.getPtr_()){
        
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

for(int i=0;i<length;i++){
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

for(int i=0;i<length-1;i++){
  
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
GTUIterator<T> GTUSet<T>::find(T value) {
    
    for(int i=0;i<length;i++){
        
        if(set1.get()[i]==value){
            return GTUIterator<T>(set1.get() + i);
            
        }
    }
    
    return GTUIterator<T>(set1.get() +length);
 }

 template<class T>
  void  GTUSet<T>::union_s(GTUSet<T> &second){
     
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

            if(this->get_set(i)==second.get_set(j)){
                element_counter++;
            
            }
        }
    }
    
    temp_arr=new T[element_counter];
     
     for(int i=0;i<this->get_length();i++){

        for(int j=0;j<second.get_length();j++){

            if(this->get_set(i)==second.get_set(j)){
                temp_arr[index_number]=this->get_set(i);
                index_number++;
            
            }
        }
    }
 return GTUSet<T>(temp_arr,index_number);

}


template<typename T>
void print (T i) {  
  std::cout << i << ' ' ;
}
 
 
 
 
 
 
 template <typename T>
GTUIterator<T> find(GTUIterator<T> begin, GTUIterator<T> end, T value){
    for (auto i = begin; i != end; i++)
    {
        if(*i == value){
            return i;
        }
    }
    return end;
}


 
 
 template <typename T>
void for_each(GTUIterator<T> begin, GTUIterator<T> end, void (*f)(T)){
    
    for (auto i = begin; i != end; i++)
    {
        (*f)(*i);
    }
   
}
 
 
 
 template <typename T>
void sort(GTUIterator<T> begin, GTUIterator<T> end){
    for(auto i = begin; i!=end; i++) {
   for(auto j = i; j!=end; j++)
   {
      if(*i > *j) {
        auto temp = *i;
         *i = *j;
         *j = temp;
      }
      
   }
}
}

int main(){

 GTUSet<int> a;
 GTUSet<int> b;
 GTUVector<int> d;
 b.insert(61);
 b.insert(31);
 b.insert(31);
 b.insert(15);
 
 
 d.add(21);
 d.add(15);
 d.add(31);
 d.add(1);
 
 a.insert(12);
 a.insert(21);
 a.clear();
 a.insert(30);
 a.insert(31);
 a.insert(23);

 GTUIterator<int> iter=a.begin();
 iter++;
 a.erase(iter);
 a.insert(15);
 auto sth=a.find(31);
 GTUSet<int>c(move(a));
 //c.union_s(b);
 GTUSet<int> g=c.intersect(b);
 for(auto it=g.begin();it!=g.end();it++){
     cout<<*it<<endl;
 }
 
   for_each(b.begin(),b.end(),print);
   sort(d.begin(),d.end());
   cout<<endl;
   for_each(d.begin(),d.end(),print);
 //cout<<c[2];

 GTUIterator<int> biter=find(d.begin(),d.end(),31);
 cout<<*biter<<endl;


    return 0;
}