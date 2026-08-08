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

int NAND(int a, int b) {
    return NOT(AND(a, b));
}

int NOR(int a, int b) {
    return NOT(OR(a, b));
}

int XNOR(int a, int b) {
    return NOT(XOR(a, b));
}

void printTruthTable(int (*gateFunc)(int, int), const char *gateName) {
    printf("\nTruth Table: %s\n", gateName);
    printf("A B | Output\n");
    printf("----+------\n");

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d %d |   %d\n", a, b, gateFunc(a, b));
        }
    }
}

int main(void) {
    int a = 1, b = 0;

    printf("Testing Logic Gates with a=%d, b=%d\n", a, b);
    printf("------------------------------------\n");
    printf("AND(%d, %d) = %d\n", a, b, AND(a, b));
    printf("OR(%d, %d)  = %d\n", a, b, OR(a, b));
    printf("NOT(%d)     = %d\n", a, NOT(a));
    printf("XOR(%d, %d) = %d\n", a, b, XOR(a, b));
    printf("NAND(%d, %d)= %d\n", a, b, NAND(a, b));
    printf("NOR(%d, %d) = %d\n", a, b, NOR(a, b));
    printf("XNOR(%d, %d)= %d\n", a, b, XNOR(a, b));

    printTruthTable(AND, "AND");
    printTruthTable(OR, "OR");
    printTruthTable(XOR, "XOR");
    printTruthTable(NAND, "NAND");
    printTruthTable(NOR, "NOR");
    printTruthTable(XNOR, "XNOR");

    return 0;
}
