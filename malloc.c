#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int *ptr = NULL;
    int gb = 1024 * 1024 * 1024;

    while(1) {
        ptr = malloc(gb);
        memset(ptr, 0, 0);
        sleep(5);
    }
}
