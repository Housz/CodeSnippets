#include <iostream>
#include <vector>
#include <tbb/parallel_for.h>
#include <tbb/parallel_for_each.h>

int main()
{

	// size_t n = 1 << 26;
	size_t n = 10;
	std::vector<float> v(n);

	// parallel_for

	tbb::parallel_for((size_t)0, (size_t)n, [&] (size_t i) {
		v[i] = (float)i;
	});

	for (auto &&i : v)
	{
		std::cout << i << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	// parallel_for_each

	tbb::parallel_for_each(v.begin(), v.end(), [&](float &f){
		f += 1;
	});

	for (auto &&i : v)
	{
		std::cout << i << std::endl;
	}

	
	return 0;
}