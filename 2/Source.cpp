#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;

class MyString {
public:
	
	int getSize() {
		return this->_s.size();		
	}
	
	MyString() {
		this->_s = "";
	}

	MyString(const char* s) {
		this->_s = "";
		char* iter = const_cast<char*>(s);		// ����������, ������
		while (*iter != '\0')					//
			_s += *iter;						//
		delete iter;							//
	}

	// ������ ��������
	MyString add(const MyString& s) {
		for (int i = 0; i < getSize(); i++)
			this->_s += *(const_cast<char*>(&s._s[i]));
	}

	MyString add(const char* s) {
		this->add(*(new MyString(s)));
	}

	// ������ ������
	int index(char c) {
		for (int i = 0; i < getSize(); i++) 
			if (this->_s[i] == c) { return i; }

		return -1;
	}

	int index(const MyString& s) {										// ���������
		
		string findMe = s._s;											//
		bool wasFound = false;											//
		
		for (int i = 0; i < (getSize() - findMe.size()); i++)	{		//					
			wasFound = true;											//
			
			for (int j = 0; j < findMe.size(); j++) 
				
				if (this->_s[i + j] != findMe[j]) { wasFound = false; }
			
			if (wasFound == true) { return i; }							//
		}																//
		return -1;														//
	}																	//

	int index(const char* s) {
		MyString* tmp = new MyString(s);								// ���������
		int rez = index(s);
		delete tmp;
		return rez;
	}

	// ������ ��������� ������� �� �������
	char get_symbol(int index) {
		return this->_s[index];
	}

	// ������ ��������� ���������
	MyString substring(int start, int end) {
		string output = "";
		for (int i = start; i < end; i++) { output += get_symbol(i); }

		return *(new MyString(output.c_str()));					// ������� ��� new, delete, this
	}

	// ����� ������ ������ � cout
	void print() {
		cout << this->_s;
	}

	~MyString() {												// ������
		_s = nullptr;
	}

private:
	string _s;
};