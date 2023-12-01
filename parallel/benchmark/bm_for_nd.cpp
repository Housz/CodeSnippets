/**
 * @file bm_for_nd.cpp
 * @author Housz
 * @brief benchmark:
 * 1 vector (m*n)
 * 2 vector<vector<T>> m,n
 * 
 * 1 tbb::parallel_for(tbb::parallel_for())
 * 2 tbb::parallel_for(range2d)
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <cmath>

#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>
#include <benchmark/benchmark.h>

size_t n = 1 << 10;
std::vector<std::vector<double>> v(n, std::vector<double>(n, 0));
std::vector<double> v2(n*n);

static void para_for_ij(benchmark::State &state)
{
    for (auto _ : state)
	{
        tbb::parallel_for(size_t(0), n, [&](size_t i){
            tbb::parallel_for(size_t(0), n, [&](size_t j){
                v[i][j] = std::sin(i) * std::cos(j);
            });
        });
    }
}

static void para_for_ij_v2(benchmark::State &state)
{
    for (auto _ : state)
	{
        tbb::parallel_for(size_t(0), n, [&](size_t i){
            tbb::parallel_for(size_t(0), n, [&](size_t j){
                v2[i*n+j] = std::sin(i) * std::cos(j);
            });
        });
    }
}

static void para_for_i_v2(benchmark::State &state)
{
    for (auto _ : state)
	{
        tbb::parallel_for(size_t(0), n*n, [&](size_t i){
            v2[i] = std::sin(i) * std::cos(i);
        });
    }
}

static void para_for_ji(benchmark::State &state)
{
    for (auto _ : state)
	{
        tbb::parallel_for(size_t(0), n, [&](size_t j){
            tbb::parallel_for(size_t(0), n, [&](size_t i){
                v[i][j] = std::sin(i) * std::cos(j);
            });
        });
    }
}

static void range2d_1(benchmark::State &state)
{
	for (auto _ : state)
    {
        tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
        [&](tbb::blocked_range2d<size_t> r){
            for(size_t i = r.cols().begin(); i < r.cols().end(); i++)
            {
                for(size_t j = r.rows().begin(); j < r.rows().end(); j++)
                {
                    v[i][j] = std::sin(i) * std::cos(j);
                }
            }
        }
        );
    }
}

static void range2d_1_v2(benchmark::State &state)
{
	for (auto _ : state)
    {
        tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
        [&](tbb::blocked_range2d<size_t> r){
            for(size_t i = r.cols().begin(); i < r.cols().end(); i++)
            {
                for(size_t j = r.rows().begin(); j < r.rows().end(); j++)
                {
                    v2[i*n+j] = std::sin(i) * std::cos(j);
                }
            }
        }
        );
    }
}

static void range2d_2(benchmark::State &state)
{
	for (auto _ : state)
    {
        tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
        [&](tbb::blocked_range2d<size_t> r){
            for(size_t i = r.cols().begin(); i < r.cols().end(); i++)
            {
                for(size_t j = r.rows().begin(); j < r.rows().end(); j++)
                {
                    v[j][i] = std::sin(i) * std::cos(j);
                }
            }
        }
        );
    }
}


static void range2d_3(benchmark::State &state)
{
	for (auto _ : state)
    {
        tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
        [&](tbb::blocked_range2d<size_t> r){
            for(size_t i = r.rows().begin(); i < r.rows().end(); i++)
            {
                for(size_t j = r.cols().begin(); j < r.cols().end(); j++)
                {
                    v[i][j] = std::sin(i) * std::cos(j);
                }
            }
        }
        );
    }
}

static void range2d_4(benchmark::State &state)
{
	for (auto _ : state)
    {
        tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
        [&](tbb::blocked_range2d<size_t> r){
            for(size_t i = r.rows().begin(); i < r.rows().end(); i++)
            {
                for(size_t j = r.cols().begin(); j < r.cols().end(); j++)
                {
                    v[j][i] = std::sin(i) * std::cos(j);
                }
            }
        }
        );
    }
}



BENCHMARK(para_for_ij);
BENCHMARK(para_for_ij_v2);
BENCHMARK(para_for_i_v2);
BENCHMARK(para_for_ji);
BENCHMARK(range2d_1);
BENCHMARK(range2d_1_v2);
BENCHMARK(range2d_2);
BENCHMARK(range2d_3);
BENCHMARK(range2d_4);

BENCHMARK_MAIN();
