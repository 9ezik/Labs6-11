#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>


int main (int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    if (pid == 0)
    {
        execv(argv[0], argv);
        perror("execv");
        return 1;
    }

    int status;
    pid_t wait_result;
    while ((wait_result = wait(&status)) != -1) {
        printf("Process %lu returned result: %d\n", (unsigned long) wait_result, status);
    }
    return 0;
}
