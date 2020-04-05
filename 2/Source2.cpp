#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class MyString {
public:
	string var;
	MyString() {
		this->var = "";
	};
	MyString(const char* s) {
		this->var = "";
		char* iter = const_cast<char*>(s);
		while (*iter != '\0')
			var += *iter;	
		delete iter;
	};
	// Методы сложения
	MyString add(const MyString& s) {
		for (int i = 0; i < &s.var.size; i++)
			this->var += *(const_cast<char*>(&s.var[i]));
	};
	MyString add(const char* s) {
		MyString *tmp = new MyString(s);
		this->add(*tmp);
		delete tmp;
	};
	// Методы поиска
	int index(char c) {
		for (int i = 0; i < this->var.size; i++)
			if (this->var[i] == c)
				return i;
		return -1;
	};
	int index(const MyString& s) {
		string findMe = s.var;
		bool wasFound = false;
		for (int i = 0; i < this->var.size - findMe.size; i++)
		{
			wasFound = true;
			for (int j = 0; j < findMe.size; j++)
				if (this->var[i + j] != findMe[j])
					wasFound = false;
			if (wasFound = true)
				return i;
		}
		return -1; 
	};
	int index(const char* s) {
		MyString* tmp = new MyString(s);
		int rez = index(s);
		delete tmp;
		return rez;
	};
	// Методы получения символа по индексу
	char get_symbol(int index)
	{
		return this->var[index];
	};
	// Методы получения подстроки
	MyString substring(int start, int end)
	{
		string output = "";
		for (int i = start; i < end; i++)
			output += get_symbol(i);
		return *(new MyString(output.c_str()));
	};
	// Метод вывода строки в cout
	void print() {
		cout << this->var;
	};


	
};