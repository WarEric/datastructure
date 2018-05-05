/*
 * 使用数组实现的ArrayList, 仅仅是对int类型的实现，这里是头文件
 * by wareric@163.com
 * 2018-05-04
 */
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#define LIST_INIT_CAPACITY 20;

class ArrayList{
	public:
		ArrayList(unsigned int cap = LIST_INIT_CAPACITY):
			type_size(sizeof(int)), length(0), capacity(cap){ array = new int[capacity];};
		ArrayList(const ArrayList &orig);
		~ArrayList();

		bool init(unsigned int cap);
		bool destory();
		void clear();
		bool empty();
		unsigned length(){return length;}
		unsigned capacity(){return capacity;}
		int get(int i);
		int contains(int value);
		bool insert(int i, int value);
		bool push_back(int value);
		int pop_front();
		bool del(int i);
		void traverse();

		static void merge(ArrayList &dst, const ArrayList list1&, const ArraList list2&);

		ArrayList& operator=(const ArrayList &orig);
		bool operator==(const ArrayList &orig);
	private:
		bool increase(unsigned int max);

		int *array;
		unsigned int length;
		unsigned int capacity;
};
#endif
