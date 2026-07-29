#include <stdio.h>

int AND(int a, int b) {
    return a && b;
}

int OR(int a, int b) {
    return a || b;
}

int NOT(int a) {
    return !a;
}

int XOR(int a, int b) {
    return a ^ b;
}

int main(void) {
    int a = 1, b = 0;

    printf("Testing Logic Gates with a=%d, b=%d\n", a, b);
    printf("------------------------------------\n");
    printf("AND(%d, %d) = %d\n", a, b, AND(a, b));
    printf("OR(%d, %d)  = %d\n", a, b, OR(a, b));
    printf("NOT(%d)     = %d\n", a, NOT(a));
    printf("XOR(%d, %d) = %d\n", a, b, XOR(a, b));

    return 0;
}
