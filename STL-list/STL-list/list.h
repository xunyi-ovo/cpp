#pragma once
#include <iostream>
using namespace std;
namespace xunyi
{
	template<typename T>
	struct listnode
	{
		T _data;
		listnode<T>* _prev;
		listnode<T>* _next;
		listnode<T>(const T& value = T())
		{
			_data = value;
			_prev = nullptr;
			_next = nullptr;
		}
	};
	template<typename T>
	class _list_iterator
	{
	private:
		typedef listnode<T>* _node_pointer;
		_node_pointer  _pointer;
	public:
		_list_iterator(_node_pointer pointer = nullptr):
			_pointer(pointer)
		{}
		T& operator*()
		{
			return _pointer->_data;
		}
		T* operator->()
		{
			return &_pointer->_data;
		}
		_list_iterator& operator++()
		{
			_pointer = _pointer->_next;
			return *this;
		}
		_list_iterator operator++(int)
		{
			_list_iterator tmp(_pointer);
			_pointer = _pointer->_next;
			return tmp;
		}
		_list_iterator& operator--()
		{
			_pointer = _pointer->_prev;
			return *this;
		}
		_list_iterator operator--(int)
		{
			_list_iterator tmp(_pointer);
			_pointer = _pointer->_prev;
			return tmp;
		}
		bool operator!=(const _list_iterator& x)
		{
			return _pointer != x._pointer;
		}
	};
	template<typename T>
	class const_list_iterator
	{
	private:
		typedef listnode<T>*  _node_pointer;
		typedef const_list_iterator<T>  Self;
		_node_pointer  _pointer;
	public:
		const_list_iterator(_node_pointer pointer = nullptr) :
			_pointer(pointer)
		{}
		//const_iterator的核心
		const T& operator*()
		{
			return _pointer->_data;
		}
		//const_iterator的核心
		const T* operator->()
		{
			return &_pointer->_data;
		}
		Self& operator++()
		{
			_pointer = _pointer->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(_pointer);
			_pointer = _pointer->_next;
			return tmp;
		}
		Self& operator--()
		{
			_pointer = _pointer->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(_pointer);
			_pointer = _pointer->_prev;
			return tmp;
		}
		bool operator!=(const Self& x)
		{
			return _pointer != x._pointer;
		}
	};
	template<typename T>
	class list
	{
	private:
		typedef listnode<T> node;
		node* _head;
	public:
		typedef _list_iterator<T> iterator;
		typedef const_list_iterator<T> const_iterator;
		list():_head(new node)
		{
			_head->_prev = _head->_next = _head;
		}
		void push_back(const T& value)
		{
			node* newnode = new node(value);
			node* _tail = _head->_prev;
			_tail->_next = newnode;
			newnode->_prev = _tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			
		}
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin()const
		{
			return const_iterator(_head);
		}
		const_iterator end()const
		{
			return _head;
		}
	};
	
}

