#pragma once
#include <string>
#include <mutex>

class Settings {
public:
    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }

    void setLogLevel(const std::string& level) {
        std::lock_guard<std::mutex> lock(mutex_);
        logLevel = level;
    }

    std::string getLogLevel() {
        std::lock_guard<std::mutex> lock(mutex_);
        return logLevel;
    }

    // Add more settings getters/setters as needed

private:
    Settings() = default;
    std::mutex mutex_;
    std::string logLevel = "INFO";

    // Prevent copy and assignment
    Settings(const Settings&) = delete;
    Settings& operator=(const Settings&) = delete;
};
