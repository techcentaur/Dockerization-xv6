## Virtualization-xv6

Virtualization of toy operating system xv6: Explicit inspiration from how [Docker](https://github.com/docker) works.

> Distribution used: Ubuntu Linux 18.04

### Why Virtualization is Important?

Virtualization is used to provide isolation, flexibility, higher resource utilization, easy resource management as well as resource elasticity and to enable co-existence of heterogeneous services on the same physical hardware.

Note: LXC or Linux containers is already an implementation of containers within the Linux kernel.

### About this Project

The purpose of this project is to familiarize with the concepts of virtualization by implementing it in XV6. These implementations will mimic the functionalities provided by a container and will NOT be a full fledged container service.

Please note that in an actual container implementation, the kernel is not aware of the processes created and running inside a container and it is the responsibility of the container to handle all the OS related operations, for the processes running inside that container, such as the memory manager, file system, system call handling etc. However, implementing all the features in XV6 is too hard, and time-consuming, and not aligned with the purpose of this project, with is to get started.


+ A more elaborate project aim and guidelines can be found [here](https://github.com/techcentaur/Dockerisation-xv6/blob/master/main.pdf).


### Brief Explanation

<dl>
	<dt>Process Structure</dt>
</dl>

```c
struct proc {
  ...

  int containerId; // which container does it belongs to
  enum procstate vState; // state which container schedular sees 
};
```

<dl>
	<dt>Container Data-Structure</dt>
</dl>

```c
#define maxfiles 10
#define maxContainerNum 10

typedef struct procReference {
  int procAlive;  // is proces alive?
  struct proc* pointerToProc; // pointer to process
} procRef;

typedef struct containerType {
  procRef procReferenceTable[NPROC]; // list of process references in container
  int containerAlive; // is container alive?
  int nextProcRefTableFreeIndex;
  int lastScheduleProcRefTableIndex;
} container;
```

<dl>
	<dt>File Data-Structure</dt>
</dl>

```c
typedef struct fstruct{
  int cfd; // container file descriptor
  int fd;  // file descriptor
  int pid; // process id
} fentry;

struct fTable{
  char names[maxfiles][20];
  int ids[maxfiles];
  int size;
};
```

> A more elaborate report is attached [here](https://github.com/techcentaur/Dockerisation-xv6/blob/master/report.pdf).

### Contact
Feel free to ask any question about the project: As an issue of this project, or directly as a mail at: ankit03june AT gmail DOT com