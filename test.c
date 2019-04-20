#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    // int c1 = create_container();
    // int c2 = create_container();

    // int child1 = fork();
    // if (child1==0) {
    //     join_container(c1);
    //     ps();
    // } else {
    //     join_container(c2);
    //     ps();
    // }
    int child1 = fork();
    if(child1==0){
        void *m = malloc(4);
        // *m = 10;
        printf(1, "mem: %d | pid %d\n", m, getpid());
        printf(1, "value: %d\n", *m);
        m = m -1000;
        printf(1, "mem: %d\n", m);

    }else{
        // int *k = malloc(8);
        // *k = 1235.21;
        // printf(1, "mem: %d | pid %d\n", k, getpid());
        // printf(1, "value: %d\n", *k);
    }
    exit();
}