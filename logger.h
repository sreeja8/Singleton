#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <iostream>
#include <mutex>
#include <string>
using namespace std;

class Logger
{
	static std::mutex mtx;
	static int ctr;
	Logger();
	static Logger* loggerInstance;
public:
	static Logger* getLogger();
	void Log(string msg);
};

#endif // LOGGER_H_INCLUDED
