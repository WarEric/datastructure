#include "ArrayList.h"
#include "gtest/gtest.h"
namespace{

TEST(ArrayList, Constrcut){
	ArrayList l1(2), l2;
	
	EXPECT_EQ(2, l1.capacity());
	EXPECT_EQ(LIST_INIT_CAPACITY, l2.capacity());

	EXPECT_TRUE(l1.push_back(1));
	EXPECT_TRUE(l1.push_back(2));
	EXPECT_TRUE(l1.push_back(3));

	EXPECT_EQ(4, l1.capacity());

	EXPECT_FALSE(l2 == l1);
	EXPECT_TRUE(l2 != l1);

	ArrayList l3 = l1;

	EXPECT_TRUE(l1 == l3);
	EXPECT_FALSE(l1 != l3);

	l2 = l1;
	EXPECT_TRUE(l2 == l1);
	EXPECT_FALSE(l2 != l1);
}

TEST(ArrayList, Insert){
	ArrayList l1;

	EXPECT_TRUE(l1.push_back(1));
	EXPECT_TRUE(l1.push_back(2));
	EXPECT_TRUE(l1.push_back(3));

//	EXPECT_FALSE(l1.insert(3, 100));
//	EXPECT_FALSE(l1.insert(-1, 100));

	EXPECT_TRUE(l1.insert(1, 4));
	
	EXPECT_EQ(1, l1.get(0));
	EXPECT_EQ(4, l1.get(1));
	EXPECT_EQ(2, l1.get(2));
	EXPECT_EQ(3, l1.get(3));

//	EXPECT_EQ(-1, l1.get(-1));
//	EXPECT_EQ(-1, l1.get(4));
}

TEST(ArrayList, Delete){
	ArrayList list;

	EXPECT_TRUE(list.push_back(1));
	EXPECT_TRUE(list.push_back(2));
	EXPECT_TRUE(list.push_back(3));

	EXPECT_EQ(1, list.pop_front());
	EXPECT_EQ(2, list.get(0));

	EXPECT_FALSE(list.del(-1));
	EXPECT_FALSE(list.del(2));

	EXPECT_TRUE(list.del(1));
	EXPECT_EQ(1, list.length());
}

TEST(ArrayList, Merge){
	ArrayList la, lb, dst;

	EXPECT_TRUE(la.push_back(1));
	EXPECT_TRUE(la.push_back(2));
	EXPECT_TRUE(la.push_back(3));

	EXPECT_TRUE(lb.push_back(5));
	EXPECT_TRUE(lb.push_back(6));
	EXPECT_TRUE(lb.push_back(7));

	ArrayList::merge(dst, la, lb);
	EXPECT_EQ(1, dst.get(0));
	EXPECT_EQ(2, dst.get(1));
	EXPECT_EQ(3, dst.get(2));
	EXPECT_EQ(5, dst.get(3));
	EXPECT_EQ(6, dst.get(4));
	EXPECT_EQ(7, dst.get(5));
}

TEST(ArrayList, Others){
	ArrayList list;

	EXPECT_TRUE(list.empty());
	EXPECT_EQ(0, list.length());

	EXPECT_TRUE(list.push_back(1));
	EXPECT_EQ(1, list.length());

	EXPECT_TRUE(list.push_back(2));
	EXPECT_EQ(2, list.length());

	EXPECT_TRUE(list.push_back(3));
	EXPECT_EQ(3, list.length());

	EXPECT_EQ(0, list.contains(1));
	EXPECT_EQ(-1, list.contains(0));

	EXPECT_FALSE(list.empty());
	list.clear();
	EXPECT_TRUE(list.empty());

	EXPECT_TRUE(list.destroy());
	EXPECT_TRUE(list.init(2));
	EXPECT_EQ(2, list.capacity());

	EXPECT_TRUE(list.push_back(1));
	EXPECT_TRUE(list.push_back(2));
	EXPECT_TRUE(list.push_back(3));

	list.reversion();
	EXPECT_EQ(3, list.get(0));
	EXPECT_EQ(2, list.get(1));
	EXPECT_EQ(1, list.get(2));
}

};
