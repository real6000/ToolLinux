cmake_minimum_required(VERSION 3.31)
project(ToolLinux LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

# Add include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/modules
        ${CMAKE_SOURCE_DIR}/utils
        ${CMAKE_SOURCE_DIR}/data
)

# Gather all source files (C and C++)
file(GLOB_RECURSE SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/core/*.cpp
        ${CMAKE_SOURCE_DIR}/core/*.c
        ${CMAKE_SOURCE_DIR}/modules/**/*.cpp
        ${CMAKE_SOURCE_DIR}/utils/*.cpp
        ${CMAKE_SOURCE_DIR}/main.cpp
)

add_executable(ToolLinux ${SOURCES}
        include/config.hpp
        core/logger.cpp
        core/logger.hpp
        core/lowlevel.c
        core/lowlevel.h
        modules/disktool/disk_info.cpp
        modules/disktool/disk_info.hpp
        modules/monitor/net_scan.cpp
        modules/monitor/net_scan.hpp
        modules/nettool/process_monitor.cpp
        modules/nettool/process_monitor.hpp
        utils/string_util.cpp
        utils/string_util.hpp
        io/file_io.cpp
        io/file_io.hpp
        data/model.hpp
        data/settings.hpp
        config/config_manager.cpp
        config/config_manager.hpp)
