#include "system_info.hpp"

#ifdef __linux__
#include <sys/utsname.h>

std::string SystemInfo::getOSName() {
    struct utsname buffer{};
    if (uname(&buffer) != 0) return "Unknown";
    return buffer.sysname;
}

std::string SystemInfo::getKernelVersion() {
    struct utsname buffer{};
    if (uname(&buffer) != 0) return "Unknown";
    return buffer.release;
}

std::string SystemInfo::getArchitecture() {
    struct utsname buffer{};
    if (uname(&buffer) != 0) return "Unknown";
    return buffer.machine;
}
#else
std::string SystemInfo::getOSName() {
    return "Unsupported OS";
}

std::string SystemInfo::getKernelVersion() {
    return "Unsupported OS";
}

std::string SystemInfo::getArchitecture() {
    return "Unsupported OS";
}
#endif
