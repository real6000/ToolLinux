#pragma once
#include <string>

/**
 * Provides basic information about the Linux system.
 */

class SystemInfo {
public:
    static std::string getOSName();
    static std::string getKernelVersion();
    static std::string getArchitecture();
};