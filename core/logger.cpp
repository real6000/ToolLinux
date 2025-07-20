#include "logger.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

Logger::Logger(const std::string& logFile) : toFile_(!logFile.empty()) {
    if (toFile_) {
        fileStream_.open(logFile, std::ios::app);
        if (!fileStream_.is_open()) {
            std::cerr << "Logger: Failed to open log file: " << logFile << "\n";
            toFile_ = false;
        }
    }
}

Logger::~Logger() {
    if (fileStream_.is_open()) fileStream_.close();
}

void Logger::log(Level level, const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    // Get current time string
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::string logMsg = "[" + std::string(std::ctime(&now_c));
    logMsg.pop_back(); // remove newline
    logMsg += "] [" + levelToString(level) + "] " + message + "\n";

    if (toFile_ && fileStream_.is_open()) {
        fileStream_ << logMsg;
        fileStream_.flush();
    } else {
        std::cout << logMsg;
    }
}

std::string Logger::levelToString(Level level) {
    switch(level) {
        case Level::DEBUG: return "DEBUG";
        case Level::INFO:  return "INFO";
        case Level::WARN:  return "WARN";
        case Level::ERROR: return "ERROR";
    }
    return "UNKNOWN";
}

void Logger::debug(const std::string& message) { log(Level::DEBUG, message); }
void Logger::info(const std::string& message) { log(Level::INFO, message); }
void Logger::warn(const std::string& message) { log(Level::WARN, message); }
void Logger::error(const std::string& message) { log(Level::ERROR, message); }
