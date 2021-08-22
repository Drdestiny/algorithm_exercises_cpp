#include <poll.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main() {
    int i = 10;
    pollfd eventSet[i];
    eventSet[0].fd = STDIN_FILENO;
    eventSet[0].events = POLLIN;
    char *recvLine;
    while (true) {
        int readyFdNum = poll(eventSet, 1, -1);
        if (readyFdNum > 0) {
            if (fgets(recvLine, 1024, stdin) != NULL) {
                printf("Your input is: %s", recvLine);
            }
        }
    }
    return 0;
}