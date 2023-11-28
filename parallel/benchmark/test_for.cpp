/*
	parallel version:3305ms
	normal version:23829ms
	tbb version:7896ms
 */

#include <array>
#include <algorithm>
#include <execution>
#include <iostream>
#include <chrono>

#include <tbb/parallel_for_each.h>

using namespace std;

array<char, 1'000'000'000 > ar;

int main()
{
	auto myrand = [](char& a) {a = rand() % 100 + 100; };

	chrono::high_resolution_clock clk;

	auto beg_time = clk.now();
	for_each(execution::par, ar.begin(), ar.end(), myrand);
	cout << "parallel version:" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;

	beg_time = clk.now();
	for (auto&& e : ar) myrand(e);
	cout << "normal version:" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;

	// tbb parallel for
	beg_time = clk.now();
	tbb::parallel_for_each(ar.begin(), ar.end(), myrand);
	cout << "tbb::parallel_for_each" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;

	beg_time = clk.now();
	tbb::parallel_for(size_t(0), size_t(ar.size()), [&](size_t i){
		ar[i] = rand() % 100 + 100;
	});
	cout << "tbb::parallel_for" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;

	// auto myrand1 = [&](char& a) {a = rand() % 100 + 100; };
	// beg_time = clk.now();
	// tbb::parallel_for(size_t(0), size_t(ar.size()), myrand1);
	// cout << "tbb::parallel_for" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;

	// beg_time = clk.now();
	// tbb::parallel_for(size_t(0), size_t(ar.size()), [&](size_t i){
	// 	ar[i] = rand() % 100 + 100;
	// });
	// cout << "c++ thread" << chrono::duration_cast<chrono::milliseconds>(clk.now() - beg_time).count() << "ms" << endl;



	return 0;
}