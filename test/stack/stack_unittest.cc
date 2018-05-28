#include "Stack.h"
#include "gtest/gtest.h"
namespace{

TEST(StackTest, addAnddel){
	Stack<float> mystack;
	
	EXPECT_TRUE(mystack.push(1.1));
	EXPECT_EQ(1, mystack.length());
	EXPECT_TRUE(mystack.push(2.2));
	EXPECT_EQ(2, mystack.length());
	EXPECT_TRUE(mystack.push(3.3));
	EXPECT_EQ(3, mystack.length());
	EXPECT_TRUE(mystack.push(4.4));
	EXPECT_EQ(4, mystack.length());

	float temp;
	EXPECT_TRUE(mystack.top(temp));
	EXPECT_EQ(temp, 4.4f);
	EXPECT_TRUE(mystack.pop());
	EXPECT_EQ(3, mystack.length());

	EXPECT_TRUE(mystack.top(temp));
	EXPECT_EQ(temp, 3.3f);
	EXPECT_TRUE(mystack.pop());
	EXPECT_EQ(2, mystack.length());

	EXPECT_TRUE(mystack.top(temp));
	EXPECT_EQ(temp, 2.2f);
	EXPECT_TRUE(mystack.pop());
	EXPECT_EQ(1, mystack.length());

	EXPECT_TRUE(mystack.top(temp));
	EXPECT_EQ(temp, 1.1f);
	EXPECT_TRUE(mystack.pop());
	EXPECT_EQ(0, mystack.length());

	EXPECT_FALSE(mystack.top(temp));
	EXPECT_FALSE(mystack.pop());
	EXPECT_EQ(0, mystack.length());
}

TEST(StackTest, Equal){
	Stack<bool> stack1;
	Stack<bool> stack2;

	EXPECT_TRUE(stack1.push(true));
	EXPECT_TRUE(stack1.push(false));
	EXPECT_TRUE(stack1.push(false));
	EXPECT_TRUE(stack1.push(true));

	EXPECT_TRUE(stack2.push(true));
	EXPECT_TRUE(stack2.push(false));
	EXPECT_TRUE(stack2.push(false));
	EXPECT_TRUE(stack2.push(true));

	EXPECT_TRUE(stack1 == stack2);
	EXPECT_FALSE(stack1 != stack2);

	EXPECT_TRUE(stack1.pop());
	EXPECT_FALSE(stack1 == stack2);
	EXPECT_TRUE(stack1 != stack2);
}

TEST(StackTest, Construct){
	Stack<int> stack1;

	EXPECT_TRUE(stack1.push(1));
	EXPECT_EQ(1, stack1.length());

	Stack<int> stack2 = stack1;
	EXPECT_TRUE(stack2 == stack1);
	EXPECT_FALSE(stack2 != stack1);

	Stack<int> stack3;
	EXPECT_TRUE(stack3.push(2));
	stack3 = stack1;
	EXPECT_TRUE(stack3 == stack1);
	EXPECT_FALSE(stack3 != stack1);
}

TEST(StackTest, Others){
	Stack<double> mystack;

	EXPECT_EQ(0, mystack.length());
	EXPECT_TRUE(mystack.empty());

	EXPECT_TRUE(mystack.push(1));
	EXPECT_EQ(1, mystack.length());
	EXPECT_FALSE(mystack.empty());

	EXPECT_TRUE(mystack.clear());
	EXPECT_EQ(0, mystack.length());
	EXPECT_TRUE(mystack.empty());
}

};
