/*
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
serial_ijk             33704 ms        23422 ms            1
serial_kji             14923 ms        10562 ms            1
tbb_blocked3d_ijk       4064 ms         1844 ms            1

*/

#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <cmath>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range3d.h>
#include <benchmark/benchmark.h>

// size_t n = 1 << 10;
size_t n = 1 << 10;
size_t X = n;
size_t Y = n + 1;
size_t Z = n + 2;

// std::vector<double> v(n *n *n);
std::vector<double> _v(X * Y * Z);

double& v(size_t i, size_t j, size_t k)
{
	if (!(i<X && j<Y && k<Z))
	{
		std::cout << i << " " << j << " " << k << "\n";
	}
	
	return _v[ i + j * X + k * X*Y ];
}

static void serial_ijk(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t i = 0; i < X; i++)
		{
			for (size_t j = 0; j < Y; j++)
			{
				for (size_t k = 0; k < Z; k++)
				{
					// v[i + j * n + k * n * n] += sin(i) * cos(i);
					v(i, j, k) = sin(i) * cos(i);
				}
			}
		}
	}
}

static void serial_kji(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t k = 0; k < Z; k++)
		{
			for (size_t j = 0; j < Y; j++)
			{
				for (size_t i = 0; i < X; i++)
				{
					// v[i + j * n + k * n * n] += sin(i) * cos(i);
					v(i, j, k) = sin(i) * cos(i);
				}
			}
		}
	}
}

static void tbb_blocked3d_ijk(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(tbb::blocked_range3d<size_t>(0, X, 0, Y, 0, Z),
						  [&](tbb::blocked_range3d<size_t> r)
						  {
							  for (size_t i = r.pages().begin(); i < r.pages().end(); i++)
							  {
								  for (size_t j = r.rows().begin(); j < r.rows().end(); j++)
								  {
									  for (size_t k = r.cols().begin(); k < r.cols().end(); k++)
									  {
										//   v[i + j * n + k * n * n] += sin(i) * cos(i);
										  v(i, j, k) = sin(i) * cos(i);
									  }
								  }
							  }
						  });
	}
}

// err
static void tbb_blocked3d_kji(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(tbb::blocked_range3d<size_t>(0, Z, 0, Y, 0, X),
						  [&](tbb::blocked_range3d<size_t> r)
						  {
							  for (size_t k = r.cols().begin(); k < r.cols().end(); k++)
							  {
								  for (size_t j = r.rows().begin(); j < r.rows().end(); j++)
								  {
									  for (size_t i = r.pages().begin(); i < r.pages().end(); i++)
									  {
										//   v[i + j * n + k * n * n] += sin(i) * cos(i);
										  v(i, j, k) = sin(i) * cos(i);
									  }
								  }
							  }
						  });
	}
}


BENCHMARK(serial_ijk);
BENCHMARK(serial_kji);
BENCHMARK(tbb_blocked3d_ijk);
// BENCHMARK(tbb_blocked3d_kji);

BENCHMARK_MAIN();
