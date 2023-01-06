#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int id;
    char *in[]={"0"};
    for(int i=0;i<5;i++)
    {
        sem_init(i,1);
        in[0][0]=i+'0';
        id=fork();
        if(id==0)
            exec("philosophers",in);
        
        printf(1,"%d complete\n",i);
        sleep(10);
    }
    for(int i=0;i<5;i++)
        wait();
}