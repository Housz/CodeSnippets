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

	virtual void draw() 
	{
		std::cout << "Base draw\n";
	}

	virtual void clone(std::shared_ptr<Base>& p)
	{
	}

	int n = 0;
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

	void draw() override
	{
		std::cout << "DerivedA: a = " << a << " n = " << n << std::endl;
	}

	void clone(std::shared_ptr<Base>& p) override
	{
		p = std::make_shared<DerivedA>(a);
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

	void draw() override
	{
		std::cout << "DerivedB: b = " << b << " n = " << n << std::endl;
	}

	void clone(std::shared_ptr<Base>& p) override
	{
		p = std::make_shared<DerivedB>(b);
	}

	int b;
};

class Container
{
public:
	Container() {}
	Container(const Container& other) 
	{
		// p = std::make_shared<Base>(*(other.p));
		other.p->clone(p);
	}

	std::shared_ptr<Base> p = nullptr;
};

int main()
{
	Container c1;
	c1.p = std::make_shared<DerivedA>(1);
	c1.p->draw();

	Container c2(c1);
	c2.p->draw();
	auto pc = std::static_pointer_cast<DerivedA>(c2.p);
	pc->draw();


	

	return 0;
}