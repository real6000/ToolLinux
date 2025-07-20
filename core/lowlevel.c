#include "lowlevel.h"
#include <stdio.h>
#include <string.h>

int read_cpu_model(char *buffer, int buffer_len) {
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) return -1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "model name", 10) == 0) {
            char *colon = strchr(line, ':');
            if (colon) {
                strncpy(buffer, colon + 2, buffer_len - 1); // +2 skips ": "
                buffer[buffer_len - 1] = '\0';
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);
    return -1;
}
