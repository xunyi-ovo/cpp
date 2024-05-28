#include "string.h"
namespace bit
{
	const size_t string::npos = -1;
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	string::string(const string& b):
		_size(b.size())
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, b.c_str());
	}
	string::~string()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	const char* string:: c_str()const
	{
		return _str;
	}
	
	size_t string::size()const
	{
		return _size;
	}
	char& string::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& string::operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::const_iterator string::begin()const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return _str + _size;
	}
	string& string::operator=(const string& a)
	{
		delete[]_str;
		_size =_capacity =  a._size;
		_str = new char[_capacity + 1];
		strcpy(_str, a._str);
		return *this;
	}
	void string::reverse()
	{
		int begin = 0, end = _size - 1;
		while (begin < end)
		{
			char t = _str[begin];
			_str[begin] = _str[end];
			_str[end] = t;
			++begin;
			--end;
		}
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n+1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_capacity == _size)
		{
			size_t newcap = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcap);
		}
		_str[_size] = ch;
		_str[_size + 1] = '\0';
		++_size;
	}
	void string::append(const char* str)
	{
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size = _capacity;
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	string& string::operator+=(const string& s)
	{
		append(s.c_str());
		return *this;
	}
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_capacity == _size)
		{
			size_t newcap = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcap);
		}
		//[0,1,2,..._size-1]
		for (int i = _size+1; i > pos; --i)
			_str[i] = _str[i-1];
		//memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		_size++;
	}
	void string::insert(size_t pos, const char* str)
	{
		int gap = strlen(str);
		if (_size + gap > _capacity)
		{
			int len = _size + gap;
			reserve(len);
		}
		//[0,1,..pos,pos+1,..._size-1]_size
		for (int i = _size;i>=(int)pos; --i)
		{
			_str[i + gap] = _str[i];
		}
		for (int i = 0; i < gap; ++i)
		{
			_str[pos + i] = *(str + i);
		}
		_size += gap;
	}
}
