
namespace lasd {

    template<>
    ulong Hashable<int>::operator()(const int &data) const noexcept{
        return data * data;
    }

    template<>
    ulong Hashable<double>::operator()(const double &data) const noexcept{
        ulong integer = floor(data);
        ulong fraction = pow(2, 24) * (data - integer);
        return integer * fraction;
    }

    template<>
    ulong Hashable<std::string>::operator()(const std::string &data) const noexcept{
        ulong acc = 0;
        for(ulong i = 0; i < data.length(); i++){
            acc = acc + (data[i] * i);
        }
        return acc;
    }

    template <typename Data>
    ulong HashTable<Data>::HashKey(ulong key) const noexcept{
        return (a * key + b) % tableSize;
    }

}
