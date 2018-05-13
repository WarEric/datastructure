#include "LinkList.h"
#include "gtest/gtest.h"
namespace {

TEST(LinkList, ConstructorAndEqual){
	LinkList l1, l3;

	EXPECT_EQ(0, l1.getLength());
	
	l1.append(1);
	l1.append(2);
	LinkList l2 = l1;
	l3 = l1;

	EXPECT_EQ(2, l2.getLength());
	EXPECT_EQ(2, l3.getLength());

	EXPECT_TRUE(l2 == l1);
	EXPECT_FALSE(l2 != l1);

	EXPECT_TRUE(l3 == l1);
	EXPECT_FALSE(l3 != l1);

	EXPECT_TRUE(l2 == l3);
	EXPECT_FALSE(l2 != l3);

	int temp;
	l3.remove_back(temp);
	l2.append(3);

	EXPECT_TRUE(l1 != l2);
	EXPECT_FALSE(l1 == l2);

	EXPECT_TRUE(l1 != l3);
	EXPECT_FALSE(l1 == l3);

	EXPECT_TRUE(l2 != l3);
	EXPECT_FALSE(l2 == l3);
}

TEST(LinkList, InsertAndGet){
	LinkList list;

	EXPECT_TRUE(list.append(1));
	EXPECT_TRUE(list.insert_first(2));
	EXPECT_TRUE(list.insert(3, 1));
	EXPECT_TRUE(list.append(4));
	EXPECT_FALSE(list.insert(-1, 5));
	EXPECT_FALSE(list.insert(4, 5));

	EXPECT_EQ(4, list.getLength());
	
	EXPECT_EQ(2, list.get(0));
	EXPECT_EQ(3, list.get(1));
	EXPECT_EQ(1, list.get(2));
	EXPECT_EQ(4, list.get(3));

	EXPECT_EQ(4, list.getLast());
}

TEST(LinkList, Delete){
	LinkList list;
	
	EXPECT_TRUE(list.append(1));
	EXPECT_TRUE(list.append(2));
	EXPECT_TRUE(list.append(3));
	EXPECT_TRUE(list.append(4));

	int res;
	EXPECT_TRUE(list.del_first(res));
	EXPECT_EQ(1, res);

	EXPECT_TRUE(list.del(res, 1));
	EXPECT_EQ(3, res);

	EXPECT_TRUE(list.remove_back(res));
	EXPECT_EQ(4, res);

	EXPECT_FALSE(list.del(res, 1));
	EXPECT_FALSE(list.del(res, -1));

	EXPECT_TRUE(list.remove_back(res));
	EXPECT_EQ(2, res);

	EXPECT_FALSE(list.remove_back(res));

	EXPECT_EQ(0, list.getLength());
}

TEST(LinkList, Merge){
	LinkList la, lb;

	EXPECT_TRUE(la.append(1));
	EXPECT_TRUE(la.append(2));
	EXPECT_TRUE(la.append(3));
	EXPECT_TRUE(la.append(4));

	EXPECT_TRUE(lb.append(7));
	EXPECT_TRUE(lb.append(8));
	EXPECT_TRUE(lb.append(9));
	EXPECT_TRUE(lb.append(10));

	LinkList lc;

	EXPECT_TRUE(LinkList::merge(la, lb, lc));

	EXPECT_EQ(8, lc.getLength());
	EXPECT_EQ(1, lc.get(0));
	EXPECT_EQ(2, lc.get(1));
	EXPECT_EQ(3, lc.get(2));
	EXPECT_EQ(4, lc.get(3));
	EXPECT_EQ(7, lc.get(4));
	EXPECT_EQ(8, lc.get(5));
	EXPECT_EQ(9, lc.get(6));
	EXPECT_EQ(10, lc.get(7));

}

TEST(LinkList, Others){
	LinkList list;

	EXPECT_TRUE(list.append(1));
	EXPECT_TRUE(list.append(2));
	EXPECT_TRUE(list.append(3));
	EXPECT_TRUE(list.append(4));

	EXPECT_TRUE(list.replace(5, 0));
	EXPECT_EQ(5, list.get(0));

	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(4, list.getLength());

	EXPECT_EQ(0, list.contain(5));
	EXPECT_EQ(1, list.contain(2));
	EXPECT_EQ(2, list.contain(3));
	EXPECT_EQ(3, list.contain(4));
	EXPECT_EQ(-1, list.contain(1));

	list.reversion();
	EXPECT_EQ(4, list.get(0));
	EXPECT_EQ(3, list.get(1));
	EXPECT_EQ(2, list.get(2));
	EXPECT_EQ(5, list.get(3));
}

};
