#pragma once
#include <vector>
#include <string>

struct ProcessInfo {
    int pid;
    std::string name;
};

class ProcessMonitor {
public:
    // List all running processes
    std::vector<ProcessInfo> listProcesses();
};
