#include <iostream>
#include <vector>
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
int main0()
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

// parallel average
int main()
{
	size_t n = 1 << 26;

	std::vector<float> v(n);

	for (size_t i = 0; i < n; i++)
	{
		v[i] = 10.f + (float)std::sin(i);
	}

	float avg_serial = 0;
	for (size_t i = 0; i < n; i++)
	{
		avg_serial += v[i];
	}
	avg_serial /= n;
	std::cout << "average serial: " << avg_serial << "\n"; // = 4


	float avg_parallel = 
	tbb::parallel_reduce(tbb::blocked_range<size_t>(0, n), (float)0, 
	[&](tbb::blocked_range<size_t> r, float avg_local){
		for (size_t i = r.begin(); i != r.end(); i++)
		{
			avg_local += v[i];
		}
		return avg_local;
	},
	// [] (float x, float y) {return x + y;}
	std::plus<float>()
	);

	avg_parallel /= n;
	
	std::cout << "average parallel: " << avg_parallel << "\n"; // = 10


	return 0;
}