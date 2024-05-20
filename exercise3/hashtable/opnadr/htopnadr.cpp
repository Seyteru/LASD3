#include "htopnadr.hpp"

namespace lasd {

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize){

    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &container){
        size = container.Size() * 2;
        container.Traverse(
            [this](const Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, const TraversableContainer<Data> &container){
        size = newSize;
        container.Traverse(
            [this](const Data &data){
                Insert(data);
            }
        );
    }
    
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&container){
        size = container.Size() * 2;
        container.Map(
            [this](Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, MappableContainer<Data> &&container){
        size = newSize;
        container.Map(
            [this](Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &hashTableOp){

    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&hashTableOp) noexcept{

    }

    template <typename Data>
    HashTableOpnAdr<Data>::~HashTableOpnAdr(){

    }

    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &hashTableOp){
        // TODO: insert return statement here
    }

    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&hashTableOp) noexcept{
        // TODO: insert return statement here
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data> &hashTableOp) const noexcept{
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data> &hashTableOp) const noexcept{
        return !(*this == hashTableOp);
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(const Data &data){
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(Data &&data) noexcept{
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(const Data &data){
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept{
        return false;
    }

    template <typename Data>
    void HashTableOpnAdr<Data>::Resize(const ulong){

    }

    template<typename Data>
    void HashTableOpnAdr<Data>::Clear(){

    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::HashKey(ulong &, const Data &data) const noexcept{
        return ulong();
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Find(ulong &, ulong &, const Data &data) const noexcept{
        return false;
    }

    template <typename Data>
    ulong HashTableOpnAdr<Data>::FindEmpty(ulong &, const Data &data) const noexcept{
        return ulong();
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(ulong &, const Data &data) noexcept{
        return false;
    }
}