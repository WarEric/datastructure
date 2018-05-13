#include<stdexcept>
#include<climits>
#include"LinkList.h"
using std::range_error;

LinkList::~LinkList()
{
	clear();
	if(head != nullptr) delete head;
}

LinkList::LinkList(const LinkList &orig)
{
	head = new Node(INT_MAX);
	head->next = head;
	head->pre = head;
	copy(orig);
}

LinkList& LinkList::operator=(const LinkList &orig)
{
	clear();
	copy(orig);
	return *this;
}

bool LinkList::insert_first(int k)
{
	if(head == nullptr) return false;

	Node *ptr = new Node(k);
	ptr->pre = head;
	ptr->next = head->next;
	ptr->next->pre = ptr;
	head->next = ptr;
	len++;

	return true;
}

bool LinkList::insert(int k, int pos)
{
	if(head == nullptr) return false;
	if(pos >= len) return false;

	Node *ptr = head->next;
	while(pos-- > 0)
		ptr = ptr->next;

	Node *temp = new Node(k);
	temp->next = ptr;
	temp->pre = ptr->pre;
	temp->pre->next = temp;
	ptr->pre = temp;
	len++;

	return true;
}

bool LinkList::append(int k)
{
	if(head == nullptr) return false;

	Node *ptr = new Node(k);
	ptr->next = head;
	ptr->pre = head->pre;
	ptr->pre->next = ptr;
	head->pre = ptr;
	len++;

	return true;
}

bool LinkList::del_first(int &res)
{
	if(head == nullptr) return false;
	if(len <= 0) return false;

	Node *ptr = head->next;
	head->next = head->next->next;
	head->next->pre = head;
	len--;
	res = ptr->key;
	delete ptr;
	
	return true;
}

bool LinkList::del(int &res, int pos)
{
	if(pos >= len || pos < 0) return false;
	if(head == nullptr) return false;

	Node *ptr = head->next;
	while(pos-- > 0)
		ptr = ptr->next;

	ptr->pre->next = ptr->next;
	ptr->next->pre = ptr->pre;
	res = ptr->key;
	len--;
	
	delete ptr;
	return true;
}

bool LinkList::remove_back(int &res)
{
	if(head == nullptr) return false;
	if(len <= 0) return false;

	Node *ptr = head->pre;
	head->pre = ptr->pre;
	ptr->pre->next = head;
	res = ptr->key;
	len--;
	
	delete ptr;
	return true;
}

int LinkList::get(int pos)
{
	if(pos >= len) throw range_error("pos bigger than length");
	if(pos < 0) throw range_error("pos can't be negative");

	Node *ptr = head->next;
	while(pos-- > 0)
		ptr = ptr->next;
	return ptr->key;
}

int LinkList::getLast()
{
	if(len <= 0)
	       	throw range_error("LinkList is empty, it doesn't have last one");
	return head->pre->key;
}

bool LinkList::replace(int k, int pos)
{
	if(pos >= len || pos < 0) 
		return false;
	Node *ptr = head->next;
	while(pos-- > 0)
		ptr = ptr->next;
	ptr->key = k;
	return true;
}

bool LinkList::isEmpty()
{
	if(len <= 0)
		return true;
	else
		return false;
}

int LinkList::contain(int k)
{
	int count;
	Node *ptr = head->next;
	for(int count = 0; ptr != head; count++, ptr= ptr->next)
	{
		if(ptr->key == k)
			return count;
	}

	return -1;
}

void LinkList::reversion()
{
	Node *ptr = head->next, *temp = nullptr;
	while(ptr != head)
	{
		temp = ptr->next;
		ptr->next = ptr->pre;
		ptr->pre = temp;
		ptr = ptr->pre;
	}
	temp = head->next;
	head->next = head->pre;
	head->pre = temp;
}

bool LinkList::clear()
{
	Node *cur = head->next, *ptr = nullptr;
	while(cur != head)
	{
		ptr = cur;
		cur = cur->next;
		delete ptr;
		len--;
	}

	head->next = head;
	head->pre = head;
	if(len == 0)
		return true;
	else 
		return false;
}

bool LinkList::copy(const LinkList &orig)
{
	if(orig.head == nullptr) return false;

	Node *src = orig.head->next, *temp = nullptr;
	while(src != orig.head)
	{
		temp = new Node(src->key);
		temp->next = head;
		temp->pre = head->pre;
		temp->pre->next = temp;
		head->pre = temp;
		len++;
		src = src->next;
	}
	return true;
}

bool LinkList::operator==(const LinkList &orig)
{
	if(len != orig.len) return false;
	if(this == &orig) return true;

	Node *la = head->next, *lb = orig.head->next;
	while(la != head)
	{
		if(la->key != lb->key)
			return false;
		la = la->next;
		lb = lb->next;
	}

	return true;
}

bool LinkList::operator!=(const LinkList &orig)
{
	return !(*this == orig);
}	

bool LinkList::merge(LinkList &la, LinkList &lb, LinkList &dst)
{
	if(!dst.clear()) return false;

	Node *ptr = la.head->next;
	while(ptr != la.head)
	{
		dst.append(ptr->key);
		ptr = ptr->next;
	}

	ptr = lb.head->next;
	while(ptr != lb.head)
	{
		dst.append(ptr->key);
		ptr = ptr->next;
	}
}
