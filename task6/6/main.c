#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (void) {
    int status;
    int pid;

    if ((pid = fork()) == 0) {
        execlp("ls", "ls", NULL);
        fprintf (stderr, "Exec error\n");
        printf("Process ID: %d", pid);
        exit(0);
    }
    system("ps");
    sleep(60);

    wait(&status);
    
    if (WIFEXITED (status)) {
        printf ("Code=%d\n", WEXITSTATUS(status));
    }
    
    system("ps");

    return 0;
}
