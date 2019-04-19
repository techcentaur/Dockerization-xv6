#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

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
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
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
    if(myproc()->killed){
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
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_create_container(void) {
	return create_container();
}

int sys_destroy_container(uint containerId) {
	if (argint(0, &containerId) < 0) {
		return -1;
	}
	return destroy_container(containerId);
}

int sys_join_container(uint containerId) {
	if (argint(0, &containerId) < 0) {
		return -1;
	}
	return join_container(containerId);
}

int sys_leave_container(void) {
	return leave_container();
}

// print all fellow processes visible
int sys_ps(void)
{
  struct proc* p = myproc();
  
  // if not in any container
  _container_id = p->containerId;
  if(_container_id == -1){
    // print all processes not in any container
    for(p=ptable.proc; p < &ptable.proc[NPROC]; p++)
    {
      if(p->containerId == -1)
        cprintf("container: %d pid:%d name:%s\n", p->containerId, p->pid, p->name);
    }

  }else if(_container_id < maxContainerNum){
    // print all processes visible inside container and which are unused
    for(p=ptable.proc; p < &ptable.proc[NPROC]; p++)
    {
      if(p->containerId == _container_id)
        if(p->vState != UNUSED){
          cprintf("container: %d pid:%d name:%s\n", p->containerId, p->pid, p->name);
        }
      }
  }else{
    return -1;
  }
}
