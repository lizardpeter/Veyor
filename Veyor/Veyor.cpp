

//#include "Worker.h"
#include "startThread.h"

void hi()
{
	std::cout << "Function hi is running within the thread";
}

int main()
{
	startThread thread;
	thread.run(thread.find, "Thread 1", hi);
	startThread thread2;
	thread2.run(thread.find, "Thread 2", hi);
	std::cout << "Initialization is complete" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(10));
	{
		std::lock_guard<std::mutex> guard(thread.m);
		std::lock_guard<std::mutex> guard2(thread2.m);
		thread.exit();
		thread2.exit();
	}
	thread.cv.notify_all();
	thread2.cv.notify_all();

	std::cout << "Threads stop immediately" << std::endl;
	thread.my_thread.join();
	thread2.my_thread.join();
}
