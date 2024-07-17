#pragma once
#include <iostream>
using namespace std;
namespace xunyi
{
	template<class T>
	class _list_node
	{
	public:
		T _data;
		_list_node<T>* _next;
		_list_node<T>* _prev;
		_list_node(const T& value = T()) :_data(value)
		{
			_next = _prev = this;
		}
	};
	template<class T,class Ref,class Ptr> struct _list_iterator
	{
		typedef _list_node<T>*            Pointer;
		typedef _list_iterator<T,Ref,Ptr> Self;
		Pointer pointer;
		_list_iterator(Pointer p = nullptr) :pointer(p) {}
		Ref operator*() { return pointer->_data; }
		Ptr operator->() { return &pointer->_data; }
		Self& operator++() { pointer = pointer->_next; return *this; }
		Self operator++(int) { Self tmp(pointer); pointer = pointer->_next; return tmp; }
		Self& operator--() { pointer = pointer->prev; return *this; }
		Self operator--(int) { Self tmp(pointer); pointer = pointer->_prev; return tmp; }
		bool operator!=(const Self& it) { return pointer != it.pointer; }
	};
	/*template<class T> class const_list_iterator
	{
	private:
		typedef _list_node<T>* Pointer;
		typedef const_list_iterator<T> Self;
		Pointer pointer;
	public:
		const_list_iterator(Pointer p = nullptr) :pointer(p) {}
		const T& operator*() { return pointer->_data; }
		const T* operator->() { return &pointer->_data; }
		Self& operator++() { pointer = pointer->_next; return *this; }
		Self operator++(int) { Self tmp(pointer); pointer = pointer->_next; return tmp; }
		Self& operator--() { pointer = pointer->prev; return *this; }
		Self operator--(int) { Self tmp(pointer); pointer = pointer->_prev; return tmp; }
		bool operator!=(const Self& it) { return pointer != it.pointer; }
	};*/
	template<class T> class list
	{
	private:
		typedef _list_node<T> node;
		node* _head;
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		//typedef _list_iterator<const T> const_iterator; error!�������ͺ�_next��_prev��ʵ����ΪT����const_iterator��װ��ָ��ʵ����Ϊconst T
		typedef _list_iterator<T,const T&,const T*> const_iterator;//��ͬ�Ĳ��������Ͳ�ͬ�������洫�ξͻ����
		list():_head(new node){}
		void push_back(const T& value)
		{
			/*node* newnode = new node(value);
			_head->_prev->_next = newnode;
			newnode->_prev = _head->_prev;
			_head->_prev = newnode;
			newnode->_next = _head;*/
			insert(end(), value);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& value)
		{
			insert(begin(), value);
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }
		const_iterator begin() const { return const_iterator(_head->_next); }
		const_iterator end() const { return const_iterator(_head); }
		iterator insert(iterator pos,const T& value)
		{
			node* newnode = new node(value);
			node* prev = pos.pointer->_prev;
			node* cur = pos.pointer;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos.pointer->_prev;
			node* next = pos.pointer->_next;
			node* waste = pos.pointer;
			prev->_next = next;
			next->_prev = prev;
			delete waste;
			return iterator(next);
		}

	};

}

