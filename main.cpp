#include <iostream>
#include "config/config_manager.hpp"

int main() {
    std::cout << "Starting ToolLinux..." << std::endl;

    ConfigManager cfg;
    bool loaded = cfg.load("config/default.cfg");

    if (loaded) {
        std::cout << "Config loaded successfully." << std::endl;
    } else {
        std::cout << "Failed to load config file." << std::endl;
    }

    // further init

    return 0;
}
