#include "../modules/disktool/disk_info.hpp"
#include <iostream>
#include <cassert>

int main() {
    DiskInfo info = DiskTool::getDiskInfo("/"); // or "C:\\" on Windows

    std::cout << "Total: " << info.totalSpace << "\n";
    std::cout << "Free: " << info.freeSpace << "\n";
    std::cout << "Available: " << info.availableSpace << "\n";

    assert(info.totalSpace > 0 && "Total disk space should be greater than 0");
    assert(info.freeSpace >= 0 && "Free space should be non-negative");
    assert(info.availableSpace >= 0 && "Available space should be non-negative");

    return 0;
}
