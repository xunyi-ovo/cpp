#include <vector>
#include <iostream>
using namespace std;
template<class K,class V>
struct hashNode{
    pair<K,V> _kv;
    hashNode* _next;
    hashNode(const pair<K,V>& kv,
        hashNode* next = nullptr):
        _kv(kv),_next(next){}
};
template <class K>
struct hashFunc{
    size_t operator()(const K& key){
        return size_t(key);
    }
};

template<class K,class V,class hash=hashFunc<K>>
class hashTable{
    public:
    typedef hashNode<K,V> node;
    hashTable(){
        _table.resize(10,nullptr);
    }
    ~hashTable(){
        for(auto e:_table){
            
        }
    }
    node* Find(const K& key){
        hash hs;
        size_t hashi=hs(key)%_table.size();
        node* cur = _table[hashi];
        while(cur!=nullptr){
            if(cur->_kv.first==key){
                break;
            }
            cur = cur->_next;
        }
        return cur;
    }
    bool Insert(const pair<K,V>& kv){
        if(Find(kv.first)!=nullptr){
            return false;
        }
        hash hs;
        if(_count==_table.size()){
            vector<node*> newTable(2*_table.size(),nullptr);
            for(const auto& e:_table){
                node* curr = e;
                while(curr!=nullptr){
                    node* next = curr->_next;
                    size_t hashi = hs(curr->_kv.first)%newTable.size();
                    curr->_next = newTable[hashi];
                    newTable[hashi] = curr;
                    curr=next;
                }
            }
            _table.swap(newTable);
        }
        size_t hashi = hs(kv.first)%_table.size();
        node* newnode = new node(kv);
        newnode->_next = _table[hashi];
        _table[hashi] = newnode;
        ++_count;
        return true;
    }


    private:
    vector<node*> _table;
    size_t _count = 0;
};