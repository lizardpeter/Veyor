#include "Worker.h"

using namespace Work;
Worker::Worker(std::string name, std::string purpose)
{
	m_name = name;
	m_purpose = purpose;
}

std::string Worker::getName()
{
	return m_name;
}

std::string Worker::getPurpose()
{
	return m_purpose;
}

void Worker::setName(std::string name)
{
	m_name = name;
}

void Worker::setPurpose(std::string purpose)
{
	m_purpose = purpose;
}

