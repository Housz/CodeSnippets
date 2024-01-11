/**
 * condition_variable
 * std::unique_lock
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>

std::queue<int> q;

std::mutex mtx;
std::condition_variable cv;

void producer()
{
	mtx.lock();
	q.push(1);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));

	mtx.lock();
	q.push(2);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));

	mtx.lock();
	q.push(3);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));

	mtx.lock();
	q.push(4);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));

	mtx.lock();
	q.push(5);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));

	mtx.lock();
	q.push(0);
	cv.notify_one();
	mtx.unlock();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
}

void consumer()
{
	for (;;)
	{
		// mtx.lock();
//////////////////////////////////////////////////////////////////////////
		std::unique_lock<std::mutex> lk(mtx);
//////////////////////////////////////////////////////////////////////////

		// while (q.empty())
		// {
		// 	mtx.unlock();
		// 	std::this_thread::sleep_for(std::chrono::microseconds(100));
		// 	mtx.lock();
		// }

//////////////////////////////////////////////////////////////////////////
		cv.wait(lk, []{return !q.empty();});
//////////////////////////////////////////////////////////////////////////
		// locked
		int gift = q.front();
		std::cout << gift;
		q.pop();
		lk.unlock();
//////////////////////////////////////////////////////////////////////////

		if (gift == 0)
		{
			return;
		}
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