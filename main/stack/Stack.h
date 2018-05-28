/*
 * Stack的头文件，这里考虑用链表来实现，采用模板类型
 * by wareric@163.com
 * 2018-05-23
 */
#ifndef STACK_H_
#define STACK_H_
template<typename T> class Stack;

template<typename T> class StackNode{
	friend class Stack<T>;
	public:
		StackNode(T k):val(k), pre(nullptr){}
		StackNode(T k, StackNode<T> *previous):val(k), pre(previous){}
	private:
		T val;
		StackNode *pre;
};

template<typename T> class Stack{
	public:
		Stack():len(0), t(nullptr){}
		Stack(const Stack &orig);
		Stack<T>& operator=(const Stack &orig);
		~Stack();

		bool clear();
		bool empty();
		int length(){ return len;}

		bool top(T&);
		bool push(const T& val);
		bool pop();

		bool operator==(const Stack &orig);
		bool operator!=(const Stack &orig);
	private:
		StackNode<T>* copy(const Stack &src);
		int len;
		StackNode<T> *t;
};

template<typename T>
Stack<T>::Stack(const Stack &orig)
{
	if(orig.len <= 0) 
		return;

	len = orig.len;
	t = copy(orig);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack &orig)
{
	if(orig.len <= 0)
		return *this;

	clear();
	len = orig.len;
	t = copy(orig);
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
bool Stack<T>::clear()
{
	if(len <= 0)
		return true;

	StackNode<T> *ptr = t;
	while(t != nullptr)
	{
		ptr = t;
		t = t->pre;
		delete ptr;
		len--;
	}

	return true;
}

template<typename T>
bool Stack<T>::empty()
{
	if(len <= 0) 
		return true;
	else
		return false;
}

template<typename T>
bool Stack<T>::top(T& val)
{
	if(len <= 0)
		return false;

	val = t->val;
	return true;
}

template<typename T>
bool Stack<T>::push(const T& val)
{
	StackNode<T> *ptr = new StackNode<T>(val, t);
	t = ptr;
	len++;
	return true;
}

template<typename T>
bool Stack<T>::pop()
{
	if(len <= 0)
	       	return false;

	StackNode<T> *ptr = t;
	t = t->pre;
	delete ptr;
	len--;
	return true;
}

template<typename T>
bool Stack<T>::operator==(const Stack &orig)
{
	if(len != orig.len)
		return false;

	StackNode<T> *pa = t, *pb = orig.t;
	while((pa != nullptr) && (pb != nullptr))
	{
		if(pa->val != pb->val)
			return false;

		pa = pa->pre;
		pb = pb->pre;
	}
	return true;
}

template<typename T>
bool Stack<T>::operator!=(const Stack &orig)
{
	return !(*this == orig);
}

template<typename T>
StackNode<T>* Stack<T>::copy(const Stack &src)
{
	if(src.len <= 0) return nullptr;

	StackNode<T> *ptr, *next, *t, *psrc = src.t;
	next = new StackNode<T>(psrc->val);
	ptr = next;
	t = ptr;
	psrc = psrc->pre;

	while(psrc != nullptr)
	{
		next = new StackNode<T>(psrc->val);
		ptr->pre = next;
		ptr = next;
		psrc = psrc->pre;
	}
	ptr->pre = nullptr;
	return t;
}
#endif
