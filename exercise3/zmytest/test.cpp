
#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>   
#include <time.h>       
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>  

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytestHashTableInteger(){
  try{
    cout << endl << "Begin HashTable for Integer" << endl;
    cout << endl << "Begin HashTableClAdr for Integer" << endl;

    lasd::Vector<int> vec(127);
    for (uint i = 0; i < 127; i++) {
      vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
    }

    lasd::Vector<int> vec2(53);
    for (uint i = 0; i < 53; i++) {
      vec[i] = i;
    }

    lasd::HashTableClsAdr<int> hashTableClAdr(83, vec);
    cout << endl << "The size is: " << hashTableClAdr.Size() << endl;
    hashTableClAdr.Clear();
    if(hashTableClAdr.Empty()){
      cout << "HashTable is Empty " << endl;
    } else{
      cout << "HashTable is NOT Empty " << endl;
    }
    cout << "The size is: " << hashTableClAdr.Size() << endl;
    hashTableClAdr.InsertAll(vec2);
    if(hashTableClAdr.Empty()){
      cout << "HashTable is Empty " << endl;
    } else{
      cout << "HashTable is NOT Empty " << endl;
    }
    cout << "The size is: " << hashTableClAdr.Size() << endl;


  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For Integer!" << endl;
}

void mytestHashTableFloat(){
  try{

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For Integer!" << endl;
}

void mytestHashTableString(){
  try{

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For Integer!" << endl;
}

void mytest() {
  mytestHashTableInteger();
}
