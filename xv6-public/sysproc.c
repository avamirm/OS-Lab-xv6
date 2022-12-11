#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int sys_fork(void)
{
  return fork();
}

int sys_exit(void)
{
  exit();
  return 0; // not reached
}

int sys_wait(void)
{
  return wait();
}

int sys_kill(void)
{
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void)
{
  return myproc()->pid;
}

int sys_sbrk(void)
{
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void)
{
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (myproc()->killed)
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_find_largest_prime_factor(void)
{
  int num = myproc()->tf->ebx;
  cprintf("KERNEL: sys_find_largest_prime_factor() is called for n = %d\n", num);
  return find_largest_prime_factor(num);
}

int sys_get_parent_pid(void)
{
  cprintf("KERNEL: sys_get_parent_pid() is called\n");
  return get_parent_pid();
}

#define PROC_HIST_SIZE 1000
#define SYSCALL_SIZE 25

int process_count[SYSCALL_SIZE] = {0};
int process_history[SYSCALL_SIZE][PROC_HIST_SIZE] = {0};

void add_process_history(int sys_call_id, int pid)
{
  process_history[sys_call_id - 1][process_count[sys_call_id - 1] % PROC_HIST_SIZE] = pid;
  process_count[sys_call_id - 1] += 1;
}

int sys_get_callers(void)
{
  int sys_call;
  if(argint(0, &sys_call) < 0)
    return -1;
  cprintf("KERNEL: sys_get_callers() is called for system call with id = %d\n", sys_call);
  if(process_count[sys_call - 1] <= PROC_HIST_SIZE)
  {
    for (int i = 0; i < process_count[sys_call - 1]; i++)
    {
      if(i != process_count[sys_call - 1] - 1)
        cprintf("%d,", process_history[sys_call - 1][i]);
      else
        cprintf("%d\n", process_history[sys_call - 1][i]);
    }
  }
  else
  {
    int start = process_count[sys_call - 1] % PROC_HIST_SIZE;
    for (int i = start; i < start + PROC_HIST_SIZE; i++)
    {
      int index = i % PROC_HIST_SIZE;
      if(index  == start - 1)
        cprintf("%d\n", process_history[sys_call - 1][index]);
      else
        cprintf("%d,", process_history[sys_call - 1][index]);
    }
  }
  return 0;
}

void sys_change_queue(void)
{
  int pid, queue;
  argint(0, &pid);
  argint(1, &queue);
  change_queue(pid, queue);
}

void sys_set_ticket_chance(void)
{
  int pid, ticket_chance;
  argint(0, &pid);
  argint(1, &ticket_chance);
  set_ticket_chance(pid, ticket_chance);
}

int // what would happen if it were void?
sys_set_bjf_s(void)
{
  int priority_ratio, arrival_time_ratio, executed_cycle_ratio;
  argint(0, &priority_ratio);
  argint(1, &arrival_time_ratio);
  argint(2, &executed_cycle_ratio);
  set_bjf_s(priority_ratio, arrival_time_ratio, executed_cycle_ratio);
  return 0;
}

int
sys_set_bjf_u(void)
{
  int pid, priority_ratio, arrival_time_ratio, executed_cycle_ratio;
  argint(0, &pid);
  argint(1, &priority_ratio);
  argint(2, &arrival_time_ratio);
  argint(3, &executed_cycle_ratio);
  set_bjf_u(pid, priority_ratio, arrival_time_ratio, executed_cycle_ratio);
  return 0;
}

void
sys_print_all_processes(void)
{
  print_all_processes();
}