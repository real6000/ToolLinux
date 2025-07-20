#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

/**
 *String utility functions for ToolLinux modules.
 */
namespace StringUtil {

    //Trim whitespace from both ends
    std::string trim(const std::string& str);

    //Split string by delimiter
    std::vector<std::string> split(const std::string& str, char delimiter);

    //Convert string to lowercase
    std::string toLower(const std::string& str);

    //Convert string to uppercase
    std::string toUpper(const std::string& str);
}