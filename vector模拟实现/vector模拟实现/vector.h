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
	private:
		typedef T* iterator;
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	public:
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
			if (_start == _finish)
			{
				int new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
			}
			*_finish = d;
			++_finish;
		}

	};
}


