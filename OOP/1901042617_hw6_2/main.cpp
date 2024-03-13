#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>

#include "set.h"

#include "array.h"
#include "vector.h"


using namespace std;
using namespace my_namespace;

template<typename T>
void print (T p) {  
  cout << p << ' ' ;
}
 
 
 
 
 
 
 template <typename T>
GTUIterator<T> find(GTUIterator<T> begin, GTUIterator<T> end, T val){
    for (auto it = begin; it != end; it++)
    {
        if(*it == val){
            return it;
        }
    }
    return end;
}


 
 
 template <typename T>
void for_each(GTUIterator<T> begin, GTUIterator<T> end, void (*f)(T)){
    
    for (auto it = begin; it != end; it++)
    {
        (*f)(*it);
    }
   
}
 
 
 
 template <typename T>
void sort(GTUIterator<T> begin, GTUIterator<T> end){
    for(auto it = begin; it!=end; it++) {
   for(auto it2 = it; it2!=end; it2++)
   {
      if(*it > *it2) {
        auto temp = *it;
         *it = *it2;
         *it2 = temp;
      }
      
   }
}
cout<<endl<<"sorted"<<endl;
}

int main(){

 GTUSet<int> a;
 GTUSet<int> b;
 
 
 
 cout<<".................SET.................\n"<<endl;

 if(b.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 b.insert(61);
 b.insert(30);
 b.insert(30);
 b.insert(15);
 if(b.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 for(auto it=b.begin();it!=b.end();it++){
     cout<<*it<<" ";
 }

 cout<<"sizeof set: "<<b.size()<<endl;
 cout<<"  inserted sorted"<<endl;
 GTUIterator<int> iter=a.begin();
 iter++;
 b.erase(iter);

 for(auto it=b.begin();it!=b.end();it++){
     cout<<*it<<" ";
 }
 cout<<"  erased sorted"<<endl;

 /*
 d.add(21);
 d.add(15);
 d.add(31);
 d.add(1);*/
 
 a.insert(12);
 a.insert(21);
 cout<<endl;
 for(auto it=a.begin();it!=a.end();it++){
     cout<<*it<<" ";
 }
 a.clear();
 cout<<"..clear.."<<endl;
 for(auto it=a.begin();it!=a.end();it++){
     cout<<*it<<" ";
 }
 a.insert(30);
 a.insert(25);
 a.insert(23);

 cout<<endl;
 cout<<"after iserted some values"<<endl;
 for(auto it=a.begin();it!=a.end();it++){
     cout<<*it<<" ";
 }
 cout<<endl<<"test find for a object"<<endl;
 a.insert(15);
 auto sth=a.find(25);
  for(auto it=sth;it!=a.end();it++){
     cout<<*it<<endl;
 }

 cout<<"move"<<endl;
 GTUSet<int>c(move(a));
cout<<endl<<"c: ";
 for(auto it=c.begin();it!=c.end();it++){
     cout<<*it<<" ";
 }
cout<<endl<<"b: ";
for(auto it=b.begin();it!=b.end();it++){
     cout<<*it<<" ";
 }
GTUSet<int> g=c.intersect(b);
cout<<endl<<"intersect c with b"<<endl;
for(auto it=g.begin();it!=g.end();it++){
     cout<<*it<<" ";
 }
 c.union_s(b);
 cout<<endl<<"union c with b"<<endl;
 for(auto it=c.begin();it!=c.end();it++){
     cout<<*it<<" ";
 }
 cout<<endl;

 cout<<"...............VECTOR..............."<<endl;
 GTUVector<int> d;
 
 if(d.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 
 cout<<endl<<"after the add functions"<<endl;
 d.add(10); 
 d.add(1);
 d.add(34);

 if(d.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 
 for(auto it=d.begin();it!=d.end();it++){
     cout<<*it<<" ";
 }

 GTUIterator<int> iter2=d.begin();
 iter2++;
 iter2++;
 cout<<endl<<"3th element erased"<<endl;
 d.erase(iter2);

 for(auto it=d.begin();it!=d.end();it++){
     cout<<*it<<" ";
 }

 cout<<endl<<"size:"<<d.size()<<endl;

 d.clear();
 
 for(auto it=d.begin();it!=d.end();it++){
     cout<<*it<<" ";
 }
 
 d.add(23); 
 d.add(11);
 d.add(38);
 
 cout<<endl<<d[2]<<endl;

 cout<<endl<<"........................ARRAY......................."<<endl;
 
 GTUArray<int,0> e;

 if(e.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 
 cout<<endl<<"after the add functions"<<endl;
 e.add(100); 
 e.add(10);
 e.add(12);
 e.add(99);
 if(e.empty()==1){
     cout<<"set is empty"<<endl;
 }
 else{
     cout<<"not empty"<<endl;
 }
 
 for(auto it=e.begin();it!=e.end();it++){
     cout<<*it<<" ";
 }

 GTUIterator<int> iter3=e.begin();
 iter3++;
 
 cout<<endl<<"2th element erased"<<endl;
 e.erase(iter3);

 for(auto it=e.begin();it!=e.end();it++){
     cout<<*it<<" ";
 }

 cout<<endl<<"size:"<<e.size()<<endl;

 e.clear();
 
 for(auto it=e.begin();it!=e.end();it++){
     cout<<*it<<" ";
 }

   /*for_each(b.begin(),b.end(),print);
   sort(d.begin(),d.end());
   cout<<endl;
   for_each(d.begin(),d.end(),print);*/
 //cout<<c[2];

 cout<<endl<<"size:"<<e.size()<<endl;

 cout<<endl<<"................sor,for_each,find................."<<endl;
 
 for(auto it=d.begin();it!=d.end();it++){
     cout<<*it<<" ";
 }
 sort(d.begin(),d.end());
for(auto it=d.begin();it!=d.end();it++){
     cout<<*it<<" ";
 }

 cout<<endl<<"for each:"<<endl;
 for_each(d.begin(),d.end(),print);

 cout<<endl<<"test find for a object"<<endl;
 
 auto sth2=find(d.begin(),d.end(),23);
  for(auto it=sth2;it!=d.end();it++){
     cout<<*it<<endl;
 }

 cout<<endl<<"for vector"<<endl;
 GTUVector<int> l(move(d));
 for(auto it=l.begin();it!=l.end();it++){
     cout<<*it<<" ";
 }
 cout<<endl<<"for array"<<endl;
 e.add(11);
 e.add(12);
 e.add(13);
 e.add(14);
 e.add(15);
 cout<<endl<<"new e after some add functions"<<endl;
 for(auto it=e.begin();it!=e.end();it++){
     cout<<*it<<" ";
 }
 
 GTUArray<int,0> m(move(e));
cout<<endl;
 for(auto it=m.begin();it!=m.end();it++){
     cout<<*it<<" ";
 }
 cout<<endl;
    return 0;
}