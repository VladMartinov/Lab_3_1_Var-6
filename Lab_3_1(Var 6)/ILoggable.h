#pragma once
#include <iostream>

class ILoggable
{
public:
	//virtual ~ILoggable();
	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& filename) = 0;
};