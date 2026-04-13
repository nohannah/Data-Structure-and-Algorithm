#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char** operations, int n) {
    int stack[1000];
    int top = 0;

    for (int i = 0; i < n; i++) {

        if (strcmp(operations[i], "+") == 0) {
            stack[top] = stack[top - 1] + stack[top - 2];
            top++;

        } else if (strcmp(operations[i], "D") == 0) {
            stack[top] = 2 * stack[top - 1];
            top++;

        } else if (strcmp(operations[i], "C") == 0) {
            top--;

        } else {
            stack[top++] = atoi(operations[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i < top; i++) {
        sum += stack[i];
    }

    return sum;
}

int main() {
    char *operations[] = {"1","2","+","C","5","D"};
    int n = 6;

    printf("%d\n", calPoints(operations, n)); // Output: 18

    return 0;
}