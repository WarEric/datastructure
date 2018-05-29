/**
 * 单链表结构的链式队列的实现使用了模板, 
 * 为了方便操作，给队列添加一个头节点。
 *
 * by wareric@163.com
 * 2018-05-29
 */
#ifndef QUEUE_H_
#define QUEUE_H_

template<typename T> class Queue;

template<typename T> class QNode{
	friend class Queue<T>;
	public:
		QNode():next(nullptr){}
		QNode(T k):val(k), next(nullptr){}
		QNode(T k, QNode<T> *nxt):val(k), next(nxt){}
	private:
		T val;
		QNode *next;
};

template<typename T> class Queue{
	public:
		Queue():len(0), front(nullptr), rear(nullptr){front = new QNode<T>(); rear = front;}
		Queue(const Queue &orig);
		Queue<T>& operator=(const Queue &orig);
		~Queue();

		bool push(T k);
		bool pop();
		bool get(T &k);

		bool empty();
		int length(){return len;}
		bool clear();

		bool operator==(const Queue &orig);
		bool operator!=(const Queue &orig);
	private:
		void copy(const Queue &orig);
		int len;
		QNode<T> *front;
		QNode<T> *rear;

};

template<typename T>
Queue<T>::Queue(const Queue &orig)
{
	front = new QNode<T>();
	rear = front;
	len = 0;

	if(orig.len <= 0)
		return;
	else
		copy(orig);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue &orig)
{
	clear();
	if(orig.len > 0) copy(orig);

	return *this;
}

template<typename T>
Queue<T>::~Queue()
{
	clear();
	delete front;
}

template<typename T>
bool Queue<T>::push(T k)
{
	rear->next = new QNode<T>(k);
	rear = rear->next;
	len++;
	return true;
}

template<typename T>
bool Queue<T>::pop()
{
	if(len <= 0) return false;

	QNode<T> *ptr = front->next;
	if(ptr == rear)
		rear = front;
	front->next = ptr->next;
	delete ptr;
	len--;

	return true;
}

template<typename T>
bool Queue<T>::get(T &k)
{
	if(len <= 0)
		return false;

	k = front->next->val;
	return true;
}

template<typename T>
bool Queue<T>::empty()
{
	if(len <= 0) return true;
	else return false;
}

template<typename T>
bool Queue<T>::clear()
{
	QNode<T>* ptr = front->next;
	rear = front;

	while(ptr != nullptr)
	{
		front->next = ptr->next;
		delete ptr;
		len--;
		ptr = front->next;
	}
	return true;
}

template<typename T>
bool Queue<T>::operator==(const Queue &orig)
{
	if(len != orig.len) return false;

	QNode<T> *src, *dst;
	src = front->next;
	dst = orig.front->next;
	while(src != nullptr && dst != nullptr)
	{
		if(src->val != dst->val)
			return false;

		src = src->next;
		dst = dst->next;
	}
	return true;
}

template<typename T>
bool Queue<T>::operator!=(const Queue &orig)
{
	return !(*this == orig);
}

template<typename T>
void Queue<T>::copy(const Queue &orig)
{
	QNode<T> *ptr;
	ptr = orig.front->next;
	while(ptr != nullptr)
	{
		rear->next = new QNode<T>(ptr->val);
		rear = rear->next;
		len++;
		ptr = ptr->next;
	}
}
#endif
