/*
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
serial_ijk             21121 ms        13562 ms            1
serial_kji             12488 ms         7578 ms            1
tbb_blocked3d_kji       1566 ms         1516 ms            1

*/

#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <cmath>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range3d.h>
#include <benchmark/benchmark.h>

size_t n = 1 << 10;

std::vector<float> v(n *n *n);



static void serial_kji(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t k = 0; k < n; k++)
		{
			for (size_t j = 0; j < n; j++)
			{
				for (size_t i = 0; i < n; i++)
				{
					v[i + j * n + k * n * n] += sin(i)*cos(i);
				}
			}
		}
	}
}

static void serial_ijk(benchmark::State &state)
{
	for (auto _ : state)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				for (size_t k = 0; k < n; k++)
				{
					v[i + j * n + k * n * n] += sin(i)*cos(i);
				}
			}
		}
	}
}


static void tbb_blocked3d_kji(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(tbb::blocked_range3d<size_t>(0, n, 0, n, 0, n),
			[&](tbb::blocked_range3d<size_t> r){
				for (size_t k = r.pages().begin(); k < r.pages().end(); k++)
				{
					for (size_t j = r.cols().begin(); j < r.cols().end(); j++)
					{
						for (size_t i = r.rows().begin(); i < r.rows().end(); i++)
						{
							v[i + j * n + k * n * n] += sin(i)*cos(i);
						}
					}
				}
				
			}
		);
	}
}


BENCHMARK(serial_ijk);
BENCHMARK(serial_kji);
BENCHMARK(tbb_blocked3d_kji);

BENCHMARK_MAIN();
