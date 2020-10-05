#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

namespace Work
{
	class Worker
	{
		std::thread thr;
		bool keepWorking;
		std::mutex mtx;
		std::condition_variable cv;

	public:
		std::string m_name;
		std::string m_purpose;

		Worker(std::string name, std::string purpose);
		std::string getName();
		std::string getPurpose();
		void setName(std::string name);
		void setPurpose(std::string purpose);

	};
}
#endif