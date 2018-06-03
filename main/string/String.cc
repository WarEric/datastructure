/**
 * String相关函数的实现
 *
 * by wareric@163.com
 * 2018-05-30
 */
#include <cstdlib>
#include "String.h"

String::String(char *chars)
{
	int i = 0;
	for(char* c = chars; *c != '\0'; ++i, ++c);

	if(i <= 0){ 
		ch = nullptr; 
		len = 0;
	}else{
		ch = (char *)malloc(i * sizeof(char));
		if(ch == nullptr)
			exit(EXIT_FAILURE);
		
		for(int j = 0; j < i; j++)
			ch[j] = chars[j];

		len = i;
	}
}

String::String(const String &str):ch(nullptr), len(0)
{
	copy(str);
}

String& String::operator=(const String &str)
{
	copy(str);
	return *this;
}

String::~String()
{
	clear();
}

int String::length()
{
	return len;
}

bool String::empty()
{
	if(len <= 0)
		return true;
	else
		return false;
}

bool String::clear()
{
	if(ch != nullptr){
	       	free(ch);
		ch = nullptr;
	}
	len = 0;
	return true;
}

String String::sub(int pos, int length)
{
	if(pos < 0 || pos >= len || length <= 0 || length > len-pos)
		return String();


	String str;
	if(!(str.ch = (char *)malloc(length * sizeof(char))))
		exit(EXIT_FAILURE);

	for(int i = 0; i < length; i++)
		str.ch[i] = ch[pos+i];
	str.len = length;

	return str;
}

bool String::concat(const String &str1, const String &str2)
{
	clear();
	if(!(ch = (char *)malloc((str1.len + str2.len) * sizeof(char))))
		exit(EXIT_FAILURE);
	
	int i, size;
	char *chars = str1.ch;
	for(i = 0, size = str1.len; i < size; i++, chars++)
		ch[i] = *chars;

	chars = str2.ch;
	for(size += str2.len; i < size; i++, chars++)
		ch[i] = *chars;

	len  = size;
}

int String::index(int pos, const String &str)
{
	int i = pos, j = 0;
	while(i < len && j < str.len)
	{
		if(ch[i] == str.ch[j])
		{
			++i;
			++j;
		}else{
			i = i-j+1;
			j = 0;
		}
	}

	if(j >= str.len) return i - str.len;
	else return -1;
}

bool String::insert(int pos, const String &str)
{
	if(pos < 0 || pos > len) return false;

	if(str.len)
	{
		if(ch == nullptr)
		{
			if(!(ch = (char *)malloc((len+str.len) * sizeof(char))))
				exit(EXIT_FAILURE);
			
			len  = str.len;
			char *chars = str.ch;
			for(int i = 0; i < len; i++)
				ch[i] = chars[i];
		}else{
			if(!(ch = (char *)realloc(ch, (len+str.len) * sizeof(char))))
				exit(EXIT_FAILURE);

			for(int i = len-1, size = str.len; i >= pos; i--)
				ch[i+size] = ch[i];

			char *chars = str.ch;
			for(int i = 0, size = str.len; i < size; i++)
				ch[i+pos] = chars[i];
			
			len += str.len;
		}
	}

	return true;
}

bool String::append(const String &str)
{
	len += str.len;
	if(str.len)
	{
		if(ch == nullptr)
		{
			if(!(ch = (char *)malloc(len * sizeof(char))))
				exit(EXIT_FAILURE);
		}else{
			if(!(ch = (char *)realloc(ch, len * sizeof(char))))
				exit(EXIT_FAILURE);
		}

		char *chars = str.ch;
		for(int i = len-str.len; i < len; i++, chars++)
			ch[i] = *chars;
	}

	return true;
}

bool String::del(int pos, int length)
{
	if(pos < 0 || pos >= len || length < 0 || length > len-pos)
		return false;

	if(length == 0)
	       	return true;

	for(int i = pos, end = len-length; i < end; i++)
		ch[i] = ch[i+length];
	len -= length;
	
	if(!len)
	{
		free(ch);
		ch = nullptr;
	}

	return true;
}

bool String::copy(const String &str)
{
	if(!clear()) return false;

	len = str.len;
	if(!len){
		ch = nullptr;
	}else{
		ch = (char *)malloc(len * sizeof(char));
		if(!ch)
			exit(EXIT_FAILURE);

		for(int j = 0; j < len; j++)
			ch[j] = str.ch[j];
	}
	return true;
}

int String::compare(const String &str)
{
	for(int i = 0; i < len && i < str.len; i++)
		if(ch[i] != str.ch[i]) return ch[i] - str.ch[i];
	return len - str.len;
}

bool String::operator==(const String &str)
{
	if(compare(str) == 0)
		return true;
	else
		return false;
}

bool String::operator!=(const String &str)
{
	return !(*this == str);
}
