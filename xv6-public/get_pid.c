#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid = getpid();
    printf(1, "The getpid() value is: %d\n", pid);
    exit();
}