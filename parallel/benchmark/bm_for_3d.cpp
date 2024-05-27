/*
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
serial_ijk        3.3715e+10 ns   1.9219e+10 ns            1
serial_kji        1.3088e+10 ns   7031250000 ns            1
tbb_blocked3d_kji 2030161400 ns   1515625000 ns            1
tbb_blocked3d_ijk 4134336500 ns   1406250000 ns            1

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

std::vector<double> v(n * n * n);


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

static void tbb_blocked3d_ijk(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(tbb::blocked_range3d<size_t>(0, n, 0, n, 0, n),
			[&](tbb::blocked_range3d<size_t> r){
				for (size_t i = r.pages().begin(); i < r.pages().end(); i++)
				{
					for (size_t j = r.cols().begin(); j < r.cols().end(); j++)
					{
						for (size_t k = r.rows().begin(); k < r.rows().end(); k++)
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
BENCHMARK(tbb_blocked3d_ijk);

BENCHMARK_MAIN();
