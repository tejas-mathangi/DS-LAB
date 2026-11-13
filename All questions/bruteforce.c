#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "ABAAABCDBBABCDDEBCABC";
    char pattern[] = "ABC";

    int n = strlen(text);
    int m = strlen(pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n\n", pattern);

    printf("Pattern found at indices: ");

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // Check if pattern matches starting at i
        while(j<m && text[i+j]==pattern[j]){
            j++;
        }

        // If full pattern matched
        if (j == m) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
