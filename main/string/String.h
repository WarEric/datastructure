/**
 * String头文件的定义，这里采用堆分配存储结构。
 *
 * by wareric@163.com
 * 2018-05-30
 */
#ifndef STRING_H_
#define STRING_H_
#include<iostream>
class String{
	friend std::ostream& operator<<(std::ostream &os, const String &str);
//写出来运行不了，后面再研究
//friend std::istream& operator>>(std::istream &in, String &str);
	public:
		String():ch(nullptr), len(0){}
		String(char *chars);
		String(const String &str);
		String& operator=(const String &str);
		~String();

		int length();
		bool empty();
		bool clear();

		String sub(int pos, int length);

		//将str置为联接str1和str2的结果
		bool concat(const String &str1, const String &str2);
		
		//返回在pos个字符后第一次与str匹配的位置；不存在则返回负数
		int index(int pos, const String &str);

		//在pos之前插入str
		bool insert(int pos, const String &str);

		bool append(const String &str);
		bool append(const char a);
		bool del(int pos, int length);

		//置其内容为str的复制
		bool copy(const String &str);

		int compare(const String &str);
		bool operator==(const String &str);
		bool operator!=(const String &str);
	private:
		char *ch;
		int len;
};
#endif
