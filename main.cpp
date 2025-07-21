#include <iostream>
#include "config/config_manager.hpp"

int main() {
    std::cout << "Starting ToolLinux..." << std::endl;

    ConfigManager cfg;
    // no longer needed since we can just put that in 
    // the if-statement instead of a separate variable
    // bool loaded = cfg.load("config/default.cfg");
    
    if (cfg.load("config/default.cfg")) {
        std::cout << "Config loaded successfully." << std::endl;
    } else {
        std::cout << "Failed to load config file." << std::endl;
    }

    // further init

    return 0;
}
