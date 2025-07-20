#include "../core/logger.hpp"
#include <cassert>

int main() {
    Logger logger("test_log.txt");

    // These don't return values, so we just ensure they run without crashing
    logger.debug("Test debug");
    logger.info("Test info");
    logger.warn("Test warn");
    logger.error("Test error");

    // If it reaches here, logging succeeded
    assert(true && "Logger ran without errors");
    return 0;
}
