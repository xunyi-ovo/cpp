#include "hash.h"

template <class K>
class unordered_Set{
    public:
    struct setkeyOfvalue{
        const K& operator()(const K& key){
            return key;
        }
    };
    bool insert(const K& key){
        return _hash_table.Insert(key);
    }
    bool erase(const K& key){
        return _hash_table.erase(key);
    }
    private:
    hashTable<K,const K,setkeyOfvalue> _hash_table;
};