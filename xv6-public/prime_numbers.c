#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void primeNumbers(int first, int second) {
    int i = 0;
    int low, high, flag;

    unlink("prime_numbers.txt");
    int fd = open("prime_numbers.txt", O_CREATE | O_RDWR);

    if (first < second) {
        low = first; high = second;
    }
    else {
        low = second; high = first;
    }
    while (low < high) {
        flag = 0;

        if (low <= 1) {
            ++low;
            continue;
        }

        for (i = 2; i <= low / 2; ++i) {

            if (low % i == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf(fd, "%d ", low);
        }
        ++low;
    }
    printf(fd, "%c", '\n');
    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf(2, "Error: number of args...\n");
        exit();
    }
    
    primeNumbers(atoi(argv[1]), atoi(argv[2]));
    exit();
}