#include <iostream>
#include <memory>



class Base
{
public:
	Base() {}
	Base(int n_) : n(n_) {}
	Base(const Base& other) 
	{
		std::cout << "Base copy\n";
	}

	int n;
};

class DerivedA : public Base
{
public:
	DerivedA() {}
	DerivedA(int a_) : a(a_) {}
	DerivedA(const DerivedA& other) 
		: Base(other), a(other.a)
	{
		std::cout << "DerivedA copy\n";
	}

	int a;
};

class DerivedB : public Base
{
public:
	DerivedB() {}
	DerivedB(int b_) : b(b_) {}
	DerivedB(const DerivedB& other)
		: Base(other), b(other.b) 
	{
		std::cout << "DerivedB copy\n";
	}

	int b;
};

class Container
{
public:
	Container() {}
	Container(const Container& other) 
	{
		p = std::make_shared<Base>(*(other.p));
	}

	std::shared_ptr<Base> p = nullptr;
};

int main()
{
	Container c1;
	c1.p = std::make_shared<DerivedA>()

	return 0;
}