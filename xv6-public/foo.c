#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int pid[12];
    for (int i = 0 ; i < 6 ; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            long long temp = 1;
            for (int j = 0 ; j < 4000000000 ; j++)
            {
                temp += 1;
            }
        }
    }
    while (wait());
    return 0;
}