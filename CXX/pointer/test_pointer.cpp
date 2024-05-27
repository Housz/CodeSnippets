#include <iostream>
#include <memory>

// int main()
// {
// 	int a = 1;
// 	int &b = a;
// 	int &c = b;
// 	int *p = &a;
// 	std::cout << &a << std::endl;
// 	std::cout << &b << std::endl;
// 	std::cout << &c << std::endl;
// 	std::cout << p << std::endl;
// 	return 0;
// }

class A
{
public:
	A()
	{
		std::cout << "construct A\n";
	}

	int n;
};

using A_ptr = std::shared_ptr<A>;

void func(A_ptr a_)
{
	std::cout << a_.use_count() << "\n";

	// auto a = a_;
	A_ptr a = nullptr;
	a = a_;
	std::cout << a.use_count() << "\n";
}

void func2(const A_ptr& a_)
{
	std::cout << a_.use_count() << "\n";

	// auto a = a_;
	A_ptr a = nullptr;
	a = a_;

	a->n = 1;
	
	std::cout << a.use_count() << "\n";
}


int main()
{
	auto a = std::make_shared<A>();

	std::cout << a.use_count() << "\n";

	// func(a);
	func2(a);
	
	return 0;
}
