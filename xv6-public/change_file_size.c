#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf(1, "error: numbers of arguments are uncorrect!\n");
        exit();
    }

    printf(1, "USER: change_file_size() is called\n");
    change_file_size(argv[1], atoi(argv[2]));
    exit();
}