#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;
namespace bit
{
	template<class T>
	class vector
	{
	public:
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _end_of_storage = _finish = nullptr;
			}
		}
		typedef T* iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		int capacity()
		{
			return _end_of_storage - _start;
		}
		int size()
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}

		}
		void push_back(const T& d)
		{
			/*if (_end_of_storage == _finish)
			{
				int new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
			}
			*_finish = d;
			++_finish;*/
			//¸´ÓÃ
			insert(_finish, d);
		}
		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}
		iterator insert(iterator pos, const T& d)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				int gap = pos - _start;
				int new_capacity = capacity() ==0 ? 4 : capacity() * 2;
				reserve(new_capacity);
				pos = _start + gap;
			}
			for (iterator t = _finish;t>pos; --t)
			{
				*t = *(t-1);
			}
			*pos = d;
			++_finish;
			return pos;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			for (iterator t = pos;t<end(); ++t)
			{
				*t = *(t + 1);
			}
			--_finish;
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};
}


