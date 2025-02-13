#include "hash.h"

template<class K,class V>
class unordered_Map{
    public:
    struct mapkeyOfv{
        const K& operator()(const pair<const K,V>& data){
            return data.first;
        }
    };
    bool insert(const pair<const K,V>& value){
        return _hash_table.Insert(value);
    }
    bool erase(const K& key){
        return _hash_table.erase(key);
    }
    private:
    hashTable<K,pair<const K,V>,mapkeyOfv> _hash_table;
};