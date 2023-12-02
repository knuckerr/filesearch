#ifndef KMP_H

#define KMP_H

void buildPrefixTable(char *pattern, int *lps, int m);

int kmpSearch(char *text, char *patern);

#endif
