#include <stdio.h>

/*
#include <stdio.h>

int main() {
    double j=20;
    void *v;
    v=&j;
    printf("%f", ____);
    return 0;
}
*/

int main() {
    double j=20;
    void *v;
    v=&j;
    printf("%f", *((double*)v));
    return 0;
}