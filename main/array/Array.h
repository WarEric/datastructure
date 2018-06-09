/**
 * 数组的头文件，这里还是采用模板实现
 *
 * by wareric@163.com
 * 2018-06-09
 */
#ifndef ARRAY_H_
#define ARRAY_H_
#include <initializer_list>
#include <cstdlib>
using std::initializer_list;

template<typename T> class Array{
	public:
		Array(initializer_list<int> il);
		Array(const Array &orig);
		Array& operator=(const Array &orig);
		~Array();

		T get(initializer_list<int> il);
		void set(T key, initializer_list<int> il);

		bool operator==(const Array &orig);
		bool operator!=(const Array &orig);
	private:
		size_t offset(const initializer_list<int> &il);
		bool copy(const Array &orig);
		void clear();

		T *base;		//数组元素基址
		int dim;		//数组维数
		int *bounds;		//数组维界基址
		int *constants;		//数组映像函数常量基址
};

template<typename T>
Array<T>::Array(initializer_list<int> il):base(nullptr),
       bounds(nullptr), constants(nullptr)
{
	dim = il.size();
	if(dim < 1) exit(EXIT_FAILURE);

	bounds = new int[dim];
	if(!bounds) exit(EXIT_FAILURE);

	size_t eletotal = 1;
	int i = 0;
	for(auto beg = il.begin(); beg != il.end(); beg++, i++)
	{
		bounds[i] = *beg;
		if(bounds[i] < 0) exit(EXIT_FAILURE);
		eletotal *= bounds[i];
	}

	base = new T[eletotal];
	if(!base) exit(EXIT_FAILURE);

	constants = new int[dim];
	if(!constants) exit(EXIT_FAILURE);
	constants[dim-1] = 1;
	for(int j = dim-2; j >=0 ; --j)
		constants[j] = bounds[j+1] * constants[j+1];
}

template<typename T>
Array<T>::Array(const Array &orig):base(nullptr),
	bounds(nullptr), constants(nullptr)
{
	copy(orig);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &orig)
{
	clear();
	copy(orig);
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	clear();
}

template<typename T>
T Array<T>::get(initializer_list<int> il)
{
	return *(base + offset(il));
}

template<typename T>
void Array<T>::set(T key, initializer_list<int> il)
{
	*(base + offset(il)) = key;
}

template<typename T>
bool Array<T>::operator==(const Array &orig)
{
	if(dim != orig.dim) return false;

	size_t total = 1;
	for(int i = 0; i < dim; i++)
	{
		if(bounds[i] != orig.bounds[i])
			return false;
		else
			total *= bounds[i];
	}

	T *pt = orig.base;;
	for(size_t i = 0; i < total; i++)
	{
		if(base[i] != pt[i])
			return false;
	}

	return true;
}

template<typename T>
bool Array<T>::operator!=(const Array &orig)
{
	return !(*this == orig);
}

template<typename T>
size_t Array<T>::offset(const initializer_list<int> &il)
{
	size_t off = 0;
	int i = 0;
	for(auto it = il.begin(); it != il.end(); it++, i++)
		off += constants[i] * (*it);
	return off;
}

template<typename T>
void Array<T>::clear()
{
	if(!base) delete[] base;

	if(!bounds) delete[] bounds;
	
	if(!constants) delete[] constants;
}

template<typename T>
bool Array<T>::copy(const Array &orig)
{
	dim = orig.dim;
	bounds = new int[dim];
	if(!bounds) return false;

	size_t eletotal = 1;
	for(int i = 0; i < dim; i++)
	{
		bounds[i] = orig.bounds[i];
		eletotal *= bounds[i];
	}

	base = new T[eletotal];
	if(!base) return false;
	for(size_t i = 0; i < eletotal; i++)
		base[i] = orig.base[i];

	constants = new int[dim];
	if(!constants) return false;
	for(int i = 0; i < dim; i++)
		constants[i] = orig.constants[i];

	return true;
}
#endif
