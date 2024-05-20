
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::HashKey;
  using DictionaryContainer<Data>::size;
  // ...

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;

  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer

  HashTableOpnAdr(const ulong);
  HashTableOpnAdr(const TraversableContainer<Data> &);
  HashTableOpnAdr(const ulong, const TraversableContainer<Data> &);
  HashTableOpnAdr(MappableContainer<Data> &&);
  HashTableOpnAdr(const ulong, MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;

  HashTableOpnAdr(const HashTableOpnAdr<Data> &);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;

  HashTableOpnAdr(HashTableOpnAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;

  ~HashTableOpnAdr();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  HashTableOpnAdr &operator=(const HashTableOpnAdr<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;

  HashTableOpnAdr &operator=(HashTableOpnAdr<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  bool operator==(const HashTableOpnAdr<Data> &) const noexcept;
  bool operator!=(const HashTableOpnAdr<Data> &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  bool Insert(const Data &) override;
  bool Insert(Data &&) noexcept override;
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

  bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size

  void Resize(const ulong) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member

  void Clear() override;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

  ulong HashKey(ulong &, const Data &) const noexcept;
  bool Find(ulong &, ulong &, const Data &) const noexcept;
  ulong FindEmpty(ulong &, const Data &) const noexcept;
  bool Remove(ulong &, const Data &) noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
