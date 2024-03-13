#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <memory>
#include <cstddef>
#include "iterable.h"
using namespace std;

namespace my_namespace{



template<typename T>
Iterable<T>::Iterable(int siz ){
 capacity=siz;
}

}