#pragma once
#include <string>
class Log
{
private:
	Log();
	static Log* s_Instance;
	std::ofstream* file;
	std::string filename;

public:
	void LogText(std::string text);
	void LogText(const char* text);
	static Log* Get();
};

