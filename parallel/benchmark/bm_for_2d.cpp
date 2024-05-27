
#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <cmath>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>
#include <benchmark/benchmark.h>

// size_t n = 1 << 10;
size_t n = 1 << 10;
size_t X = n;
size_t Y = n + 1;

// std::vector<double> v(n *n *n);
std::vector<double> _v(X *Y);

double &v(size_t i, size_t j)
{
	if (!(i < X && j < Y))
	{
		std::cout << i << " " << j << "\n";
	}

	return _v[i + j * X];
}

static void serial_ij(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t i = 0; i < X; i++)
		{
			for (size_t j = 0; j < Y; j++)
			{
				v(i, j) = sin(i) * cos(i);
			}
		}
	}
}

static void serial_ji(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t j = 0; j < Y; j++)
		{
			for (size_t i = 0; i < X; i++)
			{
				v(i, j) = sin(i) * cos(i);
			}
		}
	}
}

static void tbb_blocked3d_ij(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(tbb::blocked_range2d<size_t>(0, X, 0, Y),
						  [&](tbb::blocked_range2d<size_t> r)
						  {
							  for (size_t i = r.rows().begin(); i < r.rows().end(); i++)
							  {
								  for (size_t j = r.cols().begin(); j < r.cols().end(); j++)
								  {
									  //   v[i + j * n + k * n * n] += sin(i) * cos(i);
									  v(i, j) = sin(i) * cos(i);
								  }
							  }
						  });
	}
}

// err
// static void tbb_blocked3d_ji(benchmark::State &state)
// {
// 	for (auto _ : state)
// 	{
// 		tbb::parallel_for(tbb::blocked_range3d<size_t>(0, Z, 0, Y, 0, X),
// 						  [&](tbb::blocked_range3d<size_t> r)
// 						  {
// 							  for (size_t k = r.cols().begin(); k < r.cols().end(); k++)
// 							  {
// 								  for (size_t j = r.rows().begin(); j < r.rows().end(); j++)
// 								  {
// 									  for (size_t i = r.pages().begin(); i < r.pages().end(); i++)
// 									  {
// 										  //   v[i + j * n + k * n * n] += sin(i) * cos(i);
// 										  v(i, j, k) = sin(i) * cos(i);
// 									  }
// 								  }
// 							  }
// 						  });
// 	}
// }

BENCHMARK(serial_ij);
BENCHMARK(serial_ji);
BENCHMARK(tbb_blocked3d_ij);
// BENCHMARK(tbb_blocked3d_kji);

BENCHMARK_MAIN();
