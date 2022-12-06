#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#define SEC 5

int main(void) {
    pid_t pid;
    pid = fork();
    int count_1 = 0, count_2 = 0;
    time(NULL);
    clock_t begin = clock();
    clock_t end;
    double time;

    while (1) {
        end = clock();
        time = (double)(end - begin) / CLOCKS_PER_SEC;
        if (time >= SEC)
            break;
        if (pid == 0) {
            count_1++;
        } else if (pid > 0) {
            count_2++;
        } else {
            printf("Error wiki fork, pad not created\n");
        }
    }
    printf("\n%d | %d | time = %d sec\n", count_1, count_2, (int)time);
    
    return 0;
}
