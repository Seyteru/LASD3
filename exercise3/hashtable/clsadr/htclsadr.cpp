#include "htclsadr.hpp"

namespace lasd {

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize){
        tableSize = std::pow(2, std::ceil(log2((newSize <= 16) ? 16 : newSize)));
        table = new List<Data>[tableSize] {};
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &container) : HashTableClsAdr(container.Size()){
        container.Traverse(
            [this](const Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, const TraversableContainer<Data> &container) : HashTableClsAdr(newSize){
        container.Traverse(
            [this](const Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&container) : HashTableClsAdr(container.Size()){
        container.Map(
            [this](Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, MappableContainer<Data> &&container) : HashTableClsAdr(newSize){
        container.Map(
            [this](Data &data){
                Insert(data);
            }
        );
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &hashTableCl){
        table = hashTableCl.table;
        tableSize = hashTableCl.tableSize;
        size = hashTableCl.size;
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&hashTableCl) noexcept{
        std::swap(table, hashTableCl.table);
        std::swap(tableSize, hashTableCl.tableSize);
        std::swap(size, hashTableCl.size);
    }

    template <typename Data>
    HashTableClsAdr<Data>::~HashTableClsAdr(){
        delete[] table;
    }

    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &hashTableCl){
        table = hashTableCl.table;
        tableSize = hashTableCl.tableSize;
        size = hashTableCl.size;
        return *this;
    }

    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&hashTableCl) noexcept{
        std::swap(table, hashTableCl.table);
        std::swap(tableSize, hashTableCl.tableSize);
        std::swap(size, hashTableCl.size);
        return *this;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &hashTableCl) const noexcept{
        return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data> &hashTableCl) const noexcept{
        return !(*this == hashTableCl);
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(const Data &data){
        return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(Data &&data) noexcept{
        return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Remove(const Data &data){
        return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Exists(const Data &data) const noexcept{
        ulong idx = HashKey(Hashable<Data>()(data));
        if(table[idx].Exists(data)){
            return true;
        } else{
            return false;
        }
    }

    template <typename Data>
    void HashTableClsAdr<Data>::Resize(const ulong newSize){
        
    }

    template <typename Data>
    void HashTableClsAdr<Data>::Clear(){
        if(table != nullptr){
            delete[] table;
            table = new List<Data>[tableSize] {};
            size = 0;
        }
    }
}