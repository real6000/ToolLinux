#include "file_io.hpp"
#include <fstream>
#include <sstream>

std::string FileIO::readFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) return "";

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

bool FileIO::writeFile(const std::string& filepath, const std::string& data) {
    std::ofstream file(filepath, std::ios::trunc);
    if (!file.is_open()) return false;

    file << data;
    return true;
}