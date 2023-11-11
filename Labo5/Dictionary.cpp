#include "Dictionary.h"
#include <iostream>

template <typename K, typename V>
int Dictionary<K, V>::GetHash(K key) {
    return std::hash<K>{}(key) % buckets.size();
}

template <typename K, typename V>
void Dictionary<K, V>::Insert(K key, V val) {
    int index = GetHash(key);
    buckets.push_back(std::make_pair(key, val));
}

template <typename K, typename V>
pair<K, V> Dictionary<K, V>::Find(K key) {
    int index = GetHash(key);
    for (const auto& entry : buckets) {
        if (entry.first == key) 
            return entry;       
    }
    return nullptr;
}

template <typename K, typename V>
void Dictionary<K, V>::Delete(K key) {
    int index = GetHash(key);
    auto it = std::remove_if(buckets.begin(), buckets.end(),
        [key](const std::pair<K, V>& entry) { return entry.first == key; });

    buckets.erase(it, buckets.end());
}


template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& dict) {
    for (const auto& entry : dict.buckets) {
        os << "Key: " << entry.first << ", Value: " << entry.second << std::endl;
    }
    return os;
}
