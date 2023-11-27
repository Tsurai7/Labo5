#pragma once
#include <iostream>
#include <vector>

template <typename K, typename V>
class Dictionary
{
private:
    int GetHash(K key);
    std::vector<std::pair<K, V>> buckets;

public:
    void Insert(K key, V val);
    std::pair<K, V> Find(K key);
    void Delete(K key);

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
};

