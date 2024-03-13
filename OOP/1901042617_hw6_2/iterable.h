
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>
#ifndef IT_H
#define IT_H
using namespace std;

namespace my_namespace{
template <class T>
class GTUIterator
{
public:
    GTUIterator(T *tpoint) : pit(tpoint) {} //Iterator class.
    GTUIterator operator++()
    {
        GTUIterator it = *this;
        pit++;
        return it;
    }
    GTUIterator operator++(int sth)
    {
        pit++;
        return *this;
    }
    GTUIterator operator--()
    {
        GTUIterator it = *this;
        pit--;
        return it;
    }
    GTUIterator operator--(int sth)
    {
        pit--;
        return *this;
    }
    T &operator*() { return *pit; }
    T *operator->() { return pit; }
    bool operator==(const GTUIterator &sec) { return pit == sec.pit; }
    bool operator!=(const GTUIterator &sec) { return pit != sec.pit; }
    T *getpit() const noexcept
    {
        return pit;
    }

protected:
    T *pit;
};

template <class T>
class GTUIteratorConst
{
public:
    GTUIteratorConst(T *tpoint) : pit(tpoint) {}
    GTUIteratorConst operator++()
    {
        GTUIteratorConst it = *this;
        pit++;
        return it;
    }
    GTUIteratorConst operator++(int sth)
    {
        pit++;
        return *this;
    }
    GTUIteratorConst operator--()
    {
        GTUIteratorConst it = *this;
        pit--;
        return it;
    }
    GTUIteratorConst operator--(int sth)
    {
        pit--;
        return *this;
    }
   bool operator==(const GTUIteratorConst &sec) { return pit == sec.pit; }
    bool operator!=(const GTUIteratorConst &sec) { return pit != sec.pit; }
   
    const T &operator*() { return *pit; }
    const T *operator->() { return pit; }
    
    const T *getPtr_() const noexcept
    {
        return pit;
    }

private:
    T *pit;
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
template<typename T>
Iterable<T>::Iterable(int siz ){
 capacity=siz;
}




}
#endif