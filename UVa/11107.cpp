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
char T[110000];
int SA[110000], tempSA[110000];
int RA[110000], tempRA[110000];
int c[110000];
vi owner;
int len;

int plcp[110000], lcp[110000];
int phi[110000];
int pos[110000];

void countSort(int k) {
  memset(c, 0, sizeof c);
  int maxi = max(300, len);
  for(int i=0; i<len; i++) {
    c[i+k < len ? RA[i+k] : 0]++;
  }
  for(int i=0, sum = 0; i<maxi; i++) {
    int t = c[i]; c[i] = sum; sum+=t;
  }
  for(int i=0; i<len; i++) {
    tempSA[c[SA[i] + k < len ? RA[SA[i]+k] : 0]++] = SA[i];
  }
  for(int i=0; i<len; i++) {
    SA[i] = tempSA[i];
  }
}

void constructSA() {
  int r;
  for(int i=0; i<len; i++) SA[i] = i;
  for(int i=0; i<len; i++) RA[i] = T[i];
  for(int k=1; k<len; k<<=1) {
    countSort(k);
    countSort(0);
    tempRA[SA[0]] = r = 0;
    for(int i=1; i<len; i++) {
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    }
    for(int i=0; i<len; i++) {
      RA[i] = tempRA[i];
    }
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
    while(T[i+l] == T[phi[i]+l]) l++;
    plcp[i] = l;
    l = max(l-1, 0);
  }
  for(int i=0;  i<len; i++) {
    lcp[i] = plcp[SA[i]];
  }
  int last = 0;
  for(int i=0; i<(int)owner.size(); i++) {
    for(int j=last; j<owner[i]; j++) {
      pos[j] = i;
    }
    last = owner[i];
  }
}

char ans[5050][1010];
bitset<1010> bs;
int main() {
  int n;
  int kase = 0;
  while(scanf("%d", &n), n) {
    if(kase) printf("\n");
    kase++;
    memset(T, 0, sizeof T);
    owner.clear();
    len = 0;
    if(n == 1) {
      scanf("%s", T);
      printf("%s\n", T);
      continue;
    }
    for(int i=0; i<n; i++) {
      scanf("%s", T+len);
      int l = strlen(T+len);
      len = len + l;
      T[len++] = '#';
      owner.push_back(len);
    }
    constructSA();
    computeLCP();
    // for(int i=0; i<len; i++) {
    //   printf("%d\t%d\t%d\t%s\n", SA[i], lcp[i], pos[SA[i]], T+SA[i]);
    // }
    int high = 1000, low = 1, count = 0;
    bs.reset();
    while(high >= low) {
      int mid = (high + low) / 2, tmp = 0;
      for(int i=1; i<len; i++) {
        if(min(lcp[i], owner[pos[SA[i]]] - SA[i] - 1) < mid) {
          int cal = bs.count();
          if(cal > n / 2) {
            for(int j=0; j<mid; j++) {
              ans[tmp][j] = T[SA[i-1]+j];
            }
            ans[tmp][mid] = '\0';
            tmp++;
          }
          bs.reset();
        } else {
          bs[pos[SA[i]]] = bs[pos[SA[i-1]]] = 1;
        }
      }
      int cal = bs.count();
      if(cal > n / 2) {
        for(int j=0; j<mid; j++) {
          ans[tmp][j] = T[SA[len-1]+j];
        }
        ans[tmp][mid] = '\0';
        tmp++;
      }
      if(tmp) {
        low = mid + 1;
        count = tmp;
      } else {
        high = mid - 1;
      }
      bs.reset();
    }
    if(count) {
      for(int i=0; i<count; i++) {
        printf("%s\n", ans[i]);
      }
    } else {
      printf("?\n");
    }
    memset(ans, 0, sizeof ans);
  }
  return 0;
}
