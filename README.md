# ToolLinux

**ToolLinux** is a modular, lightweight toolkit designed for Linux-based systems. It provides a set of essential system tools for monitoring, diagnostics, and utility tasks, with a clean and extensible architecture built in C and C++.

## Features

- **System Information**: Detects OS name, kernel version, and architecture.
- **Disk Utility**: Retrieves disk usage and mount information.
- **Network Monitoring**: Scans local network interfaces and IPs.
- **Process Tools**: Monitors running processes and their resource usage.
- **Configuration System**: Loads settings from configuration files for flexibility and modularity.
- **Low-level Access**: Interacts with the system via C-level calls and libraries.

## Build Instructions

### Requirements

- Linux operating system
- CMake 3.31+
- GCC or Clang with C++20 support

### Build

```bash
git clone https://github.com/yourusername/ToolLinux.git
cd ToolLinux
mkdir build && cd build
cmake ..
make
