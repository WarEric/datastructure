#include "Array.h"
#include "gtest/gtest.h"

namespace{

TEST(Array, SetGet)
{
	Array<int> ary{2,2};
	ary.set(1, {0,0});
	ary.set(2, {0,1});
	ary.set(3, {1,0});
	ary.set(4, {1,1});

	EXPECT_EQ(1, ary.get({0,0}));
	EXPECT_EQ(2, ary.get({0,1}));
	EXPECT_EQ(3, ary.get({1,0}));
	EXPECT_EQ(4, ary.get({1,1}));
}

TEST(Array, Equal)
{
	Array<bool> arg1({2,3});
	arg1.set(true, {0,1});
	arg1.set(true, {0,2});
	arg1.set(true, {0,3});
	arg1.set(false, {1,1});
	arg1.set(false, {1,2});
	arg1.set(false, {1,3});


	Array<bool> arg2({2,3});
	arg2.set(true, {0,1});
	arg2.set(true, {0,2});
	arg2.set(true, {0,3});
	arg2.set(false, {1,1});
	arg2.set(false, {1,2});
	arg2.set(false, {1,3});

	Array<bool> arg3({3,2});
	arg3.set(true, {0,1});
	arg3.set(true, {0,2});
	arg3.set(true, {1,0});
	arg3.set(false, {1,1});
	arg3.set(false, {2,0});
	arg3.set(false, {2,1});

	EXPECT_TRUE(arg1 == arg2);
	EXPECT_FALSE(arg1 != arg2);

	EXPECT_FALSE(arg1 == arg3);
	EXPECT_TRUE(arg1 != arg3);
}

TEST(Array, Construct){
	Array<int> ary({2,2});
	ary.set(1, {0,0});
	ary.set(2, {0,1});
	ary.set(3, {1,0});
	ary.set(4, {1,1});

	Array<int> arg1 = ary;
	EXPECT_TRUE(arg1 == ary);
	EXPECT_FALSE(arg1 != ary);

	Array<int> arg2({1,2});
	arg2.set(1, {0,0});
	arg2.set(2, {0,1});

	EXPECT_FALSE(ary == arg2);
	EXPECT_TRUE(ary != arg2);

	arg2 = arg1;
	EXPECT_TRUE(arg1 == arg2);
	EXPECT_FALSE(arg1 != arg2);
}

};
