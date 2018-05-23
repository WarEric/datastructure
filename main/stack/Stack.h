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
		Stack():len(0), top(nullptr){}
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
		StackNode<T> *top;
};

template<typename T>
Stack<T>::Stack(const Stack &orig)
{
	if(orig.len <= 0) 
		return;

	len = orig.len;
	top = copy(orig);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack &orig)
{
	if(orig.len <= 0)
		return *this;

	len = orig.len;
	top = copy(orig);
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

	Node<T> *ptr = top;
	while(top != nullptr)
	{
		ptr = top;
		top = top->pre;
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

	val = top->val;
	return true;
}

template<typename T>
bool Stack<T>::push(const T& val)
{
	StackNode<T> *ptr = new StackNode<T>(val, top);
	top = ptr;
	len++;
	return true;
}

template<typename T>
bool Stack<T>::pop()
{
	if(len <= 0)
	       	return false;

	StackNode<T> *ptr = top;
	top = top->pre;
	delete ptr;
	len--;
	return true;
}

template<typename T>
bool Stack<T>::operator==(const Stack &orig)
{
	if(len != orig.len)
		return false;

	StackNode<T> *pa = top, *pb = orig.top;
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

	StackNode<T> *ptr, *next, *t, *psrc = src.top;
	next = new StackNode<T>(psrc->val);
	ptr = next;
	t = ptr;
	psrc = psrc;
	len++;

	while(psrc != nullptr)
	{
		next = new StackNode<T>(psrc->val);
		ptr->pre = next;
		ptr = next;
		len++;
	}
	return t;
}
#endif
