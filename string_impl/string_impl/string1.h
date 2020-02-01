#ifndef STRING1_H
#define STRING1_H
#include <cstring> //size_t
#include <iostream>
using std::strcpy;
using std::istream;

class String //TODO: allocate more memory for chars to add to the string
{
	//size_t m_capcity; //size of allocated storage
	size_t len; //length of string
	char *str;
	static constexpr size_t ISLIM = 80U; //limit of characters from input
public:

	//constructors
	String() : len(0U), str(new char[1]) { str[0] = '\0'; }
	String(const String &s) : len(s.len), str(new char[len + 1]) { strcpy(str, s.str); }
	String(const char * s) : len(std::strlen(s)), str(new char[len + 1]) { strcpy(str, s); }
	String(String &&s) : len(s.len), str(s.str) { s.str = nullptr; }

	//destructor
	~String() { delete[] str; }


	//member functions
	String & operator=(const String &st);
	String & operator=(const char *s); //C-string

	//capacity
	size_t length() const { return len; }
	size_t max_size() const { return npos; }
	void resize(size_t n);

	//access to the element
	char & operator[](size_t i) { return str[i]; }
	const char & operator[](size_t i) const { return str[i]; }

	//modifying
	String &operator+=(const String &s1);
	String &operator+=(const char *sz) { return (*this) += String(sz); } //C-string

	//operations on String
	const char *c_str()const { return str; }
	const char *data()const { return str; }
	size_t find(char c, size_t pos = 0U) const;
	size_t find_first_of(char c, size_t pos = 0U) const { find(c, pos); }


	//member constants
	static constexpr size_t npos{ static_cast<size_t>(-1) }; //maximum value for size_t


	//operators overload
	String operator+(const String &s1) const;
	String operator+(const char *sz) const { return (*this) + String(sz); } //C-string

	//friend operators overload
	friend String operator+	(const char *sz,	const String &s) { return String(sz) + s; } //C-string

	//relational operators
	friend bool operator==	(const String &st1, const String &st2) { return st1.len == st2.len && !std::strcmp(st1.str, st2.str); }
	friend bool operator!=	(const String &st1, const String &st2) { return st1.len != st2.len && static_cast<bool>(std::strcmp(st1.str, st2.str)); }
	friend bool operator<	(const String &st1, const String &st2) { return std::strcmp(st1.str, st2.str) < 0; }
	friend bool operator<=	(const String &st1, const String &st2) { return std::strcmp(st1.str, st2.str) <= 0; }
	friend bool operator>	(const String &st1, const String &st2) { return st2 < st1; }
	friend bool operator>=	(const String &st1, const String &st2) { return st2 <= st1; }

	//streams
	friend istream & operator>>(istream & is, String & st);
	friend std::ostream & operator<<(std::ostream & os, const String & st) { return os << st.str; }
	friend istream & getline(istream & is, String & st);
};

#endif // !STRING1_H
