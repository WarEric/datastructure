#include "Queue.h"
#include "gtest/gtest.h"
namespace{

TEST(QueueTest, addAnddel){
	Queue<float> myqueue;
	
	EXPECT_TRUE(myqueue.push(1.1));
	EXPECT_EQ(1, myqueue.length());
	EXPECT_TRUE(myqueue.push(2.2));
	EXPECT_EQ(2, myqueue.length());
	EXPECT_TRUE(myqueue.push(3.3));
	EXPECT_EQ(3, myqueue.length());
	EXPECT_TRUE(myqueue.push(4.4));
	EXPECT_EQ(4, myqueue.length());

	float temp;
	EXPECT_TRUE(myqueue.get(temp));
	EXPECT_EQ(temp, 1.1f);
	EXPECT_TRUE(myqueue.pop());
	EXPECT_EQ(3, myqueue.length());


	EXPECT_TRUE(myqueue.get(temp));
	EXPECT_EQ(temp, 2.2f);
	EXPECT_TRUE(myqueue.pop());
	EXPECT_EQ(2, myqueue.length());

	EXPECT_TRUE(myqueue.get(temp));
	EXPECT_EQ(temp, 3.3f);
	EXPECT_TRUE(myqueue.pop());
	EXPECT_EQ(1, myqueue.length());

	EXPECT_TRUE(myqueue.get(temp));
	EXPECT_EQ(temp, 4.4f);
	EXPECT_TRUE(myqueue.pop());
	EXPECT_EQ(0, myqueue.length());

	EXPECT_FALSE(myqueue.get(temp));
	EXPECT_FALSE(myqueue.pop());
	EXPECT_EQ(0, myqueue.length());
}

TEST(QueueTest, Equal){
	Queue<bool> queue1;
	Queue<bool> queue2;

	EXPECT_TRUE(queue1.push(true));
	EXPECT_TRUE(queue1.push(false));
	EXPECT_TRUE(queue1.push(false));
	EXPECT_TRUE(queue1.push(true));

	EXPECT_TRUE(queue2.push(true));
	EXPECT_TRUE(queue2.push(false));
	EXPECT_TRUE(queue2.push(false));
	EXPECT_TRUE(queue2.push(true));

	EXPECT_TRUE(queue1 == queue2);
	EXPECT_FALSE(queue1 != queue2);

	EXPECT_TRUE(queue1.pop());
	EXPECT_FALSE(queue1 == queue2);
	EXPECT_TRUE(queue1 != queue2);
}

TEST(QueueTest, Construct){
	Queue<int> queue1;

	EXPECT_TRUE(queue1.push(1));
	EXPECT_EQ(1, queue1.length());

	Queue<int> queue2 = queue1;
	EXPECT_TRUE(queue2 == queue1);
	EXPECT_FALSE(queue2 != queue1);

	Queue<int> queue3;
	EXPECT_TRUE(queue3.push(2));
	queue3 = queue1;
	EXPECT_TRUE(queue3 == queue1);
	EXPECT_FALSE(queue3 != queue1);
}

TEST(QueueTest, Others){
	Queue<double> myqueue;

	EXPECT_EQ(0, myqueue.length());
	EXPECT_TRUE(myqueue.empty());

	EXPECT_TRUE(myqueue.push(1));
	EXPECT_EQ(1, myqueue.length());
	EXPECT_FALSE(myqueue.empty());

	EXPECT_TRUE(myqueue.clear());
	EXPECT_EQ(0, myqueue.length());
	EXPECT_TRUE(myqueue.empty());
}

};
