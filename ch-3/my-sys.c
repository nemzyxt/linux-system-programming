#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(void) {
    char cwd[100] = {0};
    struct sysinfo si;
    getcwd(cwd, 100);
    sysinfo(&si);

    printf("User ID : %d\n", getuid());
    printf("Effective User ID : %d\n", geteuid());
    printf("Current Working Directory : %s\n", cwd);
    printf("Total RAM : %ldMBs\n", si.totalram / 1024 / 1024);
    printf("Free RAM : %ldMBs\n", si.freeram / 1024 /1024);
    printf("Number of running Processes : %d\n", si.procs);
    printf("Process ID : %d\n", getpid());
    printf("Parent Process ID : %d\n", getppid());

    return 0;
}

