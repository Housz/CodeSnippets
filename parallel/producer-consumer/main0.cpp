/**
 * std::thread
 * std::mutex lock/unlock
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>

std::queue<int> q;

std::mutex mtx;

void producer()
{
	mtx.lock();
	q.push(1);
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	mtx.lock();
	q.push(2);
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	mtx.lock();
	q.push(3);
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	mtx.lock();
	q.push(4);
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	mtx.lock();
	q.push(5);
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	mtx.lock();
	q.push(0); // stop product
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
}

void consumer()
{
	for (;;)
	{
		mtx.lock();
		while (q.empty())
		{
			mtx.unlock();
			std::this_thread::sleep_for(std::chrono::microseconds(100));
			mtx.lock();
		}
		int gift = q.front();
		std::cout << gift;
		mtx.unlock();
		if (gift == 0)
		{
			return;
		}
		q.pop();
	}
}

int main()
{
	std::thread producer_thread(producer);
	std::thread consumer_thread(consumer);
	producer_thread.join();
	consumer_thread.join();
	return 0;
}