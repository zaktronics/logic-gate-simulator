#include <stdio.h>
#include <string.h>

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

typedef struct {
    char type[6];
    int srcAIsGate;
    int srcA;
    int srcBIsGate;
    int srcB;
    int result;
} GateNode;

int evaluateGateByName(const char *type, int a, int b) {
    if (strcmp(type, "AND") == 0)  return AND(a, b);
    if (strcmp(type, "OR") == 0)   return OR(a, b);
    if (strcmp(type, "NOT") == 0)  return NOT(a);
    if (strcmp(type, "XOR") == 0)  return XOR(a, b);
    if (strcmp(type, "NAND") == 0) return NAND(a, b);
    if (strcmp(type, "NOR") == 0)  return NOR(a, b);
    if (strcmp(type, "XNOR") == 0) return XNOR(a, b);

    printf("Unknown gate type: %s\n", type);
    return -1;
}

void evaluateCircuit(GateNode circuit[], int numGates, int rawInputs[]) {
    printf("\n--- Evaluating Circuit ---\n");
    for (int i = 0; i < numGates; i++) {
        int valA = circuit[i].srcAIsGate ? circuit[circuit[i].srcA].result
                                          : rawInputs[circuit[i].srcA];
        int valB = circuit[i].srcBIsGate ? circuit[circuit[i].srcB].result
                                          : rawInputs[circuit[i].srcB];

        circuit[i].result = evaluateGateByName(circuit[i].type, valA, valB);

        printf("Gate %d [%s]: inputs=(%d, %d) -> output=%d\n",
               i, circuit[i].type, valA, valB, circuit[i].result);
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

    int rawInputs[3] = {1, 0, 1};

    GateNode circuit[2];

    circuit[0].srcAIsGate = 0;
    circuit[0].srcA = 0;
    circuit[0].srcBIsGate = 0;
    circuit[0].srcB = 1;
    strcpy(circuit[0].type, "AND");

    circuit[1].srcAIsGate = 1;
    circuit[1].srcA = 0;
    circuit[1].srcBIsGate = 0;
    circuit[1].srcB = 2;
    strcpy(circuit[1].type, "OR");

    printf("\nCircuit: (A AND B) OR C, with A=%d, B=%d, C=%d\n",
           rawInputs[0], rawInputs[1], rawInputs[2]);

    evaluateCircuit(circuit, 2, rawInputs);

    printf("\nFinal circuit output: %d\n", circuit[1].result);

    return 0;
}
