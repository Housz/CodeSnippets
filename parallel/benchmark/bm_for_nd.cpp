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

#include <tbb/parallel_for_each.h>
#include <benchmark/benchmark.h>


