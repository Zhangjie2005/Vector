
#include"MyVector.h"

template<class T>
class  MyVector
{
public:
	MyVector()
	{
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_capacity = nullptr;
		cout << "构造函数功能实现" << endl;
	}

	~MyVector()
	{
		delete[] _start;
		_start = _finish = _end_capacity = nullptr;
		cout << "析构函数功能实现" << endl;
	}

	MyVector(const  MyVector& vec)
	{
		_start = new T[vec.capacity()];
		for (size_t i = 0; i < vec.size(); i++)
		{
			_start[i] = vec._start[i];
		}
		_finish = _start + vec.size();
		_end_capacity = _start + vec.capacity();
		cout << "拷贝构造函数功能实现" << endl;
	}

	MyVector& operator =(const MyVector& vec)
	{
		if (this == &vec)
		{
			return *this;
		}
		delete[]_start;
		_start = new T[vec.capacity()];
		for (size_t i = 0; i < vec.size(); i++)
		{
			_start[i] = vec._start[i];
		}
		_finish = _start + vec.size();
		_end_capacity = _start + vec.capacity();
		return *this;
	}

	T& operator[](size_t index) const
	{
		assert(index < size());
		return _start[index];
	}

	bool operator==(const MyVector& vec) const
	{
		T* it1 = _start;
		T* it2 = vec._start;
		int flag = 1;
		if (size() != vec.size())
		{
			flag = 0;
		}
		else
		{
			for (; it1 < _finish; it1++, it2++)
			{
				if (*it1 != *it2)
				{
					flag = 0;
				}
			}
		}
		if (flag == 0)
		{
			return 0;
		}
		return 1;
	}

	void reserve(size_t n)
	{
		if (n > capacity())
		{
			T* tmp = new T[n];
			size_t size1 = size();
			if (_start)
			{
				for (size_t i = 0; i < size1; ++i)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + size1;
			_end_capacity = _start + n;
		}
	}

	void push_back(const T& x)
	{
		if (_finish == _end_capacity)
		{
			reserve(capacity() == 0 ? 4 : capacity() * 2);
		}
		*_finish = x;
		++_finish;
	}

	void pop_back()
	{
		assert(!empty());
		--_finish;
	}

	void insert(T* it, T val)
	{
		assert(it <= _finish);
		assert(it >= _start);
		if (_finish == _end_capacity)
		{
			int len = it - _start;
			reserve(capacity() == 0 ? 4 : capacity() * 2);
			it = _start + len;
		}
		T* end = _finish;
		while (end >= it)
		{
			*end = *(end - 1);
			--end;
		}
		*it = val;
		_finish++;
	}

	void erase(T* it)
	{
		assert(it <= _finish);
		assert(it >= _start);
		T* first = it + 1;
		while (first != _finish)
		{
			*(first - 1) = *first;
			++first;
		}
		--_finish;
	}

	T* begin()
	{
		return _start;
	}
	T* end()
	{
		return _finish;
	}

	T front() const
	{
		return *_start;
	}

	T back() const
	{
		return *(_finish - 1);
	}

	size_t size() const
	{
		return _finish - _start;
	}
	size_t capacity() const
	{
		return _end_capacity - _start;
	}

	bool empty()
	{
		return _start == _finish;
	}

	class iterator
	{
	public:
		iterator(T* ptr = nullptr) :_ptr(ptr)
		{
		}
		bool operator!=(const iterator& it)
		{
			return _ptr != it._ptr;
		}
		bool operator++()
		{
			_ptr++;
			return true;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T operator[](int index)
		{
			return _ptr[index];
		}
	private:
		T* _ptr;
	};

	typedef const T* const_iterator;

private:
	T* _start;
	T* _finish;
	T* _end_capacity;

	template<typename T>
	friend ostream& operator<<(ostream& out, const MyVector<T>& vec);
};

template<typename T>
ostream& operator<<(ostream& out, const MyVector<T>& vec)
{
	T* it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		out << *it << " ";
	}
	cout << endl;
}