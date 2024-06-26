#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>

template <typename T>
void printVector(const std::vector<T> &v)
{
	for (auto ele : v)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;
}

struct A
{
	int a;
	float b;
};

class B
{
public:
	B() {}
	~B() {}

	static std::shared_ptr<A> a;
};

std::shared_ptr<A> B::a = std::make_shared<A>();

int main()
{
	std::vector<int> v(10);
	// std::iota(std::begin(v), std::end(v), 0);
	std::iota(v.begin(), v.end(), 0);
	// printVector(v);

	// std::swap(v[0], v[1]);
	// printVector(v);

	// std::swap
	// auto iter = v.begin();
	// std::swap(*iter, *(iter+1));
	// printVector(v);
	// std::cout << *(v.begin()) << std::endl;
	// std::cout << *iter << std::endl;


	// auto iter = v.begin();
	// iter += (v.end() - v.begin()) / 2;
	// std::cout << *iter;
	
	return 0;
}