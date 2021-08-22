#include <fcntl.h>
#include <memory.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct s_test {
    int member1;
    int member2;
};

int main() {
    s_test test;
    struct stat s;
    memset(&s, 0, sizeof(s));
    stat("/etc/shadowsocks.json", &s);
    if (S_ISREG(s.st_mode)) {
        cout << "It's a regular file." << endl;
    } else {
        cout << "It's not a regular file." << endl;
    }
    char *buf;
    buf = getenv("HOME");
    size_t len = strlen(buf);
    for (size_t i = 0; i < len; i++) {
        cout << buf[i];
    }
    cout << endl;
    int fd = open("/etc/shadowsocks.json", O_RDWR);
    int rt = fcntl(fd, F_GETFL);
    printf("%x\n", O_ACCMODE & rt);
#ifdef _POSIX_THREADS
    cout << "POSIX DEFINED" << endl;
#else
    cout << "POSIX NOT DEFINED" << endl;
#endif
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    time_t t;
    pthread_spinlock_t spin;
    cout << pthread_self() << endl;
    return 0;
}