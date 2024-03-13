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

 virtual void erase(T position)=0;

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
 //GTUVector(int );
 bool empty();

 void erase(T position);

 const T & operator[](const int  index) ;
 
 void add(T value);

 int size();

 GTUIteratorConst<T> cend() const;

 void clear();

 GTUIterator<T> begin();

 GTUIterator<T> end();
 
 ~GTUVector(){

     delete [] vec;
 }
private:
    
    
    T* vec;
    int length;



};
template<class T>
class GTUSet: public Iterable<T> {


public:
GTUSet();

 bool empty();

 void erase(T position);

 int size();

 GTUIteratorConst<T> cend() const;

 void clear();

 GTUIterator<T> begin();

 GTUIterator<T> end();


private:
    
    T* set1;
    T* iterator;
    int length;


};

template<class T,int SIZE>
class GTUArray: public Iterable<T> {


public:

 GTUArray( );
 GTUArray(GTUArray && an );
 bool empty();

 void erase(T position);

 int size();

 GTUIteratorConst<T> cend() const;

 void clear();

 GTUIterator<T> begin();

 GTUIterator<T> end();
 
 void add(T value);

private:
    
    T* array;
    int length;
};

template<class T>
Iterable<T>::Iterable(int siz ){
 capacity=siz;
}

template<typename T>
GTUVector<T>::GTUVector()
                                   :Iterable<T>(0) {

    vec=new T(0);
    length=0;
}

template<typename T>
GTUSet<T>::GTUSet()
                                   :Iterable<T>(0) {

    set1=new T(0);
    length=0;
}

template<class T,int SIZE>
GTUArray<T,SIZE>::GTUArray()
                                   :Iterable<T>(SIZE) {

    array=new T(SIZE);
    length=SIZE;
}
template<class T,int SIZE>
GTUArray<T,SIZE>::GTUArray(GTUArray && ana)
                         :Iterable<T>(ana.length)
                                    {
    length=ana.length;
    array=ana.array;
    ana.array=nullptr;
}
/*GTUVector::<T>GTUVector(int len)
                                   :Iterable<T>(len) {

   
}*/
template<class T,int SIZE>
void GTUArray<T,SIZE>::add(T value){
int j=0;
T *temp=new T(length);

for(auto i=0;i<length;i++){
    temp[i]=array[i];
}
delete [] array;
length++;

array=new T(length);
for(auto i=0;i<length;i++){
    array[i]=temp[i];
}
array[length-1]=value;

delete [] temp;
}

template<class T,int SIZE>
bool GTUArray<T,SIZE>::empty(){
    if(length>0)
    return false;
    else
    return true;
}
template<class T,int SIZE>
 void GTUArray<T,SIZE>::erase(T position){
   T *temp=new T(length);

for(int i=0;i<length;i++){
    temp[i]=array[i];
    
}
delete [] array;
length--;

array=new T(length);

for(int i=0;i<position;i++){
    array[i]=temp[i];
    
}
for(auto i=position;i<length;i++){
    array[i]=temp[i+1];
}


delete [] temp;
 }
template<class T,int SIZE>
 int GTUArray<T,SIZE>::size(){
    return length;
 }
template<class T,int SIZE>
 GTUIteratorConst<T> GTUArray<T,SIZE>::cend() const{
   
    return GTUIteratorConst<T>(array+length);
 }
template<class T,int SIZE>
 void GTUArray<T,SIZE>::clear(){
  array=new T(0);
  length=0;

 }
template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::begin(){
    return GTUIterator<T>(array);
 }
template<class T,int SIZE>
 GTUIterator<T> GTUArray<T,SIZE>::end(){
    return GTUIterator<T>(array+length);
 }

template<class T>
bool GTUSet<T>::empty(){
    if(length>0)
        return false;
    
    else return true;
}
template<class T>
void GTUSet<T>::erase(T position){
     T *temp=new T(length);

for(int i=0;i<length;i++){
    temp[i]=set1[i];
    
}
delete [] set1;
length--;

set1=new T(length);

for(int i=0;i<position;i++){
    set1[i]=temp[i];
    
}
for(auto i=position;i<length;i++){
    set1[i]=temp[i+1];
}


delete [] temp;
 }
template<class T>
 int GTUSet<T>::size(){
    return length;
 }
template<class T>
 GTUIteratorConst<T> GTUSet<T>::cend() const{
    return GTUIteratorConst<T>(set1 +length);
 }
template<class T>
 void GTUSet<T>::clear(){
    for(int i=0;i<length;i++){
        set1[i].~T();
    }
    length=0;
 }
template<class T>
 GTUIterator<T> GTUSet<T>::begin(){
     return GTUIterator<T>(set1);
 }
template<class T>
 GTUIterator<T> GTUSet<T>::end(){
    return GTUIterator<T>(set1 +length);
 }

 template<class T>
const T & GTUVector<T>::operator[](const int  index) {

    if(index>=length){

        cout<<"invalid index"<<endl;
        exit(1) ;
    }
   
   return vec[index];

}

template<class T>
void GTUVector<T>::add(T value){
int j=0;
T *temp=new T(length);

for(auto i=0;i<length;i++){
    temp[i]=vec[i];
}
delete [] vec;
length++;

vec=new T(length);
for(auto i=0;i<length;i++){
    vec[i]=temp[i];
}
vec[length-1]=value;

delete [] temp;
}


template<class T>
bool GTUVector<T>::empty(){
    if(length>0)
    return false;
    else
    return true;
}
template<class T>
 void GTUVector<T>::erase(T position){
   T *temp=new T(length);

for(int i=0;i<length;i++){
    temp[i]=vec[i];
    
}
delete [] vec;
length--;

vec=new T(length);

for(int i=0;i<position;i++){
    vec[i]=temp[i];
    
}
for(auto i=position;i<length;i++){
    vec[i]=temp[i+1];
}


delete [] temp;
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
 }
template<class T>
 GTUIterator<T> GTUVector<T>::begin(){
    return GTUIterator<T>(vec);
 }
template<class T>
 GTUIterator<T> GTUVector<T>::end(){
    return GTUIterator<T>(vec+length);
 }

int main(){
 int n_size=10;
 //int arr[5];
  GTUArray<int,(int)5> a;
  GTUVector<int> b;
  
  b.add(20);
  b.add(11);
  
  cout<<b.empty()<<endl;
 //shared_ptr<Iterable<int>> b=a;
 GTUArray<int,5> c(move(a));
 cout<<c.size()<<endl;
 cout<<c.empty()<<endl;
 //cout<<b.size()<<endl;
 for (auto it = b.begin(), end = b.end(); it != end; ++it) { 
     
   cout << "5" << "\n";
}
 
 c.add(20);
 //a.clear();
 cout<<c.empty()<<endl;
 cout<<endl;
/*for(auto i=c.begin();i!=c.end();i++){
     cout<<5<<endl;
 }*/

 c.erase(4);
 cout<<endl;
/* for(auto i=c.begin();i!=c.end();i++){
     cout<<5<<endl;
 }*/
    return 0;
}