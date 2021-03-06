#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"

int
sys_fork(void)
{
	return fork();
}

int
sys_exit(void)
{
	exit();
	return 0;  // not reached
}

int
sys_wait(void)
{
	return wait();
}

extern int shmem_count[SHMEM_PAGES];
int sys_shmem_count(void)
{
	int pageno;
	if(argint(0, &pageno)<0)
		return -1;
	if(pageno<0 || pageno>=SHMEM_PAGES)
		return -1;
	return shmem_count[pageno];
}
int sys_shmem_access(void)
{
	int pageno;
	if(argint(0, &pageno)<0)
		return NULL;

	if(pageno<0 || pageno>=SHMEM_PAGES)
		return NULL;

	// Can't open the same page twice
	if(proc->shpages[pageno] != NULL)
		return (int)(proc->shpages[pageno]);

	return (int)shmem_access(proc, pageno);
}

int
sys_kill(void)
{
	int pid;

	if(argint(0, &pid) < 0)
	  return -1;
	return kill(pid);
}

int
sys_getpid(void)
{
	return proc->pid;
}

int
sys_sbrk(void)
{
	int addr;
	int n;

	if(argint(0, &n) < 0)
	  return -1;
	addr = proc->sz;
	if(((int)addr + n)>=(USERTOP - PGSIZE*proc->shpages_quantity))
		return -1;
	if(growproc(n) < 0)
	  return -1;
	return addr;
}

int
sys_sleep(void)
{
	int n;
	uint ticks0;
	
	if(argint(0, &n) < 0)
	  return -1;
	acquire(&tickslock);
	ticks0 = ticks;
	while(ticks - ticks0 < n){
	  if(proc->killed){
	    release(&tickslock);
	    return -1;
	  }
	  sleep(&ticks, &tickslock);
	}
	release(&tickslock);
	return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
	uint xticks;
	
	acquire(&tickslock);
	xticks = ticks;
	release(&tickslock);
	return xticks;
}
