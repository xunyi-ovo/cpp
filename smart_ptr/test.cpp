#include "st_ptr.h"
using xy::shared_ptr;
using xy::weak_ptr;
struct node{
    weak_ptr<node> _next;
    weak_ptr<node> _prev;
    int _data;
    node(int data=0):
        _data(data),
        _prev(nullptr),
        _next(nullptr){}
};
int main()
{
    shared_ptr<node> sp1(new node(1));
    shared_ptr<node> sp2(new node(2));
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    sp1->_next = sp2;
    sp2->_prev = sp1;
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    return 0;
}