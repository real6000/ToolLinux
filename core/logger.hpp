#pragma once
#include <string>
#include <fstream>
#include <mutex>

/**
 * Thread-safe Logger for ToolLinux modules.
 * Supports console and file logging.
 */
class Logger {
public:
    enum class Level { DEBUG, INFO, WARN, ERROR };

    explicit Logger(const std::string& logFile = "");
    ~Logger();

    void log(Level level, const std::string& message);

    // Convenience methods
    void debug(const std::string& message);
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);

private:
    std::ofstream fileStream_;
    std::mutex mutex_;
    bool toFile_;
    std::string levelToString(Level level);
};
