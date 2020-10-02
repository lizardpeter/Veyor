#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <string>
namespace Work
{
	class Worker
	{
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