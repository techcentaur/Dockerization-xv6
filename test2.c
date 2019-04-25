#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    call_ls();

    sleep(100);
    int c1 = create_container();
    int c2 = create_container();
    int c3 = create_container();

    if(c1<0 || c2<0 || c3<0){
        printf(1, "Error in creating container!\n");
    }

    int child1;
    child1 = fork();
    if(child1==0){
    	printf(1, "Child with pid: %d + cid %d\n", getpid(), c2);
        
        int j1 = join_container(c2);
        if(j1<0){
            printf(1, "Can't join container pid: %d\n", getpid());
        }
        // char* msg = (char*)malloc(8);
        // msg = "testfile1.txt";
        // int co = container_open(msg, 512);
        // if(co < 0){
        //     printf(1, "Open call unsuccessful!\n");
        // }
        cont_call_ls();
        leave_container();
        // kill(getpid());
        exit();
    }else{
        wait();
        exit();
        // join_container(c3);
        // sleep(1000);
    }
    // wait();
}