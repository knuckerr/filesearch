#ifndef KMP_H

#define KMP_H

void buildPrefixTable(const char *pattern, int *lps, int m);

int kmpSearch(char *text, const char *patern);

#endif
