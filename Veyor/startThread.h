#pragma once
#ifndef STARTTHREAD_H
#define STARTTHREAD_H

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <functional>

struct startThread
{
public:

	int k;
	std::condition_variable cv;
	std::mutex m;
	std::thread my_thread;
	std::atomic<bool> exit_thread = false;
	std::string m_name;

	startThread();

	void exit();

	//template<typename Function>
	void run(std::function<void(std::atomic<bool>&, std::mutex&, std::condition_variable&,std::string, std::function<void()>)> func, std::string name, std::function<void()> func2);

	static void find(std::atomic<bool>& test, std::mutex &m, std::condition_variable &cv, std::string name, std::function<void()> func2);
};



#endif