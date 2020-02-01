#include "pch.h"
#include "string1.h"
#include <cctype> //isspace()

String & String::operator=(const String & st)
{
	if (this != &st) {
		delete[] str;
		len = st.len;
		str = new char[len + 1U];
		strcpy(str, st.str);
	}
	return *this;
}

String & String::operator=(const char * s) //from C-string to String
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1U];
	strcpy(str, s);
	return *this;
}

void String::resize(size_t n)
{
	if (n != len) {
		char *temp = new char[n];
		if (n > len) {
			strcpy(temp, str);
			for (size_t i = len - 1; i < n; ++i)
				str[i] = '\0';
		}
		else { // n < len
			std::strncpy(temp, str, n - 1);
			str[n - 1] = '\0';
		}
		len = n;
		delete[]str;
		str = temp;
	}
}

String & String::operator+=(const String & s1)
{
	len += s1.len;
	char *temp = new char[len + 1U];
	strcpy(temp, str);
	delete[]str;
	str = temp;
	std::strcat(str, s1.str);

	return *this;
}

size_t String::find(char c, size_t pos) const
{
	for (; pos < len; ++pos)
		if (c == str[pos])
			return pos;
	return npos;
}

String String::operator+(const String & s1) const
{
	String s2;
	s2.len = len + s1.len;
	s2.str = new char[s2.len + 1];
	strcpy(s2.str, str);
	std::strcat(s2.str, s1.str);

	return s2;
}

istream & operator>>(istream & is, String & st) //it could be better, but...
{															//I don't know
	char temp[String::ISLIM];
	temp[String::ISLIM - 1] = '\0';

	/*is.get(temp, String::ISLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;*/

	int i;
	do {
		i = 0;
		is.get(temp[i]);
		while (i < (String::ISLIM - 2) && !std::isspace(temp[i]))
			is.get(temp[++i]);

		if (i < (String::ISLIM - 2)) {
			is.putback(temp[i]); //put whitespace after word back
			temp[i] = '\0';
		}
		st += temp;
	} while (i == (String::ISLIM - 2));

	return is;
}

istream &getline(istream & is, String & st)
{

	char temp[String::ISLIM];
	is.getline(temp, String::ISLIM);
	st = temp;
	while (is.fail() && !is.bad()) {
		if (is.eof())
			return is;
		is.clear();
		is.getline(temp, String::ISLIM);
		st += temp;
	}

	return is;
}
