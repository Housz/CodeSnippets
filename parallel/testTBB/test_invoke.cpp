#include <iostream>
#include <string>
#include <tbb/tbb.h>

int main()
{
	auto t1 = []()
	{
		for (size_t i = 0; i < 100; i++)
		{
			std::cout << "processi something..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	};
	auto t2 = []()
	{
		std::string s;
		std::cin >> s;
		std::cout << "hello: " << s << std::endl;
	};
	tbb::parallel_invoke(
		t1,
		t2
	);

	return 0;
}