#include <iostream>
#include <memory>

int main()
{
	int a = 1;
	int &b = a;
	int &c = b;
	int *p = &a;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
	std::cout << p << std::endl;
	return 0;
}