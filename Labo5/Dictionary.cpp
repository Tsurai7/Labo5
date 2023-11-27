//#include "Dictionary.h"
//#include <iostream>
//#include <stdexcept>
//
//template <typename K, typename V>
//int Dictionary<K, V>::GetHash(K key) {
//    return std::hash<K>{}(key) % buckets.size() + 1;
//}
//
//template <typename K, typename V>
//void Dictionary<K, V>::Insert(K key, V val) {
//    int index = GetHash(key);
//    buckets.push_back(std::make_pair(key, val));
//}
//
//template <typename K, typename V>
//std::pair<K, V> Dictionary<K, V>::Find(K key) {
//    try {
//        int index = GetHash(key);
//        for (const auto& entry : buckets) {
//            if (entry.first == key)
//                return entry;
//        }
//        throw std::out_of_range("Key not found");
//    }
//    catch (const std::out_of_range& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return std::make_pair(K(), V());
//    }
//}
//
//template <typename K, typename V>
//void Dictionary<K, V>::Delete(K key) {
//    try {
//        int index = GetHash(key);
//        auto it = std::remove_if(buckets.begin(), buckets.end(),
//            [key](const std::pair<K, V>& entry) { return entry.first == key; });
//
//        if (it != buckets.end()) {
//            buckets.erase(it, buckets.end());
//        }
//        else {
//            throw std::out_of_range("Key not found");
//        }
//    }
//    catch (const std::out_of_range& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//}
//
//
//template <typename K, typename V>
//std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& dict) {
//    for (const auto& entry : dict.buckets) {
//        os << "Key: " << entry.first << ", Value: " << entry.second << std::endl;
//    }
//    return os;
//}
//
//template class Dictionary<std::string, int>;
