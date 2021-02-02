#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_term_handler(int signum, siginfo_t *info, void *ptr)
{
    int count = 0;
    while (1) {
        printf("ignore SIGTERM (%ds)\n", count++);
        sleep(1);

        if (count > 3000) {
            break;
        }
    }
}

void catch_sigterm()
{
    static struct sigaction _sigact;

    memset(&_sigact, 0, sizeof(_sigact));
    _sigact.sa_sigaction = sig_term_handler;
    _sigact.sa_flags = SA_SIGINFO;

    sigaction(SIGTERM, &_sigact, NULL);
}


int main() {
    catch_sigterm();

    int *ptr = NULL;
    int gb = 1024 * 1024 * 1024;

    while(1) {
        ptr = malloc(gb);
        memset(ptr, 0, gb);
        sleep(5);
    }
    
    return 0;
}
