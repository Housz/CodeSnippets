#include <iostream>
#include <cmath>
#include <algorithm>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>

// sum sin(0 ~ n)

/**
 * range
 * 
 * identity
 * 
 * func
 * 
 * reduction
 */
int main()
{
	size_t n = 11; // sum [sin(0), sin(1), ..., sin(10)] 
	double res = tbb::parallel_reduce(
		
		tbb::blocked_range<size_t>(0, n), // 0 ~ n

		float(100), // 100 += 

		[&](tbb::blocked_range<size_t> r, double local_res) { // local sum
			for( size_t i = r.begin(); i < r.end(); i++)
			{
				local_res += std::sin(i);
			}
			return local_res;
		},
		
		std::plus<double>()

	);

	std::cout << res << std::endl;  // 100 + sum [sin(0), sin(1), ..., sin(10)] 

	return 0;
}