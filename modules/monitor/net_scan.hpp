#pragma once
#include <vector>
#include <string>

struct HostInfo {
    std::string ip;
    std::string hostname;
};

class NetScan {
public:
    // Scan the subnet for active hosts
    std::vector<HostInfo> scanSubnet(const std::string& subnet);
};
