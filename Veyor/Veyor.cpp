
#include <thread>
#include <iostream>

int main()
{
	for (;;)
	{
		std::cout << "This is a test :)\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	}
}
