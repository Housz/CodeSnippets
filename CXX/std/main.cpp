#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>

template <typename T>
void print(std::vector<T>& v)
{
	for(auto ele : v)
	{
		std::cout << ele << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> v1(5);
	std::vector<int> v2(5);

	std::fill(v1.begin(), v1.end(), 1);
	std::fill(v2.begin(), v2.end(), 2);

	print(v1);
	print(v2);

	std::swap(v1, v2);

	print(v1);
	print(v2);
	
	return 0;
}