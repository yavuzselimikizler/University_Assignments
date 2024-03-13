
#include <iostream>




namespace my_namespace{
    template<class T>

class Iterable{

public:

virtual void empty()=0;

virtual void erase()=0;

virtual void size()=0;

virtual void cend()=0;

virtual void clear()=0;

virtual void begin()=0;

virtual void end()=0;








protected:


T *a;





};



}