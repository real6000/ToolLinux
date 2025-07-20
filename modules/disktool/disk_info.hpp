// disk_info.hpp
#pragma once
#include <string>

struct DiskInfo {
    long long totalSpace;
    long long freeSpace;
    long long availableSpace;
};

class DiskTool {
public:
    static DiskInfo getDiskInfo(const std::string& path);
};
