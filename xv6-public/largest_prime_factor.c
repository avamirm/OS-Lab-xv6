#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        if(argc < 2)
		    printf(2, "Error: you didn't enter the number!\n");
        else if(argc > 2)
            printf(2, "Error: Too many arguments!\n");
		exit();
	}
    else
    {

		int last_ebx_value;
		int num = atoi(argv[1]);
		
		asm volatile(
			"movl %%ebx, %0;" // last_ebx_value = ebx
			"movl %1, %%ebx;" // ebx = num
			: "=r" (last_ebx_value)
			: "r"(num)
		);
		printf(1, "USER: find_largest_prime_factor() is called for n = %d\n" , num);
        int answer = find_largest_prime_factor();
		printf(1, "largest prime factor in number %d is: %d\n" , num , answer);

		asm("movl %0, %%ebx"
             : 
             : "r"(last_ebx_value)
        ); 	
    }
    exit();
} 