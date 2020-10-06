#include "startThread.h"

startThread::startThread()
{

}

	void startThread::exit()
	{
		startThread::exit_thread = true;
	}

	//template<typename Function>
	void startThread::run(std::function<void(std::atomic<bool>&, std::mutex&, std::condition_variable&, std::string, std::function<void()>)> func, std::string name, std::function<void()> func2)
	{
		m_name = name;
		my_thread = std::thread([this, func, func2] {
			do {
				std::cout << m_name + " is doing something... \n" << std::endl;
				{
					//int i = 0;
					//while (!exit_thread && i < 100000)
					//{
						//i++;
						//std::cout << i;
					//}
					func(exit_thread, m, cv, m_name, func2); //ISSUE HERE???

					//std::unique_lock<std::mutex> lock(m);
					//cv.wait_for(lock, std::chrono::seconds(10));
					std::cout << exit_thread;
					std::cout << "OH NO. BIG MISTAKE...";
				}
			} while (!exit_thread);
			});
	}


void startThread::find(std::atomic<bool>& test, std::mutex &m, std::condition_variable &cv, std::string name, std::function<void()> func2)
{
	int i = 0;
	while (!test && i < 100000)
	{
		//std::cout << i;
		func2();
		std::cout << name + "\n";
		i++;
		std::unique_lock<std::mutex> lock(m);
		cv.wait_for(lock, std::chrono::seconds(15));
		//std::cout << exit_thread;
		
	}
}
