
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  
  ulong operator()(const Data &) const noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size;

  ulong a = 3;
  ulong b = 5;
  ulong tableSize = 16;

  // ...

public:

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable &operator=(const HashTable<Data> &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable &operator=(HashTable<Data> &&)noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.

  bool operator==(const HashTable<Data> &) const noexcept = delete;
  bool operator!=(const HashTable<Data> &) const noexcept = delete;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  ulong HashKey(ulong) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
