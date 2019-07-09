#include <cstdio>

// this file is the implementation of KMP algorithm

#define MAX_N 100010
char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;             // b = back table, n = length of T, m = length of P

void kmpPreprocess() {          // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values;
  while(i < m) {                // pre-process the pattern string P
    while(j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
    i++; j++;                               // if same, advance both pointers
    b[i] = j;                               // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
  }                                         // in the example of P = "SEVENTY SEVEN" above
}

void kmpSearch() {
  int i=0, j = 0;
  while(i < n) {
    while(j >= 0 && T[i] != P[j]) j = b[j];
    i++; j++;
    if(j == m) {
      printf("P is found at index %d in T\n", i - j);
      j = b[j];
    }
  }
}
