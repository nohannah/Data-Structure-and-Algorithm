#include <stdio.h>

int main() {
    int nums[] = {3, 4, 5, 6};
    int target = 7;
    int n = 4;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d, %d]\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}