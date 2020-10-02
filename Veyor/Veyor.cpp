
#include <thread>
#include <iostream>

int main()
{
	for (;;)
	{
		std::cout << "Hello World!\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	}
}