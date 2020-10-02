
#include <thread>
#include <iostream>
#include "Worker.h"

int main()
{
	for (;;)
	{
		std::cout << "This is a test :)\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		Work::Worker Peter("Peter","spawn threads");
		std::cout << "My name is " + Peter.getName() + "\n";
		std::cout << "My purpose is to " + Peter.getPurpose() + "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		Peter.setName("Thanos");
		Peter.setPurpose("destroy worlds");
		std::cout << "My name is " + Peter.getName() + "\n";
		std::cout << "My purpose is to " + Peter.getPurpose() + "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));


	}
}
