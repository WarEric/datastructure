/*
 * arraylist相关函数的实现
 * by wareric@163.com
 * 2018-05-05
 */
#include<stdexcept>
#include<sstream>
#include"ArrayList.h"
ArrayList::ArrayList(const ArrayList &orig)
{
	capacity = orig.capacity;
	array = new int[capacity];
	type_size = orig.size;
	length = orig.length;

	int *dst = array, *src = orig.array;
	for(int i = 0; i < length; i++)
		*dst++ = *src++;
}

ArrayList::~ArrayList()
{
	if(array != nullptr)
		delete[] array;
}

bool ArrayList::init(unsigned int cap)
{
	if(array != nullptr) 
		return false;

	capacity = cap;
	length = 0;
	array = new int[capacity];
	return true;
}

bool ArrayList::destory()
{
	if(array == nullptr) return false;

	delete[] array;
	array = nullptr;
	length = 0;
	return true;
}

void ArrayList::clear()
{
	length = 0;
}

bool ArrayList::empty()
{
	return length > 0 ? false:true;
}

unsigned ArrayList::length()
{
	return length;
}

unsigned ArrayList::capacity()
{
	return capacity;
}

int ArrayList::get(int i)
{
	if(i < 0 || i >= length)
	{
		ostringstream s;
		s << i << " out range [0," << length << "]" << endl;
		throw range_error(s.str());
	}
	return *(array+i);
}

int ArrayList::contains(int value)
{
	int *ptr = array;
	for(int i = 0; i < length; i++, ptr++)
		if(*ptr == value)
			return i;
}

bool ArrayList::insert(int i, int value)
{
	if(i < 0 || i >= length) return false;
	if(length >= capacity) increase(2*capacity);

	length++;
	int j;
	for(j = length; j > i; j--)
		array[j] = array[j-1];
	array[j] = value;

	return true;
}

bool ArrayList::push_back(int value)
{
	if(length >= capacity) increase(2*capacity);

	array[length++] = value;
}

int ArrayList::pop_front()
{
	int res = array[0];
	length--;
	for(int i = 0; i < length; i++)
		array[i] = array[i+1];

	return res;
}

bool ArrayList::del(int i)
{
	if(i < 0 || i >= length) return false;
	length--;
	for(; i < length; i++)
		array[i] = array[i+1];
	return true;
}

void ArrayList::traverse()
{
	for(int i = 0, j = length-1, mid = length/2; i < mid; i++, j--)
		array[i] = array[j];
}



ArrayList& operator=(const ArrayList &orig)
{
	if(this == &orig) return;

	destory();
	capacity = orig.capacity;
	init(capacity);

	for(int i = 0, end = orig.length; i < end; i++, length++)
		array[i] = orig.array[i];
}

bool ArrayList::operator==(const ArrayList &orig)
{
	if(this == &orig) return true;
	if(array == nullptr || orig.array == nullptr) return false;
	if(length != orig.length) return false;

	for(int i = 0; i < length; i++)
		if(array[i] != orig.array[i]) return false;

	return true;
}

bool ArrayList::increase(unsigned int max)
{
	if(max <= capacity) return false;
	
	capacity = max;
	int *ptr = new int[capacity];
	int *dst = ptr, *src = array;

	for(int i = 0; i < lenght; i++)
		*dst++ = *src++;

	delete array;
	array = ptr;
	return true;
}
