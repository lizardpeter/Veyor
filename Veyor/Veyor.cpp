

//#include "Worker.h"
#include "startThread.h"

void hi()
{
	std::cout << "hi :)";
}

int main()
{
	std::cout << "My program starts" << std::endl;
	startThread thread;
	thread.run(thread.find, "Thread 1", hi);
	startThread thread2;
	thread2.run(thread.find, "Thread 2", hi);


	std::this_thread::sleep_for(std::chrono::seconds(5));
	{
		std::lock_guard<std::mutex> guard(thread.m);
		std::lock_guard<std::mutex> guard2(thread2.m);
		thread.exit();
		thread2.exit();
	}
	thread.cv.notify_all();
	thread2.cv.notify_all();

	std::cout << "Thread stops immediately" << std::endl;
	thread.my_thread.join();
	thread2.my_thread.join();
}
