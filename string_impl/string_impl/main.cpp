//own implementation of string
#include "pch.h"
#include <iostream>
#include "string1.h"

int main()
{
	String s1;
	String s2{ "kebab" };

	std::cout << "give data: ";
	std::cin >> s1;

	getline(std::cin, s1);
	std::cout << s1 << '\t';
	std::cout<< s2;

	return 0;
}
