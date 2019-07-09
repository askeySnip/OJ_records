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
map<int, int> mp;

void fib() {
  mp[1] = 0;
  mp[2] = 1;
  long long a = 1, b = 2, c = 2, t = 3, l = (ll)((1 << 31)-1);
  while(t < l) {
    mp[t] = c++;
    a = b, b = t, t = a + b;
    // cout << t << endl;
  }
}

int main() {
  int t, n;
  scanf("%d", &t);
  fib();
  int num[110];
  char ans[1024];
  char cip[120];
  while(t--) {
    for(int i=0; i<1024; i++) ans[i] = ' ';
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &num[i]);
    getchar();
    gets(cip);
    int len = strlen(cip);
    int c = 0, m = 0;
    REP(i, 0, len) {
      if(cip[i] >= 'A' && cip[i] <= 'Z') {
        m = max(m, mp[num[c]]);
        ans[mp[num[c]]] = cip[i];
        c++;
        if(c == n) break;
      }
    }
    ans[m+1] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}
