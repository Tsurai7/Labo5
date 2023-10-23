#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Dictionary
{
private:
	int size;
	vector<pair<K, V>>* buckets;
public:
	Dictionary(int capacity);



};

