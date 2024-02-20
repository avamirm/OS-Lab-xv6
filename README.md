# OS-LAB-xv6
A modified [xv6](https://github.com/mit-pdos/xv6-public) operating system with some extra features.

## 1. Introduction to xv6
* Added contributors' names to the system boot message
* Added following keyboard shortcuts to the console: 

    i) `Ctrl + N` : Removing all the digits from the console

    ii) `Ctrl + R` : Reversing the current line

    iii) `Tab` : Substituting the current line with a command from the history

* Finding the prime numbers in the range [a, b] with the `prime_numbers a b` command.

## 2. System Calls
* `find_largest_prime_factor` : This system call finds the largest prime factor of a given number. The parameter of this system call is passed in the ebx register.

* `change_file_size` : This system call changes the size of the file by adding zeros to the end of the file or removing the last bytes of the file

* `get_callers` : This system call returns the history of the callers of every system call.

* `get_parent_pid` : This system call returns the parent process id of the current process.

## 3. CPU Scheduling
* Added 3 different queues:

    i) Round-Robin (with the highest priority)

    ii) Lottery-queue: The chance of each process for being executed is showed with a number.

    iii) Best-Job-First: The process with the lowest rank is executed first.
* Added Aging: If a runnable process has not been executed for 8000 ticks, we move it to the Round-Robin queue. By default all the processes except the init and sh processes are in Lottery queue.

* The following system calls are also added:

    i) `int change_scheduling_queue(int pid, int queue)`: Changes the scheduling queue of a process.

    ii) `set_bjf_params_process(int pid, float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio)`: Sets the Best Job First parameters for a process.

    iii) `int set_bjf_params_system(float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio)`: Sets the Best Job First parameters for a system.

    iv) `int set_lottery_tickets(int pid, int tickets)`: Sets the lottery tickets of a process.

    v) `print_process_info(void)`: Shows the processes information.

## 4. Synchronization
* System calls which initialize, acquire, and release a semaphore are added.
* The simulation of the Dining-Philosophers is implemented. 








