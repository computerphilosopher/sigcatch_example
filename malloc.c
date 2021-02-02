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


int main(int argc, char** argv) {
    catch_sigterm();

    int *ptr = NULL;
    //100mib
    int to_alloc = 1024 * 1024 * 100;

    //1Gib
    long long total_alloc = 1024 * 1024 * 1024;
    if (argc > 1) {
        total_alloc = atoi(argv[1]);
        if (total_alloc == 0) {
            perror("atoi failed\n");
        }
    }
    printf("total alloc bytes: %lld\n", total_alloc);

    int cur_bytes = 0;
    while (cur_bytes < total_alloc) {
        ptr = malloc(to_alloc);
        memset(ptr, 0, to_alloc);
        cur_bytes += to_alloc;
        sleep(1);
    }

    while(1) {
        sleep(10);
    }
    
    return 0;
}
