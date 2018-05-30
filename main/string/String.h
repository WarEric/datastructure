/**
 * String头文件的定义，这里采用堆分配存储结构。
 *
 * by wareric@163.com
 * 2018-05-30
 */
#ifndef STRING_H_
#define STRING_H_
class String{
	public:
		String():ch(nullptr), len(0){}
		String(char *chars);
		String(const String &str);
		String& operator=(const String &str);
		~String();

		int length();
		bool empty();
		bool clear();

		String sub(int pos, int len);

		//将str置为联接str1和str2的结果
		bool concat(const String &str1, const String &str2);
		
		//返回在pos个字符后第一次与str匹配的位置；否则为0
		int index(int pos, const String &str);
		
		//将其中与match匹配的串替换为target中的串
		bool replace(const String &match, const String &target);

		//在pos之前插入str
		bool insert(int pos, const String &str);

		bool append(const String &str);
		bool del(int pos, int len);

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
