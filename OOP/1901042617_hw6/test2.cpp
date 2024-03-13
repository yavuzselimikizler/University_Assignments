
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

 virtual void erase(int position)=0;

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

 void erase(int position);

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
GTUSet(T *,int);
 GTUSet<T> intersect(GTUSet<T> & second);
 bool empty();

 void erase(int position);

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
  return set1[index];
 }

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

 void erase(int position);

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
template<typename T>
GTUSet<T>::GTUSet(T* temp_arr,int size):Iterable<T>(size){
    set1= new T[size];
    length=size;

    for(int i=0;i<size;i++){
        set1[i]=temp_arr[i];
    }
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
T *temp=new T[length];

for(auto i=0;i<length;i++){
    temp[i]=array[i];
}
delete array;
array=nullptr;
length++;

array=new T[length];
for(auto i=0;i<length;i++){
    array[i]=temp[i];
}
array[length-1]=value;

delete temp;
temp=nullptr;

}

template<class T,int SIZE>
bool GTUArray<T,SIZE>::empty(){
    if(length>0)
    return false;
    else
    return true;
}
template<class T,int SIZE>
 void GTUArray<T,SIZE>::erase(int position){
/*   T *temp=new T(length);

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


delete [] temp;*/
for(auto j=position;j<length;j++){
		array[j]=array[j+1];
	}
	if(position<length){
	array[length].~T();
	length--;
 }
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
                                   //...............SET...........


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

template<class T>
  void  GTUSet<T>::union_s(GTUSet<T> &second){
     
    for(int i=0;i<second.size();i++){
        this->insert(second.get_set(i));
    }

 }  

template<class T>
bool GTUSet<T>::empty(){
    if(length>0)
        return false;
    
    else return true;
}
template<class T>
void GTUSet<T>::erase(int position){
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
GTUIterator<T> GTUSet<T>::find(T value) {
    
    for(int i=0;i<length;i++){
        cout<<" ee"<<endl;
        if(set1[i]==value){
            return GTUIterator<T>(set1 + i);
            
        }
    }
    
    return GTUIterator<T>(set1 +length);
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
 void GTUSet<T>::insert(T value){
  
  T min;
  T temp_value;

T *temp=new T[length];

for(int i=0;i<length;i++){
    if(value==set1[i]){
        return;
    }
}


for(auto i=0;i<length;i++){
    temp[i]=set1[i];
}
delete set1;
set1=nullptr;
length++;

set1=new T[length];
for(auto i=0;i<length;i++){
    set1[i]=temp[i];
}
set1[length-1]=value;

for(int i=0;i<length-1;i++){
  
  for(int j=0;j<length-1-i;j++){
   if(set1[j]>set1[j+1]){
   temp_value=set1[j+1];
   set1[j+1]=set1[j];
   set1[j]=temp_value;
   }
  }

  }
    


delete temp;
temp=nullptr;

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
T *temp=new T[length];

for(auto i=0;i<length;i++){
    temp[i]=vec[i];
}
delete vec;
vec=nullptr;
length++;

vec=new T[length];
for(auto i=0;i<length;i++){
    vec[i]=temp[i];
}
vec[length-1]=value;

delete temp;
temp=nullptr;
}


template<class T>
bool GTUVector<T>::empty(){
    if(length>0)
    return false;
    else
    return true;
}
template<class T>
 void GTUVector<T>::erase(int position){
 /*  T *temp=new T(length);

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


delete [] temp;    */
for(auto j=position;j<length;j++){
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
 }
template<class T>
 GTUIterator<T> GTUVector<T>::begin(){
    return GTUIterator<T>(vec);
 }
template<class T>
 GTUIterator<T> GTUVector<T>::end(){
    return GTUIterator<T>(vec+length);
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
 
 template <typename T>
void printVector(GTUVector<T> &vectorForInt)
{
    for (auto iter = vectorForInt.begin(); iter != vectorForInt.end(); ++iter)
    {
    cout << *iter << " ";
    }
}
 

int main(){
 int n_size=10;
 
 //int arr[5];
  GTUArray<int,0> a;
  GTUVector<int> b;
  GTUSet<int> e,f;
  b.add(20);
  b.add(5);
  b.add(11);
  b.add(19);
  b.add(1);
  //printVector(b);
  e.insert(20);
  e.insert(32);
  e.insert(2);
  e.insert(5);
  f.insert(2);
  f.insert(10);
  f.insert(15);
  //e.union_s(f);
  
  GTUSet<int> g=e.intersect(f);
  
  //auto sth=e.find(5);
  for(auto it=g.begin();it!=g.end();it++){

      cout<<*it<<" ";
  }
  cout<<endl;
  for_each(b.begin(),b.end(),print);
  sort(b.begin(),b.end());
  for_each(b.begin(),b.end(),print);
 // cout<<endl<<b.empty()<<endl;
 //cout<<endl<<"the number in "<<find(b.begin(),b.end(),11)<<"th index"<<endl;
 //shared_ptr<Iterable<int>> b=a;
 GTUArray<int,0> c(move(a));
 //cout<<c.size()<<endl;
 //cout<<c.empty()<<endl;
 //cout<<b.size()<<endl;
 for (auto it = b.begin(), end = b.end(); it != end; ++it) { 
     
   cout << *it << "\n";
}
 /* for (auto it = e.begin(), end = e.end(); it != end; ++it) { 
     
   cout << *it << "\n";
}*/
 /*c.add(20);
 //a.clear();
 cout<<c.empty()<<endl;
 cout<<endl;
/*for(auto i=c.begin();i!=c.end();i++){
     cout<<5<<endl;
 }

 c.erase(4);
 cout<<endl;*/
 
/* for(auto i=c.begin();i!=c.end();i++){
     cout<<5<<endl;
 }*/
    return 0;
}