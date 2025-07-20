#include "disk_info.hpp"

#ifdef __linux__
#include <sys/statvfs.h>
#endif

DiskInfo DiskTool::getDiskInfo(const std::string& path) {
    DiskInfo info;

#ifdef __linux__
    struct statvfs stat{};
    if (statvfs(path.c_str(), &stat) == 0) {
        info.totalSpace = stat.f_blocks * stat.f_frsize;
        info.freeSpace = stat.f_bfree * stat.f_frsize;
        info.availableSpace = stat.f_bavail * stat.f_frsize;
    } else {
        info.totalSpace = -1;
        info.freeSpace = -1;
        info.availableSpace = -1;
    }
#else
    info.totalSpace = -1;
    info.freeSpace = -1;
    info.availableSpace = -1;
#endif

    return info;
}
