/*
 * arraylist相关函数的实现
 * by wareric@163.com
 * 2018-05-05
 */
#include<stdexcept>
#include<sstream>
#include"ArrayList.h"
using std::ostringstream;
using std::endl;
using std::range_error;

ArrayList::ArrayList(const ArrayList &orig)
{
	cap = orig.cap;
	array = new int[cap];
	len = orig.len;

	int *dst = array, *src = orig.array;
	for(int i = 0; i < len; i++)
		*dst++ = *src++;
}

ArrayList::~ArrayList()
{
	if(array != nullptr)
		delete[] array;
}

bool ArrayList::init(unsigned int capacity)
{
	if(array != nullptr) 
		return false;

	cap = capacity;
	len = 0;
	array = new int[cap];
	return true;
}

bool ArrayList::destroy()
{
	if(array == nullptr) return false;

	delete[] array;
	array = nullptr;
	len = 0;
	return true;
}

void ArrayList::clear()
{
	len = 0;
}

bool ArrayList::empty()
{
	return len > 0 ? false:true;
}

int ArrayList::get(int i)
{
	if(i < 0 || i >= len)
	{
		ostringstream s;
		s << i << " out range [0," << len << "]" << endl;
		throw range_error(s.str());
	}
	return *(array+i);
}

int ArrayList::contains(int value)
{
	int *ptr = array;
	for(int i = 0; i < len; i++, ptr++)
		if(*ptr == value)
			return i;
	return -1;
}

bool ArrayList::insert(int i, int value)
{
	if(i < 0 || i >= len) return false;
	if(len >= cap) increase(2*cap);

	len++;
	int j;
	for(j = len; j > i; j--)
		array[j] = array[j-1];
	array[j] = value;

	return true;
}

bool ArrayList::push_back(int value)
{
	if(len >= cap) increase(2*cap);

	array[len++] = value;
}

int ArrayList::pop_front()
{
	int res = array[0];
	len--;
	for(int i = 0; i < len; i++)
		array[i] = array[i+1];

	return res;
}

bool ArrayList::del(int i)
{
	if(i < 0 || i >= len) return false;
	len--;
	for(; i < len; i++)
		array[i] = array[i+1];
	return true;
}

void ArrayList::traverse()
{
	int temp;
	for(int i = 0, j = len-1, mid = len/2; i < mid; i++, j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

ArrayList& ArrayList::operator=(const ArrayList &orig)
{
	if(this == &orig) return *this;

	destroy();
	cap = orig.cap;
	init(cap);

	for(int i = 0, end = orig.len; i < end; i++, len++)
		array[i] = orig.array[i];

	return *this;
}

bool ArrayList::operator==(const ArrayList &orig)
{
	if(this == &orig) return true;
	if(array == nullptr || orig.array == nullptr) return false;
	if(len != orig.len) return false;

	for(int i = 0; i < len; i++)
		if(array[i] != orig.array[i]) return false;

	return true;
}

bool ArrayList::increase(unsigned int max)
{
	if(max <= cap) return false;
	
	cap = max;
	int *ptr = new int[cap];
	int *dst = ptr, *src = array;

	for(int i = 0; i < len; i++)
		*dst++ = *src++;

	delete array;
	array = ptr;
	return true;
}
