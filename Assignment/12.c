#include <stdio.h>

int findJudge(int n, int trust[][2], int trustSize) {
    int score[n + 1];

    // initialize
    for (int i = 1; i <= n; i++) {
        score[i] = 0;
    }

    // process trust relations
    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];

        score[a]--;  // a trusts someone → cannot be judge
        score[b]++;  // b is trusted
    }

    // find judge
    for (int i = 1; i <= n; i++) {
        if (score[i] == n - 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n = 4;

    int trust[][2] = {
        {1, 3},
        {4, 3},
        {2, 3}
    };

    int trustSize = 3;

    int result = findJudge(n, trust, trustSize);

    printf("Town Judge = %d\n", result);

    return 0;
}