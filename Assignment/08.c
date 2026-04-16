#include <stdio.h>
#include <stdlib.h>
int* asteroidCollision(int* asteroids, int n, int* returnSize) {
    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        int a = asteroids[i];
        int alive = 1;

        while (top > 0 && stack[top - 1] > 0 && a < 0) {
            if (stack[top - 1] < -a) {
                top--; // stack asteroid explodes
            }
            else if (stack[top - 1] == -a) {
                top--; // both explode
                alive = 0;
                break;
            }
            else {
                alive = 0; // current asteroid explodes
                break;
            }
        }

        if (alive) {
            stack[top++] = a;
        }
    }

    int* result = (int*)malloc(top * sizeof(int));
    for (int i = 0; i < top; i++) {
        result[i] = stack[i];
    }

    *returnSize = top;
    return result;
}

int main() {
    int asteroids[] = {2, 4, -4, -1};
    int n = 4;

    int returnSize;

    int* res = asteroidCollision(asteroids, n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}