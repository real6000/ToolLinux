#pragma once
#include <string>
#include <vector>

/**
 * Simple cross-platform file reading and writing utility.
 */

class FileIO {
public:
    // Reads entire file into a string
    static std::string readFile(const std::string& filepath);

    // Writes string data to a file (overwrites)
    static bool writeFile(const std::string& filepath, const std::string& data);

    // Reads file line by line into a vector of strings
    static std::vector<std::string> readLines(const std::string& filepath);
};