#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int c1 = create_container();
    int c2 = create_container();

    int child1 = fork();
    if (child1==0) {
        join_container(c1);
        ps();
        ps();
        printf(1, "child");
    } else {
        join_container(c2);
        ps();
        ps();
        printf(1, "parent");
    }
    printf(1, "reached");

    exit();
}