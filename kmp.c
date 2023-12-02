#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buildPrefixTable(char *pattern, int *lps, int m) {
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            ++j;
        }

        lps[i] = j;
    }
}

int kmpSearch(char *text, char *pattern) {
    if (text == NULL || pattern == NULL) {
        return -1;
    }

    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0) {
        return -1;
    }

    int *lps = (int *)malloc(sizeof(int) * m);

    if (lps == NULL) {
        return -1;
    }

    buildPrefixTable(pattern, lps, m);

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1];
        }

        if (text[i] == pattern[j]) {
            ++j;
        }

        if (j == m) {
            int index = i - j + 1;
            free(lps);
            return index;
        }
    }
    free(lps);
    return -1;
}
