#pragma once
#include <string>
#include <unordered_map>

/**
 * Loads and manages configuration key-value pairs.
 */
class ConfigManager {
public:
    // Default constructor (optional, sets empty path)
    ConfigManager() = default;

    // Constructor with file path
    explicit ConfigManager(const std::string& path) : filePath(path) {}

    // Load config from filePath; returns success
    bool load(const std::string& path);

    // Get value by key, return defaultValue if key not found
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

    // Check if key exists
    bool hasKey(const std::string& key) const;

private:
    std::string filePath;
    std::unordered_map<std::string, std::string> configData;
};
