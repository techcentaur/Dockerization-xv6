#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    scheduler_log_on();
    int c1 = create_container();
    int c2 = create_container();
    if(c1<0 || c2<0){
        printf(1, "Error in creating container!\n");
    }

    printf(1, "Parent PID: %d\n", getpid());
    int child1, child2;
    child1 = fork();
    if(child1==0){
        printf(1, "Child1 PID: %d\n", getpid());
        int j1 = join_container(c1);
        if(j1<0){
            printf(1, "Can't join container pid: %d\n", getpid());
        }
        ps();
        sleep(10);
    }else{
        child2 = fork();
        if(child2==0){
            printf(1, "Child2 PID: %d\n", getpid());
            int j1 = join_container(c2);
            if(j1<0){
            printf(1, "Can't join container pid: %d\n", getpid());
            }
            sleep(30);
            ps();
        }else{
            join_container(c2);
            sleep(50);
            ps();
        }
    }

    // scheduler_log_on();
    // // ps();
    int i, j, k, p;
    for(i=0; i<1000;i++){
        for(j=0; j< 1000; j++){
            for(k=0; k<1000; k++){
                    p = ((i+1)*i) % i;
            }
        }
    }
    printf(1, "p: %d\n", p);
    // // scheduler_log_off();
    leave_container();

    printf(1, "%d is here\n", getpid());
    exit();
}