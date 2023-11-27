#include <iostream>
#include <vector>
#include <tbb/parallel_for.h>
#include <tbb/parallel_for_each.h>

int main()
{

	std::vector<double> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	tbb::parallel_for_each(v.begin(), v.end(), [](auto i){
		std::cout << i << std::endl;
	});
	
	return 0;
}