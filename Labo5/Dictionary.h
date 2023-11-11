#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Dictionary
{
private:
	int GetHash(K key);
	vector<pair<K, V>>() buckets;

public:
	void Insert(K key, V val);
	pair<K, V> Find(K key);
	void Delete(K key);

	friend ostream& operator<<();
	friend ostream& operator<<();

};

