//own implementation of string
#include "pch.h"
#include <iostream>
#include "string1.h"
#include <string>

int main()
{
	String s1;
	

	std::cout << "give data: ";
	std::cin >> s1;

	//getline(std::cin, s1);
	std::cout << s1 << '\t';
	char c;
	std::cin.get(c);
	std::cout << (int)c;

	String s2{ "kebab" };
	std::cout<< s2;

	//String s3;
	//s3.resize(1294967294U);

	std::string elo;
	elo.find('e');
	elo.find_first_of('e');

	return 0;
}
