/**
 * single producer, multi consumer
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <format>
#include <vector>

std::queue<int> q;

std::mutex mtx;
std::condition_variable cv;

//////////////////////////////////////////////////////////////////////////
void push_task(int task)
{
	std::unique_lock<std::mutex> lk(mtx);
	q.push(task);
	lk.unlock();

	std::this_thread::sleep_for(std::chrono::microseconds(100));

	cv.notify_all();
}
//////////////////////////////////////////////////////////////////////////

void producer()
{
	for (size_t i = 1; i <= 100; i++)
	{
		push_task((int)i);
	}
	push_task(0);
}

void consumer(int thread_id)
{
	for (;;)
	{
		// mtx.lock();
		std::unique_lock<std::mutex> lk(mtx);

		// while (q.empty())
		// {
		// 	mtx.unlock();
		// 	std::this_thread::sleep_for(std::chrono::microseconds(100));
		// 	mtx.lock();
		// }
		cv.wait(lk, []
				{ return !q.empty(); });
		// locked
		int gift = q.front();
		std::cout << std::format("{} got gift {} \n", thread_id, gift);
		if (gift != 0)
		{
			q.pop();
		}
		lk.unlock();
		if (gift == 0)
		{
			break;
		}
	}
}

int main()
{
	std::thread producer_thread(producer);
	std::thread consumer_thread1(consumer, 1);
	std::thread consumer_thread2(consumer, 2);
	producer_thread.join();
	consumer_thread1.join();
	consumer_thread2.join();


	// std::thread producer_thread(producer);
	// std::vector<std::thread> consumer_thread_container;
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	std::thread consumer_thread(consumer, (int)i);
	// 	consumer_thread_container.push_back(std::move(consumer_thread));
	// }
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	consumer_thread_container[i].join();
	// }
	// producer_thread.join();

	return 0;
}