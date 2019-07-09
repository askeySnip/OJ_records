/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
char T[700];
int len;
int SA[700], tempSA[700];
int RA[700], tempRA[700];
int c[700];
int lcp[700], phi[700], plcp[700];

void countSorting(int k) {
  int sum, maxi = max(300, len);
  memset(c, 0, sizeof c);
  for(int i=0; i<len; i++) {
    c[i + k < len ? RA[i+k] : 0]++;
  }
  for(int i=sum=0; i<maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for(int i=0; i<len; i++) {
    tempSA[c[SA[i] + k < len ? RA[SA[i] + k] : 0]++] = SA[i];
  }
  for(int i=0; i<len; i++) {
    SA[i] = tempSA[i];
  }
}

void constructSA() {
  int i, r, k;
  for (i=0; i<len; i++) SA[i] = i;
  for (i=0; i<len; i++) RA[i] = T[i];
  for(k=1; k<len; k<<=1) {
    countSorting(k);
    countSorting(0);
    tempRA[SA[0]] = r = 0;
    for(i=1; i<len; i++) {
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    }
    for(i=0; i<len; i++) {
      RA[i] = tempRA[i];
    }
  }
}

void computeLCP() {
  phi[SA[0]] = -1;
  for(int i=1; i<len; i++) {
    phi[SA[i]] = SA[i-1];
  }
  int L = 0;
  for(int i=0; i<len; i++) {
    if(phi[i] == -1) {
      plcp[i] = 0;
      continue;
    }
    while(T[i+L] == T[phi[i]+L]) L++;
    plcp[i] = L;
    L = max(L-1, 0);
  }
  for(int i=0; i<len; i++) {
    lcp[i] = plcp[SA[i]];
  }
}

inline bool diffOwner(int i, int l) {
  if(SA[i] >= l && SA[i-1] < l) return true;
  if(SA[i] < l && SA[i-1] >= l) return true;
  return false;
}

int main() {
  int c = 0;
  while(true) {
    int l;
    memset(T, 0, sizeof T);
    scanf("%s", T);
    len = strlen(T);
    if(len == 0) break;
    if (c > 0) printf("\n");
    c++;
    l = len+1;
    T[len++] = '$';
    scanf("%s", T+len);
    len = strlen(T);
    T[len++] = '#';
    constructSA();
    // for(int i=0; i<len; i++) {
    //   printf("%2d\t%s\n", SA[i], T+SA[i]);
    // }
    computeLCP();
    int ans_len = 0;
    for(int i=1; i<len; i++) {
      if(diffOwner(i, l)) {
        ans_len = max(ans_len, lcp[i]);
      }
    }

    if(ans_len == 0) {
      printf("No common sequence.\n");
    } else {
      char tmp[700];
      memset(tmp, 0, sizeof tmp);
      for(int i=1; i<len; i++) {
        if(lcp[i] == ans_len && diffOwner(i, l)) {
          int s = SA[i], e = SA[i] + lcp[i];
          bool flag = false;
          for(int j=s, k=0; j<e; j++) {
            if (T[j] != tmp[k++]) {
              flag = true;
              break;
            }
          }
          if (flag) {
            for(int j=s, k=0; j<e; j++) {
              printf("%c", T[j]);
              tmp[k++] = T[j];
            }
            printf("\n");
          }
        }
      }
    }
  }
  return 0;
}
