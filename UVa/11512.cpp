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
char T[1024];
int SA[1024], tempSA[1024];
int RA[1024], tempRA[1024];
int c[1024];
int len;
int lcp[1024], plcp[1024];
int phi[1024];

void countSorting(int k) {
  memset(c, 0, sizeof c);
  for(int i=0; i<len; i++) {
    c[i + k < len ? RA[i+k] : 0]++;
  }
  int sum = 0, maxi = max(300, len);
  for(int i=0; i<maxi; i++) {
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
  for(int i=0; i<len; i++) SA[i] = i;
  for(int i=0; i<len; i++) RA[i] = T[i];
  int r;
  for(int k=1; k<len; k<<=1) {
    countSorting(k);
    countSorting(0);
    tempRA[SA[0]] = r = 0;
    for(int i=1; i<len; i++) {
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
    }
    for(int i=0; i<len; i++) {
      RA[i] = tempRA[i];
    }
    if(RA[SA[len-1]] == len - 1) break;
  }
}

void computeLCP() {
  phi[SA[0]] = -1;
  for(int i=1; i<len; i++) {
    phi[SA[i]] = SA[i-1];
  }
  int l = 0;
  for(int i=0; i<len; i++) {
    if(phi[i] == -1) {
      plcp[i] = 0;
      continue;
    }
    while(T[i + l] == T[phi[i] + l]) l++;
    plcp[i] = l;
    l = max(l-1, 0);
  }
  for(int i=0; i<len; i++) {
    lcp[i] = plcp[SA[i]];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    memset(T, 0, sizeof T);
    scanf("%s", T);
    len = strlen(T);
    T[len++] = '$';
    constructSA();
    computeLCP();
    // for(int i=0; i<len; i++) {
    //   cout << SA[i] << " " << lcp[i] << " " << T+SA[i] << endl;
    // }
    int ll = 0;
    for(int i=0; i<len; i++) {
      ll = max(ll, lcp[i]);
    }
    if(ll == 0) {
      printf("No repetitions found!\n");
    } else {
      for(int i=0; i<len; i++) {
        if(lcp[i] == ll) {
          for(int j=0; j<lcp[i]; j++) {
            printf("%c", T[SA[i]+j]);
          }
          int ans = 2;
          for(int k=i+1; k<len; k++) {
            if(lcp[k] >= ll) ans++;
            else break;
          }
          printf(" %d\n", ans);
          break;
        }
      }
    }
  }
  return 0;
}
