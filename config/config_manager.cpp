#include "config_manager.hpp"
#include <../utils/string_util.hpp>
#include <fstream>
#include <sstream>

ConfigManager::ConfigManager(const std::string& path) : filePath(path) {}

bool ConfigManager::load() {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        line = StringUtil::trim(line);
        if (line.empty() || line[0] == '#') continue;

        auto parts = StringUtil::split(line, '=');
        if (parts.size() == 2) {
            std::string key = StringUtil::trim(parts[0]);
            std::string value = StringUtil::trim(parts[1]);
            configData[key] = value;
        }
    }

    return true;
}

std::string ConfigManager::get(const std::string& key, const std::string& defaultValue) const {
    auto it = configData.find(key);
    return it != configData.end() ? it->second : defaultValue;
}

bool ConfigManager::hasKey(const std::string& key) const {
    return configData.find(key) != configData.end();
}