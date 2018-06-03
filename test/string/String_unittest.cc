#include "String.h"
#include "gtest/gtest.h"
namespace{

TEST(String, Length){
	String str1;
	EXPECT_EQ(0, str1.length());

	String str2("test");
	EXPECT_EQ(4, str2.length());
	
	str2.clear();
	EXPECT_EQ(0, str2.length());
}

TEST(String, Empty){
	String str1;
	EXPECT_TRUE(str1.empty());

	String str2("not empty");
	EXPECT_FALSE(str2.empty());
}


TEST(String, Clear){
	String str("this is test");
	EXPECT_TRUE(str.clear());
	EXPECT_TRUE(str.empty());
}

TEST(String, Compare){
	String str1;
	String str2("abc");
	String str3("abcd");
	String str4("bbb");
	String str5("bbb");

	EXPECT_EQ(0, str1.length());
	EXPECT_EQ(3, str2.length());
	EXPECT_EQ(4, str3.length());
	EXPECT_EQ(3, str4.length());
	EXPECT_EQ(3, str5.length());

	EXPECT_EQ(-3, str1.compare(str2));
	EXPECT_EQ(3,  str2.compare(str1));

	EXPECT_EQ(-1, str2.compare(str3));
	EXPECT_EQ(1,  str3.compare(str2));

	EXPECT_EQ(-1, str2.compare(str4));
	EXPECT_EQ( 1, str4.compare(str2));

	EXPECT_EQ(0, str4.compare(str5));
	EXPECT_EQ(0, str5.compare(str4));
}

TEST(String, Equal){
	String str1("This is test");
	String str2("This is test");
	String str3("This isn't test");
	String str4("This is text");

	EXPECT_TRUE(str1 == str2);
	EXPECT_FALSE(str1 != str2);

	EXPECT_FALSE(str1 == str3);
	EXPECT_TRUE(str1 != str3);

	EXPECT_FALSE(str1 == str4);
	EXPECT_TRUE(str1 != str4);

	EXPECT_FALSE(str3 == str4);
	EXPECT_TRUE(str3 != str4);
}

TEST(String, Copy){
	String str1("adc");
	String str2("123");

	EXPECT_TRUE(str1.copy(str2));
	EXPECT_TRUE(str1 == str2);
}

TEST(String, Construct){
	String str1;

	EXPECT_EQ(0, str1.length());
	EXPECT_TRUE(str1.empty());

	String str2("test");
	EXPECT_EQ(4, str2.length());
	EXPECT_FALSE(str2.empty());

	String str3(str2);
	EXPECT_TRUE(str2 == str3);
	EXPECT_FALSE(str2 != str3);

	String str4 = str3;
	EXPECT_TRUE(str3 == str4);
	EXPECT_FALSE(str3 != str4);

	String str5;
	str5 = str4;
	EXPECT_TRUE(str5 == str4);
	EXPECT_FALSE(str5 != str4);
}

TEST(String, Del){
	String str1("123456");
	String str2("23456");

	EXPECT_TRUE(str1.del(0,1));
	EXPECT_TRUE(str1 == str2);

	EXPECT_TRUE(str1.del(4, 1));
	EXPECT_TRUE(str2.del(4, 1));
	EXPECT_TRUE(str1 == str2);

	EXPECT_TRUE(str2.del(1,2));
	EXPECT_EQ(2, str2.length());
}

TEST(String, Insert){
	String str1;
	String str2("abc");
	String str3("aabcbc");
	String str4;

	EXPECT_TRUE(str1.append(str2));
	EXPECT_TRUE(str1 == str2);

	EXPECT_TRUE(str1.insert(1, str2));
	EXPECT_TRUE(str1 == str3);

	EXPECT_TRUE(str4.insert(0,str2));
	EXPECT_TRUE(str4 == str2);
}

TEST(String, Index){
	String str1("123456123456");
	String str2("456");
	String str3("abc");

	EXPECT_EQ(3, str1.index(0, str2));
	EXPECT_EQ(9, str1.index(6, str2));
	EXPECT_GT(0, str1.index(0, str3));
}

TEST(String, Concat){
	String str;
	String str1("abcd");
	String str2("123");
	String str3("456");
	String str4("123456");

	EXPECT_TRUE(str.concat(str2, str3));
	EXPECT_TRUE(str == str4);
	EXPECT_TRUE(str1.concat(str2, str3));
	EXPECT_TRUE(str1 == str4);
}

TEST(String, sub){
	String str1("abcdefg");
	String str2("cde");
	String empty;

	String str3;
	str3 = str1.sub(2,3);
	EXPECT_TRUE(str3 == str2);

	str3 = str1.sub(2, 10);
	EXPECT_TRUE(str3 == empty);
}

};
