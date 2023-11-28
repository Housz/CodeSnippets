#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>

#include <tbb/parallel_for_each.h>
#include <benchmark/benchmark.h>

size_t n = 1 << 20;

std::vector<float> v(n);

auto myrand = [](float &a)
{ a = rand() % 100 + 100; };

static void foreach_normal(benchmark::State &state)
{
	for (auto _ : state)
	{
		for_each(v.begin(), v.end(), myrand);
	}
}

static void foreach_parallel(benchmark::State &state)
{
	for (auto _ : state)
	{
		for_each(std::execution::par, v.begin(), v.end(), myrand);
	}
}

static void tbb_parallel_for_each(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for_each(v.begin(), v.end(), myrand);
	}
}

static void tbb_parallel_for(benchmark::State &state)
{
	for (auto _ : state)
	{
		tbb::parallel_for(size_t(0), size_t(v.size()), [&](size_t i)
						  { v[i] = rand() % 100 + 100; });
	}
}

BENCHMARK(foreach_normal);
BENCHMARK(foreach_parallel);
BENCHMARK(tbb_parallel_for_each);
BENCHMARK(tbb_parallel_for);

BENCHMARK_MAIN();
