#include <iostream>
namespace xunyi{
template<class T>
struct ListNode{
    typedef ListNode<T> Self;
    Self* _next;
    Self* _prev;
    T     _value;
    ListNode(const T& value=T()):_next(nullptr),_prev(nullptr),_value(value){}
};

template<class T,class Ref,class Pointer>
struct list_iterator{
    typedef list_iterator<T,Ref,Pointer> Self;
    typedef ListNode<T> Node;
    Node* _node;
    list_iterator(Node* value):_node(value){}
    list_iterator(const Self& value):_node(value._node){}
    Self& operator++(){
        _node = _node->_next;
        return *this;
    }
    Self operator++(int){
        Self tmp(*this);
        _node = _node->_next;
        return tmp;
    }
    Self& operator--(){
        _node = _node->_prev;
        return *this;
    }
    Self operator--(int){
        Self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    Ref operator*(){
        return _node->_value;
    }

    Pointer operator->(){
        return &(_node->_value);
    }

    bool operator!=(const Self& him){
        return _node != him._node;
    }
    bool operator==(const Self& him){
        return _node == him._node;
    }
      
};
template<class T>
class List{
    private:
        typedef ListNode<T> Node;
        Node *_head;
    public:
        typedef list_iterator<T, T &, T *> iterator;
        typedef list_iterator<T, const T &, const T *> const_iterator;
        List() : _head(new Node())
        {
            _head->_next = _head;
            _head->_prev = _head;
        }
        ~List()
        {
            iterator it = begin();
            iterator finish = end();
            while (it != finish)
            {
                it = erase(it);
            }
            erase(finish);
        }
        iterator end()
        {
            return iterator(_head);
        }
        iterator begin()
        {
            return iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        iterator insert(iterator pos, const T& value)
        {
            Node *newnode = new Node(value);
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            return iterator(newnode);
        }
        iterator erase(iterator pos)
        {
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete cur;
            return iterator(next);
        }
        void push_back(const T &value)
        {
            insert(end(), value);
        }
        void push_front(const T &value)
        {
            insert(begin(), value);
        }
        void pop_back()
        {
            erase(--end());
        }
        void pop_front()
        {
            erase(begin());
        }
};
ListNode<int>* test1(){
    List<int> ls;
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);
    return ls.begin()._node;
}
}
