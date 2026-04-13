#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char s[], char t[]) {
    // If lengths are different → not anagram
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[256] = {0}; // for all ASCII characters

    // Count characters of s
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    // Subtract characters using t
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i]]--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char s[] = "stop";
    char t[] = "post";

    if (isAnagram(s, t)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}