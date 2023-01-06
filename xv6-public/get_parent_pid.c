#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int process_id = getpid();
    printf(1, "USER: get_parent_pid() is called\n");
    int parent_pid = get_parent_pid();
    printf(1, "The first proccess id is: %d, and its parent pid is: %d\n", process_id, parent_pid);

    int pid0 = fork();
    if(!pid0)
    {
        int process_id = getpid();
        printf(1, "USER: get_parent_pid() is called\n");
        int parent_pid = get_parent_pid();
        printf(1, "The second proccess id is: %d, and its parent pid is: %d\n", process_id, parent_pid);

        int pid1 = fork();
        if(!pid1)
        {
            int process_id = getpid();
            printf(1, "USER: get_parent_pid() is called\n");
            int parent_pid = get_parent_pid();
            printf(1, "The third process id is: %d, and its parent pid is: %d\n", process_id, parent_pid);
        }
    }
    wait();
    exit();
}