#include <sys/select.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    fd_set readSetTemplate;
    fd_set readSet;
    FD_SET(0, &readSetTemplate);  // stdin
    int fdNum = 1;
    char *recvLine;
    while (true) {
        readSet = readSetTemplate;
        int activeFdNum = select(fdNum, &readSet, NULL, NULL, NULL);
        if (activeFdNum > 0) {
            if (FD_ISSET(STDIN_FILENO, &readSet)) {
                if (fgets(recvLine, 1024, stdin) != NULL) {
                    printf("Your input is: %s", recvLine);
                }
            }
        }
    }
    return 0;
}