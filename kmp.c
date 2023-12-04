#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buildPrefixTable(const char *pattern, int *lps, size_t m) {
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

int kmpSearch(char *text, const char *pattern) {
  if (text == NULL || pattern == NULL) {
    return -1;
  }
  size_t n = strlen(text);
  size_t m = strlen(pattern);

  if (m == 0) {
    return -1;
  }

  int *lps = (int *)malloc(sizeof(int) * m);

  if (lps == NULL) {
    return -1;
  }

  memset(lps, 0, sizeof(int) * m);  // Initialize with zeros

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
