#include "logger.h"
#include <iostream>
#include <mutex>

using namespace std;

int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;
Logger::Logger()
{
	ctr++;
	cout << "New instance created. No. of instances = " << ctr << endl;
}

void Logger::Log(string msg)
{
	cout << msg << endl;
}

Logger* Logger::getLogger()
{
	if (loggerInstance == nullptr)
	{
		mtx.lock(); // locks are expensive
		if (loggerInstance == nullptr)
		{
			loggerInstance = new Logger();
		}
		mtx.unlock();
	}
	return loggerInstance;
}
