#include <functional>
#include <iostream>


void sayHi(int i)
{
	std::cout << "hello " << i << std::endl;
}

int main()
{
	// auto f_sayHi = sayHi;
	std::function<void(int)> f_sayHi = sayHi;
	f_sayHi(1);

	return 0;
}