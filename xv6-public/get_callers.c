#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    printf(1, "USER: get_callers() is called for write (id = 16)\n");
    get_callers(16);
    printf(1, "USER: get_callers() is called for fork (id = 1)\n");
    get_callers(1);
    printf(1, "USER: get_callers() is called for wait (id = 3)\n");
    get_callers(3);
    exit();
}