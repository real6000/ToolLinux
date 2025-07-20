#pragma once
#include <string>
#include <unordered_map>

/**
 * Loads and manages configuration key-value pairs.
 */
class ConfigManager {
public:
    explicit ConfigManager(const std::string& path);

    bool load();
    std::string get(const std::string& key, const std::string& defaultValue = "") const;
    bool hasKey(const std::string& key) const;

private:
    std::string filePath;
    std::unordered_map<std::string, std::string> configData;
};