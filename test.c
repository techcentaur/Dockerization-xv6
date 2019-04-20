#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    scheduler_log_on();
    int c1 = create_container();
    int c2 = create_container();

    ps();

    int child1 = fork();
    if (child1==0) {
        join_container(c1);
        ps();
        printf(1, "child\n");
    } else {
        join_container(c2);
        ps();
        printf(1, "parent\n");
        scheduler_log_off();
    }
    printf(1, "reached\n");

    exit();
}