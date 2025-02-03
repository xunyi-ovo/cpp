#include "RB_tree.h"
namespace xunyi{
    template<class K,class V,class Compare=my_less<K>>
    class map{
        public:
        struct keyOfvalue{
            const K& operator()(const pair<K,V>& p){
                return p.first;
            }
        };
        typedef typename RB_tree<K,pair<K,V>,keyOfvalue>::iterator iterator;
        typedef typename RB_tree<K,pair<K,V>,keyOfvalue>::const_iterator const_iterator;
        iterator begin()
        {
            return tree.Begin();
        }
        iterator end()
        {
            return tree.End();
        }
        const_iterator begin() const
        {
            return tree.Begin();
        }
        const_iterator end() const
        {
            return tree.End();
        }
        bool insert(const pair<K,V>& p)
        {
            return tree.Insert(p);
        }

        private:
        RB_tree<K,pair<K,V>,keyOfvalue,Compare> tree;

    };
}