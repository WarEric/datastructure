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

		bool init();
		bool destory();
		bool clear();
		bool empty();

		int length();
		bool top(T&);
		bool push(const T& val);
		bool pop();

		bool operator==(const Stack &orig);
		bool operator!=(const Stack &orig);
	private:
		StackNode<T>* copy(const Stack &orig);
		int len;
		StackNode<T> *top;
};
#endif
