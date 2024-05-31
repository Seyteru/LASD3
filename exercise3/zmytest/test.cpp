
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

std::string characters {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
std::random_device rd;
std::mt19937 generator(rd());
std::string randomString(int length){
  std::string output(characters);
  std::shuffle(output.begin(), output.end(), generator);
  return output.substr(0, length);
}

template <typename Data>
void fill(lasd::Vector<Data> &vec){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < vec.Size(); i++){
    dataRandom = rand() / (100 + 1);
    vec[i] = dataRandom;
  }
}

void fill(lasd::Vector<string> &vec){
  for(ulong i = 0; i < vec.Size(); i++){
    vec[i] = randomString(4);
  }
}

template <typename Data>
void fill(lasd::List<Data> &list, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    list.InsertAtBack(dataRandom);
  }
}

void fill(lasd::List<string> &list, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    list.InsertAtBack(randomString(4));
  }
}

void HashTabEmpty(const lasd::Container &hash, bool test){
  if(hash.Empty()){
    cout << "HashTable is Empty";
  } else{
    cout << "HashTable is NOT Empty";
  }
  if(hash.Empty() == test){
    cout << " CORRECT" << endl;
  } else{
    cout << " NOT CORRECT" << endl;
  }
}

void HashTabSize(const lasd::Container &hash, ulong size){
  cout << "The size is: " << hash.Size();
  if(hash.Size() == size){
    cout << " CORRECT" << endl;
  } else{
    cout << " NOT CORRECT" << endl;
  }
}

template <typename Data>
void HashTabCountElementFromContainer(const lasd::HashTable<Data> &hash, const lasd::TraversableContainer<Data> &con, ulong number) {
  ulong cont = 0;
  try {
    con.Traverse(
      [&hash, &cont](const Data &data){
        if(hash.Exists(data)){
          cont++;
        }
      }
    );
    cout <<"HashTable has " << cont << " elements of the Container";
    if(cont == number){
    cout << " CORRECT" << endl;
  } else{
    cout << " NOT CORRECT" << endl;
  }
  }
  catch (...) {
    cout << "Error" << endl;
  }
}

template <typename HashT>
void HashTabEquals(const HashT &hash1, const HashT &hash2, bool test) {
  try {
    cout << "The two hash tables are ";
    if((hash1 == hash2) == test){
      cout << "Equals" << " CORRECT" << endl;
    } else{
      cout << "NOT Equals" << " NOT CORRECT" << endl;
    }
  }
  catch (...) {
    cout << "Error" << endl;
  }
}

template <typename HashT>
void HashTabNotEquals(const HashT &hash1, const HashT &hash2, bool test) {
  try {
    cout << "The two hash tables are ";
    if((hash1 != hash2) == test){
      cout << "NOT Equals" << " CORRECT" << endl;
    } else{
      cout << "Equals" << " NOT CORRECT" << endl;
    }
  }
  catch (...) {
    cout << "Error" << endl;
  }
}

template <typename Data>
void HashTabExists(const lasd::HashTable<Data> &hash, bool test, const Data &val) {
  if(hash.Exists(val) == test){
    cout << "Data " << val << " Exists" << " CORRECT" << endl;
  } else{
    cout << "Data " << val << " Does NOT Exists" << " NOT CORRECT" << endl;
  }
}

template <typename Data>
void HashTabNotExists(const lasd::HashTable<Data> &hash, bool test, const Data &val) {
  if(!(hash.Exists(val)) == test){
    cout << "Data " << val << " Does NOT Exists" << " CORRECT" << endl;
  } else{
    cout << "Data " << val << " Exists" << " NOT CORRECT" << endl;
  }
}

/* ************************************************************************** */

void mytestHashTableInteger(){
  try{
    cout << endl << "Begin HashTable for String" << endl;
    cout << endl << "Begin HashTableClAdr for String" << endl;

    lasd::Vector<int> vec(135);
    fill(vec);

    lasd::Vector<int> vec2(50);
    fill(vec2);

    lasd::Vector<int> vec3(100);
    fill(vec3);

    lasd::List<int> list1;
    fill(list1, 160);

    lasd::List<int> list2;
    fill(list2, 200);

    lasd::BinaryTreeLnk<int> binaryTreeLnk1(vec);
    lasd::BST<int> bst1(vec2);

    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableClsAdr<int> hashTableClAdrDef;

    HashTabSize(hashTableClAdrDef, 0);
    HashTabEmpty(hashTableClAdrDef, true);
    hashTableClAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableClAdrDef, false);
    HashTabSize(hashTableClAdrDef, 200);
    HashTabCountElementFromContainer(hashTableClAdrDef, list2, 200);
    hashTableClAdrDef.Clear();
    HashTabEmpty(hashTableClAdrDef, true);
    HashTabSize(hashTableClAdrDef, 0);

    cout << endl;

    lasd::HashTableClsAdr<int> hashTableClAdr1(65545);

    HashTabSize(hashTableClAdr1, 0);
    HashTabEmpty(hashTableClAdr1, true);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);
    hashTableClAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableClAdr1, false);
    HashTabSize(hashTableClAdr1, 50);
    HashTabCountElementFromContainer(hashTableClAdr1, bst1, 50);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);

    cout << endl;

    lasd::HashTableClsAdr<int> hashTableClAdr2(vec2);

    HashTabSize(hashTableClAdr2, 50);
    HashTabEmpty(hashTableClAdr2, false);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);
    hashTableClAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableClAdr2, false);
    HashTabSize(hashTableClAdr2, 135);
    HashTabCountElementFromContainer(hashTableClAdr2, binaryTreeLnk1, 135);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);

    cout << endl;

    lasd::HashTableClsAdr<int> hashTableClAdr3(90, vec2);

    HashTabSize(hashTableClAdr3, 50);
    HashTabEmpty(hashTableClAdr3, false);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);
    hashTableClAdr3.InsertAll(list2);
    HashTabEmpty(hashTableClAdr3, false);
    HashTabSize(hashTableClAdr3, 200);
    HashTabCountElementFromContainer(hashTableClAdr3, list2, 200);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableClsAdr<int> hashTableCl(vec);
    lasd::HashTableClsAdr<int> copyHashTableCl(hashTableCl);

    HashTabEquals(hashTableCl, copyHashTableCl, true);

    lasd::HashTableClsAdr<int> moveHashTableCl(std::move(hashTableCl));

    HashTabNotEquals(hashTableCl, moveHashTableCl, true);
    HashTabEquals(moveHashTableCl, copyHashTableCl, true);

    hashTableCl = copyHashTableCl;
    HashTabEquals(hashTableCl, copyHashTableCl, true);
    HashTabEquals(hashTableCl, moveHashTableCl, true);

    lasd::HashTableClsAdr<int> hashTableClNew;

    hashTableClNew = std::move(hashTableCl);
    HashTabEquals(hashTableClNew, copyHashTableCl, true);
    HashTabEquals(hashTableClNew, moveHashTableCl, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableCl, 0);
    hashTableCl.Resize(250);
    HashTabSize(hashTableCl, 0);
    hashTableCl.InsertAll(vec);
    HashTabSize(hashTableCl, 135);
    hashTableCl.Resize(64);
    HashTabSize(hashTableCl, 135);
    hashTableCl.RemoveAll(vec);
    HashTabSize(hashTableCl, 0);
    for (int i = 0; i < 100; i++) {
      hashTableCl.Insert(vec3[i]);
    }
    hashTableCl.Insert(1);
    hashTableCl.Insert(2);
    hashTableCl.Insert(3);
    hashTableCl.Insert(4);
    HashTabExists(hashTableCl, true, 1);
    HashTabExists(hashTableCl, true, 2);
    HashTabExists(hashTableCl, true, 3);
    HashTabExists(hashTableCl, true, 4);
    HashTabNotExists(hashTableCl, true, 0);
    HashTabSize(hashTableCl, 104);
    hashTableCl.Remove(1);
    hashTableCl.Remove(2);
    hashTableCl.Remove(3);
    hashTableCl.Remove(4);
    HashTabNotExists(hashTableCl, true, 1);
    HashTabNotExists(hashTableCl, true, 2);
    HashTabNotExists(hashTableCl, true, 3);
    HashTabNotExists(hashTableCl, true, 4);
    HashTabSize(hashTableCl, 100);

    cout << endl << "End HashTableClAdr for String" << endl;
    cout << endl << "Begin HashTableOpnAdr for String" << endl;
    
    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableOpnAdr<int> hashTableOpnAdrDef;

    HashTabSize(hashTableOpnAdrDef, 0);
    HashTabEmpty(hashTableOpnAdrDef, true);
    hashTableOpnAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdrDef, false);
    HashTabSize(hashTableOpnAdrDef, 200);
    HashTabCountElementFromContainer(hashTableOpnAdrDef, list2, 200);
    hashTableOpnAdrDef.Clear();
    HashTabEmpty(hashTableOpnAdrDef, true);
    HashTabSize(hashTableOpnAdrDef, 0);

    cout << endl;

    lasd::HashTableOpnAdr<int> hashTableOpnAdr1(65545);

    HashTabSize(hashTableOpnAdr1, 0);
    HashTabEmpty(hashTableOpnAdr1, true);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);
    hashTableOpnAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableOpnAdr1, false);
    HashTabSize(hashTableOpnAdr1, 50);
    HashTabCountElementFromContainer(hashTableOpnAdr1, bst1, 50);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);

    cout << endl;

    lasd::HashTableOpnAdr<int> hashTableOpnAdr2(vec2);

    HashTabSize(hashTableOpnAdr2, 50);
    HashTabEmpty(hashTableOpnAdr2, false);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);
    hashTableOpnAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableOpnAdr2, false);
    HashTabSize(hashTableOpnAdr2, 135);
    HashTabCountElementFromContainer(hashTableOpnAdr2, binaryTreeLnk1, 135);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);

    cout << endl;

    lasd::HashTableOpnAdr<int> hashTableOpnAdr3(90, vec2);

    HashTabSize(hashTableOpnAdr3, 50);
    HashTabEmpty(hashTableOpnAdr3, false);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);
    hashTableOpnAdr3.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdr3, false);
    HashTabSize(hashTableOpnAdr3, 200);
    HashTabCountElementFromContainer(hashTableOpnAdr3, list2, 200);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableOpnAdr<int> hashTableOpn(vec);
    lasd::HashTableOpnAdr<int> copyHashTableOpn(hashTableOpn);

    HashTabEquals(hashTableOpn, copyHashTableOpn, true);

    lasd::HashTableOpnAdr<int> moveHashTableOpn(std::move(hashTableOpn));

    HashTabNotEquals(hashTableOpn, moveHashTableOpn, true);
    HashTabEquals(moveHashTableOpn, copyHashTableOpn, true);

    hashTableOpn = copyHashTableOpn;
    HashTabEquals(hashTableOpn, copyHashTableOpn, true);
    HashTabEquals(hashTableOpn, moveHashTableOpn, true);

    lasd::HashTableOpnAdr<int> hashTableOpnNew;

    hashTableOpnNew = std::move(hashTableOpn);
    HashTabEquals(hashTableOpnNew, copyHashTableOpn, true);
    HashTabEquals(hashTableOpnNew, moveHashTableOpn, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableOpn, 0);
    hashTableOpn.Resize(250);
    HashTabSize(hashTableOpn, 0);
    hashTableOpn.InsertAll(vec);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.Resize(64);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.RemoveAll(vec);
    HashTabSize(hashTableOpn, 0);
    for (int i = 0; i < 100; i++) {
      hashTableOpn.Insert(vec3[i]);
    }
    hashTableOpn.Insert(1);
    hashTableOpn.Insert(2);
    hashTableOpn.Insert(3);
    hashTableOpn.Insert(4);
    HashTabExists(hashTableOpn, true, 1);
    HashTabExists(hashTableOpn, true, 2);
    HashTabExists(hashTableOpn, true, 3);
    HashTabExists(hashTableOpn, true, 4);
    HashTabNotExists(hashTableOpn, true, 0);
    HashTabSize(hashTableOpn, 104);
    hashTableOpn.Remove(1);
    hashTableOpn.Remove(2);
    hashTableOpn.Remove(3);
    hashTableOpn.Remove(4);
    HashTabNotExists(hashTableOpn, true, 1);
    HashTabNotExists(hashTableOpn, true, 2);
    HashTabNotExists(hashTableOpn, true, 3);
    HashTabNotExists(hashTableOpn, true, 4);
    HashTabSize(hashTableOpn, 100);

    cout << endl << "End HashTableOpnAdr for String" << endl;

  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For String!" << endl;
}

void mytestHashTableDouble(){
  try{
    cout << endl << "Begin HashTable for Double" << endl;
    cout << endl << "Begin HashTableClAdr for Double" << endl;

    lasd::Vector<double> vec(135);
    fill(vec);

    lasd::Vector<double> vec2(50);
    fill(vec2);

    lasd::Vector<double> vec3(100);
    fill(vec3);

    lasd::List<double> list1;
    fill(list1, 160);

    lasd::List<double> list2;
    fill(list2, 200);

    lasd::BinaryTreeLnk<double> binaryTreeLnk1(vec);
    lasd::BST<double> bst1(vec2);

    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableClsAdr<double> hashTableClAdrDef;

    HashTabSize(hashTableClAdrDef, 0);
    HashTabEmpty(hashTableClAdrDef, true);
    hashTableClAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableClAdrDef, false);
    HashTabSize(hashTableClAdrDef, 200);
    HashTabCountElementFromContainer(hashTableClAdrDef, list2, 200);
    hashTableClAdrDef.Clear();
    HashTabEmpty(hashTableClAdrDef, true);
    HashTabSize(hashTableClAdrDef, 0);

    cout << endl;

    lasd::HashTableClsAdr<double> hashTableClAdr1(65545);

    HashTabSize(hashTableClAdr1, 0);
    HashTabEmpty(hashTableClAdr1, true);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);
    hashTableClAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableClAdr1, false);
    HashTabSize(hashTableClAdr1, 50);
    HashTabCountElementFromContainer(hashTableClAdr1, bst1, 50);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);

    cout << endl;

    lasd::HashTableClsAdr<double> hashTableClAdr2(vec2);

    HashTabSize(hashTableClAdr2, 50);
    HashTabEmpty(hashTableClAdr2, false);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);
    hashTableClAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableClAdr2, false);
    HashTabSize(hashTableClAdr2, 135);
    HashTabCountElementFromContainer(hashTableClAdr2, binaryTreeLnk1, 135);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);

    cout << endl;

    lasd::HashTableClsAdr<double> hashTableClAdr3(90, vec2);

    HashTabSize(hashTableClAdr3, 50);
    HashTabEmpty(hashTableClAdr3, false);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);
    hashTableClAdr3.InsertAll(list2);
    HashTabEmpty(hashTableClAdr3, false);
    HashTabSize(hashTableClAdr3, 200);
    HashTabCountElementFromContainer(hashTableClAdr3, list2, 200);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableClsAdr<double> hashTableCl(vec);
    lasd::HashTableClsAdr<double> copyHashTableCl(hashTableCl);

    HashTabEquals(hashTableCl, copyHashTableCl, true);

    lasd::HashTableClsAdr<double> moveHashTableCl(std::move(hashTableCl));

    HashTabNotEquals(hashTableCl, moveHashTableCl, true);
    HashTabEquals(moveHashTableCl, copyHashTableCl, true);

    hashTableCl = copyHashTableCl;
    HashTabEquals(hashTableCl, copyHashTableCl, true);
    HashTabEquals(hashTableCl, moveHashTableCl, true);

    lasd::HashTableClsAdr<double> hashTableClNew;

    hashTableClNew = std::move(hashTableCl);
    HashTabEquals(hashTableClNew, copyHashTableCl, true);
    HashTabEquals(hashTableClNew, moveHashTableCl, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableCl, 0);
    hashTableCl.Resize(250);
    HashTabSize(hashTableCl, 0);
    hashTableCl.InsertAll(vec);
    HashTabSize(hashTableCl, 135);
    hashTableCl.Resize(64);
    HashTabSize(hashTableCl, 135);
    hashTableCl.RemoveAll(vec);
    HashTabSize(hashTableCl, 0);
    for (int i = 0; i < 100; i++) {
      hashTableCl.Insert(vec3[i]);
    }
    hashTableCl.Insert(1.5);
    hashTableCl.Insert(2.5);
    hashTableCl.Insert(3.5);
    hashTableCl.Insert(4.5);
    HashTabExists(hashTableCl, true, 1.5);
    HashTabExists(hashTableCl, true, 2.5);
    HashTabExists(hashTableCl, true, 3.5);
    HashTabExists(hashTableCl, true, 4.5);
    HashTabNotExists(hashTableCl, true, 0.5);
    HashTabSize(hashTableCl, 104);
    hashTableCl.Remove(1.5);
    hashTableCl.Remove(2.5);
    hashTableCl.Remove(3.5);
    hashTableCl.Remove(4.5);
    HashTabNotExists(hashTableCl, true, 1.5);
    HashTabNotExists(hashTableCl, true, 2.5);
    HashTabNotExists(hashTableCl, true, 3.5);
    HashTabNotExists(hashTableCl, true, 4.5);
    HashTabSize(hashTableCl, 100);

    cout << endl << "End HashTableClAdr for Integer" << endl;
    cout << endl << "Begin HashTableOpnAdr for Integer" << endl;
    
    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableOpnAdr<double> hashTableOpnAdrDef;

    HashTabSize(hashTableOpnAdrDef, 0);
    HashTabEmpty(hashTableOpnAdrDef, true);
    hashTableOpnAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdrDef, false);
    HashTabSize(hashTableOpnAdrDef, 200);
    HashTabCountElementFromContainer(hashTableOpnAdrDef, list2, 200);
    hashTableOpnAdrDef.Clear();
    HashTabEmpty(hashTableOpnAdrDef, true);
    HashTabSize(hashTableOpnAdrDef, 0);

    cout << endl;

    lasd::HashTableOpnAdr<double> hashTableOpnAdr1(65545);

    HashTabSize(hashTableOpnAdr1, 0);
    HashTabEmpty(hashTableOpnAdr1, true);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);
    hashTableOpnAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableOpnAdr1, false);
    HashTabSize(hashTableOpnAdr1, 50);
    HashTabCountElementFromContainer(hashTableOpnAdr1, bst1, 50);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);

    cout << endl;

    lasd::HashTableOpnAdr<double> hashTableOpnAdr2(vec2);

    HashTabSize(hashTableOpnAdr2, 50);
    HashTabEmpty(hashTableOpnAdr2, false);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);
    hashTableOpnAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableOpnAdr2, false);
    HashTabSize(hashTableOpnAdr2, 135);
    HashTabCountElementFromContainer(hashTableOpnAdr2, binaryTreeLnk1, 135);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);

    cout << endl;

    lasd::HashTableOpnAdr<double> hashTableOpnAdr3(90, vec2);

    HashTabSize(hashTableOpnAdr3, 50);
    HashTabEmpty(hashTableOpnAdr3, false);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);
    hashTableOpnAdr3.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdr3, false);
    HashTabSize(hashTableOpnAdr3, 200);
    HashTabCountElementFromContainer(hashTableOpnAdr3, list2, 200);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableOpnAdr<double> hashTableOpn(vec);
    lasd::HashTableOpnAdr<double> copyHashTableOpn(hashTableOpn);

    HashTabEquals(hashTableOpn, copyHashTableOpn, true);

    lasd::HashTableOpnAdr<double> moveHashTableOpn(std::move(hashTableOpn));

    HashTabNotEquals(hashTableOpn, moveHashTableOpn, true);
    HashTabEquals(moveHashTableOpn, copyHashTableOpn, true);

    hashTableOpn = copyHashTableOpn;
    HashTabEquals(hashTableOpn, copyHashTableOpn, true);
    HashTabEquals(hashTableOpn, moveHashTableOpn, true);

    lasd::HashTableOpnAdr<double> hashTableOpnNew;

    hashTableOpnNew = std::move(hashTableOpn);
    HashTabEquals(hashTableOpnNew, copyHashTableOpn, true);
    HashTabEquals(hashTableOpnNew, moveHashTableOpn, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableOpn, 0);
    hashTableOpn.Resize(250);
    HashTabSize(hashTableOpn, 0);
    hashTableOpn.InsertAll(vec);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.Resize(64);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.RemoveAll(vec);
    HashTabSize(hashTableOpn, 0);
    for (int i = 0; i < 100; i++) {
      hashTableOpn.Insert(vec3[i]);
    }
    hashTableOpn.Insert(1.5);
    hashTableOpn.Insert(2.5);
    hashTableOpn.Insert(3.5);
    hashTableOpn.Insert(4.5);
    HashTabExists(hashTableOpn, true, 1.5);
    HashTabExists(hashTableOpn, true, 2.5);
    HashTabExists(hashTableOpn, true, 3.5);
    HashTabExists(hashTableOpn, true, 4.5);
    HashTabNotExists(hashTableOpn, true, 0.5);
    HashTabSize(hashTableOpn, 104);
    hashTableOpn.Remove(1.5);
    hashTableOpn.Remove(2.5);
    hashTableOpn.Remove(3.5);
    hashTableOpn.Remove(4.5);
    HashTabNotExists(hashTableOpn, true, 1.5);
    HashTabNotExists(hashTableOpn, true, 2.5);
    HashTabNotExists(hashTableOpn, true, 3.5);
    HashTabNotExists(hashTableOpn, true, 4.5);
    HashTabSize(hashTableOpn, 100);

    cout << endl << "End HashTableOpnAdr for Double" << endl;
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For Double!" << endl;
}

void mytestHashTableString(){
  try{
    cout << endl << "Begin HashTable for String" << endl;
    cout << endl << "Begin HashTableClAdr for String" << endl;

    lasd::Vector<string> vec(135);
    fill(vec);

    lasd::Vector<string> vec2(50);
    fill(vec2);

    lasd::Vector<string> vec3(100);
    fill(vec3);

    lasd::List<string> list1;
    fill(list1, 160);

    lasd::List<string> list2;
    fill(list2, 200);

    lasd::BinaryTreeLnk<string> binaryTreeLnk1(vec);
    lasd::BST<string> bst1(vec2);

    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableClsAdr<string> hashTableClAdrDef;

    HashTabSize(hashTableClAdrDef, 0);
    HashTabEmpty(hashTableClAdrDef, true);
    hashTableClAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableClAdrDef, false);
    HashTabSize(hashTableClAdrDef, 200);
    HashTabCountElementFromContainer(hashTableClAdrDef, list2, 200);
    hashTableClAdrDef.Clear();
    HashTabEmpty(hashTableClAdrDef, true);
    HashTabSize(hashTableClAdrDef, 0);

    cout << endl;

    lasd::HashTableClsAdr<string> hashTableClAdr1(65545);

    HashTabSize(hashTableClAdr1, 0);
    HashTabEmpty(hashTableClAdr1, true);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);
    hashTableClAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableClAdr1, false);
    HashTabSize(hashTableClAdr1, 50);
    HashTabCountElementFromContainer(hashTableClAdr1, bst1, 50);
    hashTableClAdr1.Clear();
    HashTabEmpty(hashTableClAdr1, true);
    HashTabSize(hashTableClAdr1, 0);

    cout << endl;

    lasd::HashTableClsAdr<string> hashTableClAdr2(vec2);

    HashTabSize(hashTableClAdr2, 50);
    HashTabEmpty(hashTableClAdr2, false);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);
    hashTableClAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableClAdr2, false);
    HashTabSize(hashTableClAdr2, 135);
    HashTabCountElementFromContainer(hashTableClAdr2, binaryTreeLnk1, 135);
    hashTableClAdr2.Clear();
    HashTabEmpty(hashTableClAdr2, true);
    HashTabSize(hashTableClAdr2, 0);

    cout << endl;

    lasd::HashTableClsAdr<string> hashTableClAdr3(90, vec2);

    HashTabSize(hashTableClAdr3, 50);
    HashTabEmpty(hashTableClAdr3, false);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);
    hashTableClAdr3.InsertAll(list2);
    HashTabEmpty(hashTableClAdr3, false);
    HashTabSize(hashTableClAdr3, 200);
    HashTabCountElementFromContainer(hashTableClAdr3, list2, 200);
    hashTableClAdr3.Clear();
    HashTabEmpty(hashTableClAdr3, true);
    HashTabSize(hashTableClAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableClsAdr<string> hashTableCl(vec);
    lasd::HashTableClsAdr<string> copyHashTableCl(hashTableCl);

    HashTabEquals(hashTableCl, copyHashTableCl, true);

    lasd::HashTableClsAdr<string> moveHashTableCl(std::move(hashTableCl));

    HashTabNotEquals(hashTableCl, moveHashTableCl, true);
    HashTabEquals(moveHashTableCl, copyHashTableCl, true);

    hashTableCl = copyHashTableCl;
    HashTabEquals(hashTableCl, copyHashTableCl, true);
    HashTabEquals(hashTableCl, moveHashTableCl, true);

    lasd::HashTableClsAdr<string> hashTableClNew;

    hashTableClNew = std::move(hashTableCl);
    HashTabEquals(hashTableClNew, copyHashTableCl, true);
    HashTabEquals(hashTableClNew, moveHashTableCl, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableCl, 0);
    hashTableCl.Resize(250);
    HashTabSize(hashTableCl, 0);
    hashTableCl.InsertAll(vec);
    HashTabSize(hashTableCl, 135);
    hashTableCl.Resize(64);
    HashTabSize(hashTableCl, 135);
    hashTableCl.RemoveAll(vec);
    HashTabSize(hashTableCl, 0);
    for (int i = 0; i < 100; i++) {
      hashTableCl.Insert(vec3[i]);
    }
    hashTableCl.Insert(string("A"));
    hashTableCl.Insert(string("B"));
    hashTableCl.Insert(string("C"));
    hashTableCl.Insert(string("D"));
    HashTabExists(hashTableCl, true, string("A"));
    HashTabExists(hashTableCl, true, string("B"));
    HashTabExists(hashTableCl, true, string("C"));
    HashTabExists(hashTableCl, true, string("D"));
    HashTabNotExists(hashTableCl, true, string("Z"));
    HashTabSize(hashTableCl, 104);
    hashTableCl.Remove(string("A"));
    hashTableCl.Remove(string("B"));
    hashTableCl.Remove(string("C"));
    hashTableCl.Remove(string("D"));
    HashTabNotExists(hashTableCl, true, string("A"));
    HashTabNotExists(hashTableCl, true, string("B"));
    HashTabNotExists(hashTableCl, true, string("C"));
    HashTabNotExists(hashTableCl, true, string("D"));
    HashTabSize(hashTableCl, 100);

    cout << endl << "End HashTableClAdr for String" << endl;
    cout << endl << "Begin HashTableOpnAdr for String" << endl;
    
    cout << endl << "Constructors Tests" << endl << endl;

    lasd::HashTableOpnAdr<string> hashTableOpnAdrDef;

    HashTabSize(hashTableOpnAdrDef, 0);
    HashTabEmpty(hashTableOpnAdrDef, true);
    hashTableOpnAdrDef.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdrDef, false);
    HashTabSize(hashTableOpnAdrDef, 200);
    HashTabCountElementFromContainer(hashTableOpnAdrDef, list2, 200);
    hashTableOpnAdrDef.Clear();
    HashTabEmpty(hashTableOpnAdrDef, true);
    HashTabSize(hashTableOpnAdrDef, 0);

    cout << endl;

    lasd::HashTableOpnAdr<string> hashTableOpnAdr1(65545);

    HashTabSize(hashTableOpnAdr1, 0);
    HashTabEmpty(hashTableOpnAdr1, true);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);
    hashTableOpnAdr1.InsertAll(bst1);
    HashTabEmpty(hashTableOpnAdr1, false);
    HashTabSize(hashTableOpnAdr1, 50);
    HashTabCountElementFromContainer(hashTableOpnAdr1, bst1, 50);
    hashTableOpnAdr1.Clear();
    HashTabEmpty(hashTableOpnAdr1, true);
    HashTabSize(hashTableOpnAdr1, 0);

    cout << endl;

    lasd::HashTableOpnAdr<string> hashTableOpnAdr2(vec2);

    HashTabSize(hashTableOpnAdr2, 50);
    HashTabEmpty(hashTableOpnAdr2, false);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);
    hashTableOpnAdr2.InsertAll(binaryTreeLnk1);
    HashTabEmpty(hashTableOpnAdr2, false);
    HashTabSize(hashTableOpnAdr2, 135);
    HashTabCountElementFromContainer(hashTableOpnAdr2, binaryTreeLnk1, 135);
    hashTableOpnAdr2.Clear();
    HashTabEmpty(hashTableOpnAdr2, true);
    HashTabSize(hashTableOpnAdr2, 0);

    cout << endl;

    lasd::HashTableOpnAdr<string> hashTableOpnAdr3(90, vec2);

    HashTabSize(hashTableOpnAdr3, 50);
    HashTabEmpty(hashTableOpnAdr3, false);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);
    hashTableOpnAdr3.InsertAll(list2);
    HashTabEmpty(hashTableOpnAdr3, false);
    HashTabSize(hashTableOpnAdr3, 200);
    HashTabCountElementFromContainer(hashTableOpnAdr3, list2, 200);
    hashTableOpnAdr3.Clear();
    HashTabEmpty(hashTableOpnAdr3, true);
    HashTabSize(hashTableOpnAdr3, 0);

    cout << endl;

    cout << "Copy/Move Constructors and Operator= Tests" << endl << endl;

    lasd::HashTableOpnAdr<string> hashTableOpn(vec);
    lasd::HashTableOpnAdr<string> copyHashTableOpn(hashTableOpn);

    HashTabEquals(hashTableOpn, copyHashTableOpn, true);

    lasd::HashTableOpnAdr<string> moveHashTableOpn(std::move(hashTableOpn));

    HashTabNotEquals(hashTableOpn, moveHashTableOpn, true);
    HashTabEquals(moveHashTableOpn, copyHashTableOpn, true);

    hashTableOpn = copyHashTableOpn;
    HashTabEquals(hashTableOpn, copyHashTableOpn, true);
    HashTabEquals(hashTableOpn, moveHashTableOpn, true);

    lasd::HashTableOpnAdr<string> hashTableOpnNew;

    hashTableOpnNew = std::move(hashTableOpn);
    HashTabEquals(hashTableOpnNew, copyHashTableOpn, true);
    HashTabEquals(hashTableOpnNew, moveHashTableOpn, true);

    cout << endl;

    cout << "Other Functions Tests" << endl << endl;

    HashTabSize(hashTableOpn, 0);
    hashTableOpn.Resize(250);
    HashTabSize(hashTableOpn, 0);
    hashTableOpn.InsertAll(vec);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.Resize(64);
    HashTabSize(hashTableOpn, 135);
    hashTableOpn.RemoveAll(vec);
    HashTabSize(hashTableOpn, 0);
    for (int i = 0; i < 100; i++) {
      hashTableOpn.Insert(vec3[i]);
    }
    hashTableOpn.Insert(string("A"));
    hashTableOpn.Insert(string("B"));
    hashTableOpn.Insert(string("C"));
    hashTableOpn.Insert(string("D"));
    HashTabExists(hashTableOpn, true, string("A"));
    HashTabExists(hashTableOpn, true, string("B"));
    HashTabExists(hashTableOpn, true, string("C"));
    HashTabExists(hashTableOpn, true, string("D"));
    HashTabNotExists(hashTableOpn, true, string("Z"));
    HashTabSize(hashTableOpn, 104);
    hashTableOpn.Remove(string("A"));
    hashTableOpn.Remove(string("B"));
    hashTableOpn.Remove(string("C"));
    hashTableOpn.Remove(string("D"));
    HashTabNotExists(hashTableOpn, true, string("A"));
    HashTabNotExists(hashTableOpn, true, string("B"));
    HashTabNotExists(hashTableOpn, true, string("C"));
    HashTabNotExists(hashTableOpn, true, string("D"));
    HashTabSize(hashTableOpn, 100);

    cout << endl << "End HashTableOpnAdr for String" << endl;
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End of HashTable For String!" << endl;
}

void mytest() {
  cout << "Begin of MyTest!" << endl;
  int choiche = 0;
  do{
    cout << endl << "1: To Run HashTable for Integer Tests" << endl;
    cout << "2: To Run HashTable for Double Tests" << endl;
    cout << "3: To Run HashTable for String Tests" << endl;
    cout << "Any Other Key: To Close" << endl;
    cin >> choiche;
    if(choiche == 1){
      mytestHashTableInteger();
    }
    else if(choiche == 2){
      mytestHashTableDouble();
    }
    else if(choiche == 3){
      mytestHashTableString();
    } else{
      choiche = 0;
    }
  } while (choiche == 1 || choiche == 2 || choiche == 3);
  cout << "End of MyTest!" << endl;
  cout << endl;
}
