#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>



std::queue<float> q;

std::mutex mtx;

void producer()
{
	mtx.lock();
	// q.push(1);
	std::cout << "producer" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	mtx.unlock();
}

void consumer()
{
	mtx.lock();
	std::cout << "consumer" << std::endl; std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "consumer" << std::endl; std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "consumer" << std::endl; std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "consumer" << std::endl; std::this_thread::sleep_for(std::chrono::seconds(1));
	mtx.unlock();
}

int main()
{
	std::thread producer_thread(producer);
	std::thread consumer_thread(consumer);
	producer_thread.join();
	consumer_thread.join();
	return 0;
}