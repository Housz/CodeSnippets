#include <iostream>

class A
{
public:
	A(){};
	~A() {};

	virtual void func() 
	{
		std::cout << "A" << std::endl;
	}
};

class B : public A
{
public:
	virtual void func()
	{
		std::cout << "B" << std::endl;
	}
};

class C : public B
{
public:
	void func()
	{
		std::cout << "C" << std::endl;
	}
};
