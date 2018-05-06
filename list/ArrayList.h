/*
 * 使用数组实现的ArrayList, 仅仅是对int类型的实现，这里是头文件
 * by wareric@163.com
 * 2018-05-04
 */
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#define LIST_INIT_CAPACITY 20

class ArrayList{
	public:
		ArrayList(unsigned int capacity = LIST_INIT_CAPACITY):
			len(0), cap(capacity){ array = new int[capacity];};
		ArrayList(const ArrayList &orig);
		~ArrayList();

		bool init(unsigned int cap);
		bool destroy();
		void clear();
		bool empty();
		unsigned int length() const{return len;}
		unsigned int capacity() const{return cap;}
		int get(int i);
		int contains(int value);
		bool insert(int i, int value);
		bool push_back(int value);
		int pop_front();
		bool del(int i);
		void traverse();

		static void merge(ArrayList &dst, const ArrayList &list1, const ArrayList &list2){
			dst.destroy();
			dst.init(list1.length() + list2.length());
			int *ptr = dst.array;

			for(int i = 0, len = list1.length(); i < len; i++)
				*ptr++ = list1.array[i];

			for(int i = 0, len = list2.length(); i < len; i++)
				*ptr++ = list2.array[i];
		}

		ArrayList& operator=(const ArrayList &orig);
		bool operator==(const ArrayList &orig);
	private:
		bool increase(unsigned int max);

		int *array;
		unsigned int len;
		unsigned int cap;
};
#endif
