#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int c1 = create_container();
    int c2 = create_container();

    int child1, child2;
    child1 = fork();
    if(child1==0){
        join_container(c1);
        int i, j;
        for(i=0; i<100000;i++){
            j=1;
        }
        printf(1, "j: %d\n", j);
        // ps();
    } else {
        join_container(c2);
        child2 = fork();
        if(child2==0){
            sleep(30);
            join_container(c2);
            int i, j;
            for(i=0; i<100000;i++){
                j=1;
            }
            printf(1, "k: %d\n", j);
            // ps();
        }else{
            sleep(100);
        }
    }
    ps();
    printf(1, "%d is here\n", getpid());
    exit();
}