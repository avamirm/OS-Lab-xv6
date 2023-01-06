#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int i=argv[0][0]-'0';
    while (1)
    {
       
        
        sleep(20);
        pickup(i);
        printf(1, "philosopher %d in critical\n", i + 1);
        if (i==0)
            sleep(150);
        else
            sleep(30);
        putdown(i);
    }
}