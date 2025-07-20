# CMake file for test targets

file(GLOB_RECURSE TEST_SOURCES *.cpp)

add_executable(runTests ${TEST_SOURCES})

target_include_directories(runTests PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/modules
        ${CMAKE_SOURCE_DIR}/utils
)

target_link_libraries(runTests PRIVATE pthread)
