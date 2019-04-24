#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    scheduler_log_on();
    int c1 = create_container();
    int c2 = create_container();

    // ps();

    printf(1, "A\n");
    int child1 = fork();
    int x = 1;
    for (int i=1; i<100000; i++) {
        for (int j=1; j<1000; j++) {
            if (i%2==0) {
                x *= i;
                x *= j;
            } else {
                x *= i*i;
                x *= j*j;
            }
            // printf(1, "%d");
        }
    }
    for (int i=1; i<100000; i++) {
        for (int j=1; j<1000; j++) {
            if (i%2==0) {
                x *= i;
                x *= j;
            } else {
                x *= i*i;
                x *= j*j;
            }
            // printf(1, "%d");
        }
    }
    sleep(100);
    printf(1, "%d\n", x);
    if (child1==0) {
        join_container(c1);
        ps();
        // printf(1, "child\n");
    } else {
        join_container(c2);
        ps();
        // printf(1, "parent\n");
        // scheduler_log_off();
        // wait();
    }
    // printf(1, "reached\n");

    // leave_container();
    // leave_container();
    exit();
}