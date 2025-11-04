#include "Log.h"
#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <sstream>

Log* Log::s_Instance = nullptr;

void Log::LogText(std::string text)
{
	std::cout << text << std::endl;
	*file << text << "\n";
}

void Log::LogText(const char* text)
{
    std::cout << text << std::endl;
    *file << text << "\n";
}

Log* Log::Get()
{
	return (s_Instance == nullptr ? s_Instance = new Log() : s_Instance);
}

Log::Log()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::tm local_time;

    // Thread-safe version of localtime
#ifdef _MSC_VER
    localtime_s(&local_time, &time_now);
#else
    local_time = *std::localtime(&time_now);
#endif

    std::ostringstream oss;
    oss << std::put_time(&local_time, "%d%m%y-%H%M%S");

    filename = oss.str(); // store in member variable
    file = new std::ofstream(filename.c_str(), std::ios::app);

    if (!file->is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}
