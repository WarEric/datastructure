/*
 * 使用双向链表实现的list, 其中有些函数的名称可能有变化
 * by wareric@163.com
 * 2018-05-12
 */
#ifndef LINKLIST_H_
#define LINKLIST_H_
#include<climits>

struct Node{
	friend class LinkList;
	public:
		Node(int k):key(k), pre(nullptr), next(nullptr){}
	private:
		int key;
		Node *pre;
		Node *next;
};

class LinkList{
	public:
		LinkList():head(nullptr), len(0){ head = new Node(INT_MAX);
		       	head->next = head; head->pre = head;}
		~LinkList();
		LinkList(const LinkList &orig);
		LinkList& operator=(const LinkList &orig);

		bool insert_first(int k);
		bool insert(int k, int pos);
		bool append(int k);

		bool del_first(int &res);//res返回删除的值,默认删除首部
		bool del(int &res, int pos);
		bool remove_back(int &res);

		int get(int pos);
		int getLast();
		bool replace(int k, int pos);
		bool isEmpty();
		int getLength(){return len;}
		int contain(int k);//-1 表示不存在
		void reversion();

		bool clear();

		bool operator==(const LinkList &orig);
		bool operator!=(const LinkList &orig);

		static bool merge(LinkList &la, LinkList &lb, LinkList &dst);
	private:
		bool copy(const LinkList &orig);

		Node *head;
		int len;
};
#endif
