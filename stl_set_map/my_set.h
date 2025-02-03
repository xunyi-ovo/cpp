#include "RB_tree.h"

namespace xunyi{
template <class K>
class set{
    public:
    struct keyOfvalue{
        const K& operator()(const K& key){
            return key;
        }
    };
    typedef typename RB_tree<K,K,keyOfvalue>::iterator iterator;
    typedef typename RB_tree<K,K,keyOfvalue>::const_iterator const_iterator;
    iterator begin(){
        return tree.Begin();
    }
    iterator end(){
        return tree.End();
    }
    const_iterator begin()const{
        return tree.Begin();
    }
    const_iterator end()const{
        return tree.End();
    }
    bool insert(const K& key){
        return tree.Insert(key);
    }
    private:
    RB_tree<K,K,keyOfvalue> tree;
};
}