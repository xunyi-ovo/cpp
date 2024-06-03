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
		_str = new char[_capacity + 1];
		_capacity = b._capacity;
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
		if (this != &a)
		{
			char* tmp = new char[a._capacity + 1];
			strcpy(tmp, a.c_str());
			delete[]_str;
			_str = tmp;
			_size = a._size;
			_capacity = a._capacity;
		}
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
			size_t len = _size + gap;
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

	void string::eraser(size_t pos, int n)
	{
		if (n >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			int i = 0;
			for (i = pos + n; i < _size + 1; ++i)
			{
				_str[i - n] = _str[i];
			}
			_size -= n;
		}
	}
	size_t string::find(char ch,int pos)const
	{
		for (int i = pos; i < _size; ++i)
		{
			if (_str[i] == ch)
				return i;
		}
		return -1;
	}

	size_t string::find(const char* s, int pos)const
	{
		for (int i = 0; strlen(s) <= _size - i; ++i)
		{
			int record = i, tmp = i;
			for (int j = 0; j < strlen(s); ++j)
			{
				if (_str[tmp] == s[j])
				{
					++tmp;
					if (s[j + 1] == '\0')
					{
						return record;
					}
				}
				else
				{
					break;
				}
			}
		}
		return -1;
	}
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	string string::substr(size_t pos, size_t len)const
	{
		if (len >= _size - pos)
		{
			//hello
			string sub(_str + pos);
			return sub;
		}
		else
		{
			string sub;
			sub.reserve(len);
			for (int i = pos; i < pos + len; ++i)
			{
				sub += _str[i];
			}
			return sub;
		}
	}
	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		out << s.c_str();
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}


}
